//
// Created by alexmal on 07.12.19.
//
#pragma once

#ifndef TASK_2_0_OBJECTS_H
#define TASK_2_0_OBJECTS_H

#include <iostream>
#include <string>
#include <any>
#include <cmath>
#include <memory>

#include "options.h"


class TFunction {
public:
    virtual double GetDeriv(double x) const = 0;

    virtual double operator()(double x) const = 0;

    virtual std::string ToString() const = 0;

    virtual ~TFunction() = default;
};

class TIdent : public TFunction {
public:
    explicit TIdent(const TOptions &opt) {
        if (!opt.options.empty()) {
            std::cout << "To many arguments for TIdent" << std::endl;
        }

    }

    explicit TIdent() = default;

    double GetDeriv(double x) const override {
        return 1;
    }

    double operator()(double x) const override {
        return x;
    }

    std::string ToString() const override {
        return "x";
    }
};

class TConst : public TFunction {
    double _value;
public:
    explicit TConst(const TOptions &opt) : _value(opt.get<double, 0>()) {}

    explicit TConst(double value = 0) : _value(value) {}

    double GetDeriv(double x) const override {
        return 0;
    }

    double operator()(double x) const override {
        return _value;
    }

    std::string ToString() const override {
        return std::to_string(_value);
    }
};

class TPower : public TFunction {
    double _power;
public:
    explicit TPower(const TOptions &opt) : _power(opt.get<double, 0>()) {}

    explicit TPower(double power = 1) : _power(power) {}

    double GetDeriv(double x) const override {
        return _power * (std::pow(x, _power - 1));
    }

    double operator()(double x) const override {
        return std::pow(x, _power);
    }

    std::string ToString() const override {
        return "x^" + std::to_string(_power);
    }
};

class TExp : public TFunction {
public:

    explicit TExp(const TOptions &opt) {
        if (!opt.options.empty()) {
            std::cout << "To many arguments for TIdent" << std::endl;
        }

    }

    explicit TExp() = default;

    double GetDeriv(double x) const override {
        return std::exp(x);
    }

    double operator()(double x) const override {
        return std::exp(x);
    }

    std::string ToString() const override {
        return "exp(x)";
    }
};

class TPolynomial : public TFunction {
    std::vector<double> _coefficients;
public:
    explicit TPolynomial() {
        _coefficients.push_back(0);
    }

    explicit TPolynomial(const TOptions &opt) : _coefficients(opt.get<std::vector<double>, 0>()) {
        if (opt.get<std::vector<double>, 0>().empty()) {
            _coefficients.push_back(0);
        }
    }

    explicit TPolynomial(const std::vector<double> &coefficients) : _coefficients(coefficients) {
        if (coefficients.empty()) {
            _coefficients.push_back(0);
        }
    }

    double GetDeriv(double x) const override {
        double result = 0;
        for (size_t itr = 1; itr < _coefficients.size(); ++itr) {
            result += _coefficients[itr] * (itr) * std::pow(x, itr - 1);
        }
        return result;
    }

    double operator()(double x) const override {
        double result = 0;
        for (size_t itr = 0; itr < _coefficients.size(); ++itr) {
            result += _coefficients[itr] * std::pow(x, itr);
        }
        return result;
    }

    std::string ToString() const override {
        std::string s = std::to_string(_coefficients[0]);

        for (size_t itr = 1; itr < _coefficients.size(); ++itr) {
            s += " + " + std::to_string(_coefficients[itr]) + "*x^" + std::to_string(itr);
        }
        return s;
    }
};

class TComplexFunc : public TFunction {
    std::shared_ptr<TFunction> _f;
    std::shared_ptr<TFunction> _g;
    std::string _op;
public:
    TComplexFunc(std::shared_ptr<TFunction> f, std::shared_ptr<TFunction> g, const std::string &op) {
        _f = std::move(f);
        _g = std::move(g);
        _op = op;
    }

    double operator()(double x) const override {
        if (_op == "plus") {
            return (*_f)(x) + (*_g)(x);
        } else if (_op == "minus") {
            return (*_f)(x) - (*_g)(x);
        } else if (_op == "multiply") {
            return (*_f)(x) * (*_g)(x);
        } else if (_op == "division") {
            return (*_f)(x) / (*_g)(x);
        } else {
            throw std::logic_error("TComplexFunc: Unknown operation");

        }
    }

    double GetDeriv(double x) const override {
        if (_op == "plus") {
            return (*_f).GetDeriv(x) + (*_g).GetDeriv(x);
        } else if (_op == "minus") {
            return (*_f).GetDeriv(x) - (*_g).GetDeriv(x);
        } else if (_op == "multiply") {
            return (*_f).GetDeriv(x) * (*_g)(x) + (*_f)(x) * (*_g).GetDeriv(x);
        } else if (_op == "division") {
            double g_x = (*_g)(x);
            if (g_x != 0) {
                return ((*_f).GetDeriv(x) * g_x - (*_g).GetDeriv(x) * (*_f)(x)) / (std::pow(g_x, 2));
            } else {
                throw std::logic_error("TComplexFunc: Divide by zero");
            }
        } else {
            throw std::logic_error("TComplexFunc: Unknown operation");

        }
    }


    std::string ToString() const override {
        std::string operation;
        if (_op == "plus") {
            operation = " + ";
        } else if (_op == "minus") {
            operation = " - ";
        } else if (_op == "multiply") {
            operation = " * ";
        } else if (_op == "division") {
            operation = " / ";
        } else {
            throw std::logic_error("TComplexFunc: Unknown operation");

        }
        return "(" + _f->ToString() + ")" + operation + "(" + _g->ToString() + ")";
    }
};

inline std::shared_ptr<TFunction> operator+(const std::shared_ptr<TFunction> f, const std::shared_ptr<TFunction> g) {
    return std::make_unique<TComplexFunc>(f, g, "plus");
}

inline std::shared_ptr<TFunction> operator-(const std::shared_ptr<TFunction> &f, const std::shared_ptr<TFunction> &g) {
    return std::make_unique<TComplexFunc>(f, g, "minus");
}

inline std::shared_ptr<TFunction> operator*(const std::shared_ptr<TFunction> &f, const std::shared_ptr<TFunction> &g) {
    return std::make_unique<TComplexFunc>(f, g, "multiply");
}

inline std::shared_ptr<TFunction> operator/(const std::shared_ptr<TFunction> &f, const std::shared_ptr<TFunction> &g) {
    return std::make_unique<TComplexFunc>(f, g, "division");
}


#endif //TASK_2_OBJECTS_H

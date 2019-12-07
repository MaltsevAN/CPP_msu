//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_OBJECTS_H
#define TASK_2_0_OBJECTS_H

#include <iostream>
#include <string>
#include <any>

class TFunction {
public:
//    virtual double GetDeriv(double value) const = 0;
//    virtual double operator()(double value) const = 0;
//    virtual std::string ToString() const = 0;

    virtual void Do() const = 0;

};

class TCustomObject : public TFunction {
public:
//    Ident(const std::any& value) {}

    void Do() const override {
        std::cout << "TCustomObject DO" << std::endl;

    }
};

class TSuperObject : public TFunction {
public:
    void Do() const override {
        std::cout << "TSuperObject DO" << std::endl;

    }
};

#endif //TASK_2_OBJECTS_H

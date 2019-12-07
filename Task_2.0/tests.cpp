//
// Created by alexmal on 07.12.19.
//
#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

#include "gtest/gtest.h"

#include "include/factory.h"
#include "include/gradient_descent.h"

TEST (Factory, GetAvailableObjects) {
// arrange
    TFactory factory;
    auto objects = factory.GetAvailableObjects();
//act
// assert
    ASSERT_NE (nullptr, &objects) << "ERROR GetAvailableObjects";
}

TEST (Factory, CreateObject_ident) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("ident");
//act
// assert
    ASSERT_NE (nullptr, f) << "ERROR CREATE obj ident";
}

TEST (Factory, CreateObject_const) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const");
//act
// assert
    ASSERT_NE (nullptr, f) << "ERROR CREATE obj const";
}

TEST (Factory, CreateObject_power) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 2.0);
//act
// assert
    ASSERT_NE (nullptr, f) << "ERROR CREATE obj power";
}

TEST (Factory, CreateObject_exp) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("exp");
//act
// assert
    ASSERT_NE (nullptr, f) << "ERROR CREATE obj exp";
}

TEST (Factory, CreateObject_polynomial) {
// arrange
    TFactory factory;
    std::vector<double> v = {7, 5, 16, 8};
    auto f = factory.CreateObject("polynomial", v);
//act
// assert
    ASSERT_NE (nullptr, f) << "ERROR CREATE obj polynomial";
}

TEST (Exceptions, logic_error_left_op) {
    // arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 1.2);
    //act

    // assert
    ASSERT_THROW (f + "adf", std::logic_error) << "ERROR logic_error_left_op";
}


TEST (Exceptions, logic_error_right_op) {
    // arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 1.2);
    //act

    // assert
    ASSERT_THROW (12 + f, std::logic_error) << "ERROR logic_error_right_op";
}

TEST (Exceptions, logic_error_divide_by_zero) {
    // arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 1.2);
    auto g = factory.CreateObject("ident");

    auto t = f / g;
    //act

    // assert
    ASSERT_THROW (t->GetDeriv(0.0), std::logic_error) << "ERROR logic_error_divide_by_zero";
}

TEST (GetDerive, GetDerive_ident) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("ident");
//act
// assert
    ASSERT_EQ (1, f->GetDeriv(0.0)) << "ERROR GetDerive_ident";
}

TEST (GetDerive, GetDerive_const) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const");
//act
// assert
    ASSERT_EQ (0, f->GetDeriv(0.0)) << "ERROR GetDerive_const";

}
//
TEST (GetDerive, GetDerive_power) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 2.0);
//act
// assert
    ASSERT_EQ (6, f->GetDeriv(3.0)) << "ERROR GetDerive_power";

}
//
TEST (GetDerive, GetDerive_exp) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("exp");
//act
// assert
    ASSERT_EQ (std::exp(2.0), f->GetDeriv(2.0)) << "ERROR GetDerive_exp";

}
//
TEST (GetDerive, GetDerive_polynomial) {
// arrange
    TFactory factory;
    std::vector<double> v = {7, 5, 16, -3};
    auto f = factory.CreateObject("polynomial", v);
//act
// assert
    double x = 2.0;
    ASSERT_EQ (5 + 2 * 16 * x - 3 * 3 * std::pow(x, 2), f->GetDeriv(x)) << "ERROR GetDerive_polynomial";

}

TEST (CheckValue, CheckValue_ident) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("ident");
//act
// assert
    ASSERT_EQ (2.0, (*f)(2.0)) << "ERROR CheckValue_ident";
}

TEST (CheckValue, CheckValue_const) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const");
//act
// assert
    ASSERT_EQ (0, (*f)(2.0)) << "ERROR CheckValue_const";

}
//
TEST (CheckValue, CheckValue_power) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 2.0);
//act
// assert
    ASSERT_EQ (4.0, (*f)(2.0)) << "ERROR CheckValue_power";

}
//
TEST (CheckValue, CheckValue_exp) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("exp");
//act
// assert
    ASSERT_EQ (std::exp(2.0), (*f)(2.0)) << "ERROR CheckValue_exp";

}
//
TEST (CheckValue, CheckValue_polynomial) {
// arrange
    TFactory factory;
    std::vector<double> v = {7, 5, 16, -3};
    auto f = factory.CreateObject("polynomial", v);
//act
// assert
    double x = 2.0;
    ASSERT_EQ (7 + 5 * x + 16 * std::pow(x, 2) - 3 * std::pow(x, 3), (*f)(x)) << "ERROR CheckValue_polynomial";

}

TEST (ToString, ToString_ident) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("ident");
//act
// assert
    ASSERT_EQ ("x", f->ToString()) << "ERROR ToString_ident";
}

TEST (ToString, ToString_const) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const", 4.0);
//act
// assert
    ASSERT_EQ ("4.000000", f->ToString()) << "ERROR ToString_const";

}
//
TEST (ToString, ToString_power) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("power", 2.0);
//act
// assert
    ASSERT_EQ ("x^2.000000", f->ToString()) << "ERROR ToString_power";

}
//
TEST (ToString, ToString_exp) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("exp");
//act
// assert
    ASSERT_EQ ("exp(x)", f->ToString()) << "ERROR ToString_exp";

}
//
TEST (ToString, ToString_polynomial) {
// arrange
    TFactory factory;
    std::vector<double> v = {7, 5, 16, -3};
    auto f = factory.CreateObject("polynomial", v);
//act
// assert
    ASSERT_EQ ("7.000000 + 5.000000*x^1 + 16.000000*x^2 + -3.000000*x^3", f->ToString()) << "ERROR ToString_polynomial";

}

TEST (ComplecFunct, ComplecFunct_factory) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const", 4.0);
    auto g = factory.CreateObject("exp");
//act
// assert
    ASSERT_NE (nullptr, f + g) << "ERROR CREATE obj ComplecFunct";
}

TEST (ComplecFunct, ComplecFunct_GetDeriv) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const", 4.0);
    auto g = factory.CreateObject("exp");
    auto c = f + g;
//act
// assert
    ASSERT_EQ (std::exp(2.0), c->GetDeriv(2.0)) << "ERROR ComplecFunct_GetDeriv";
}

TEST (ComplecFunct, ComplecFunct_ToString) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const", 4.0);
    auto g = factory.CreateObject("exp");
    auto c = f + g;
//act
// assert
    ASSERT_EQ ("(4.000000) + (exp(x))", c->ToString()) << "ERROR ComplecFunct_ToString";
}

TEST (ComplecFunct, ComplecFunct_Value) {
// arrange
    TFactory factory;
    auto f = factory.CreateObject("const", 4.0);
    auto g = factory.CreateObject("exp");
    auto c = f + g;
//act
// assert
    ASSERT_EQ (4.000000 + (exp(2.0)), (*c)(2.0)) << "ERROR ComplecFunct_ToString";
}


TEST (GradientDescent, GradientDescent_1) {
// arrange
    TFactory factory;
    std::vector<double> v = {-2, 1, 1};
    auto f = factory.CreateObject("polynomial", v);
    auto res = std::round(gradient_descent(f, 20, 0.1, 0.00001, 0, false));
//act
// assert
    ASSERT_EQ (true, res == 1 || res == -2) << "ERROR GradientDescent_1";

}

TEST (GradientDescent, GradientDescent_2) {
// arrange
    TFactory factory;
    std::vector<double> v = {2, 1};
    auto f = factory.CreateObject("polynomial", v);
    auto res = std::round(gradient_descent(f, 20, 0.1, 0.00001, 0, false));
//act
// assert
    ASSERT_EQ (true, res == -2) << "ERROR GradientDescent_2";

}

TEST (GradientDescent, GradientDescent_3) {
// arrange
    TFactory factory;
    std::vector<double> v = {-2, 1, 1, 6};
    auto f = factory.CreateObject("polynomial", v);
    auto g = factory.CreateObject("exp");
    auto res = gradient_descent(f / g, 200, 0.01, 0.0000001, 0, false);
    double precision = 0.0002;
    double answer = 0.569241;
//act
// assert
    ASSERT_EQ (true, std::abs(res - answer) < precision) << "ERROR GradientDescent_3";

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    srand(millis % 40960);
    return RUN_ALL_TESTS();;
}

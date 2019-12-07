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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    srand(millis % 40960);
    return RUN_ALL_TESTS();;
}

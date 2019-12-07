//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_EXCEPTIONS_H
#define TASK_2_0_EXCEPTIONS_H

#include "objects.h"

using TFunctionShPtr = std::shared_ptr<TFunction>;

template<class T>
TFunctionShPtr operator+(const T lhs, const TFunctionShPtr &rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionShPtr operator-(const T lhs, const TFunctionShPtr &rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionShPtr operator*(const T lhs, const TFunctionShPtr &rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionShPtr operator/(const T lhs, const TFunctionShPtr &rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionShPtr operator+(const TFunctionShPtr &lhs, const T rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionShPtr operator-(const TFunctionShPtr &lhs, const T rhs) {
    throw std::logic_error("Invalid type of operand");
}

template<class T>
TFunctionShPtr operator*(const TFunctionShPtr &lhs, const T rhs) {
    throw std::logic_error("Invalid type of operand");

}

template<class T>
TFunctionShPtr operator/(const TFunctionShPtr &lhs, const T rhs) {
    throw std::logic_error("Invalid type of operand");
}

#endif //TASK_2_0_EXCEPTIONS_H

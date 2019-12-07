//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_GRADIENT_DESCENT_H
#define TASK_2_0_GRADIENT_DESCENT_H

#include "objects.h"

double
gradient_descent(const std::shared_ptr<TFunction> f, size_t iterations, double alpha, double precision, double x = 0,
                 bool out = false) {
    auto f_2 = f * f;
    double cur_value;
    for (size_t itr = 0; itr < iterations; ++itr) {
        cur_value = (*f_2)(x);
        if (cur_value < precision) {
            break;
        }
        if (out) {
            std::cout << cur_value;
        }
        x = x - alpha * f_2->GetDeriv(x);
    }
    if (out) {
        std::cout << std::endl;
    }
    return x;
};


#endif //TASK_2_0_GRADIENT_DESCENT_H

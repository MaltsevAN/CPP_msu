#include <iostream>
#include "include/factory.h"
#include <vector>

int main() {

    TFactory factory;

    auto objects = factory.GetAvailableObjects();

    for (const auto &obj: objects) {
        std::cout << obj << std::endl;
    }

    auto f = factory.CreateObject("ident");
    std::cout << f->ToString() << std::endl;

    f = factory.CreateObject("const", 4.0);
    std::cout << f->ToString() << std::endl;

    double x = 2;
    f = factory.CreateObject("power", x);
    std::cout << f->ToString() << std::endl;
    std::cout << f->GetDeriv(x) << std::endl;


    f = factory.CreateObject("exp");
    std::cout << f->ToString() << std::endl;
//
    std::vector<double> v = {7, 5, 16, 8};
    for (int n : v) {
        std::cout << n;
    }
    std::cout << std::endl;
    f = factory.CreateObject("polynomial", v);
    std::cout << f->ToString() << std::endl;
//
    f = factory.CreateObject("ident", 2);
    std::cout << f->ToString() << std::endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
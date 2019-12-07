#include <iostream>
#include "include/factory.h"

int main() {

    TFactory factory;

    auto objects = factory.GetAvailableObjects();

    for (const auto &obj: objects) {
        std::cout << obj << std::endl;
    }

    for (const auto &objName : {"super object", "custom object"}) {
        factory.CreateObject(objName)->Do();
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
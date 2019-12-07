//
// Created by alexmal on 07.12.19.
//

#include "../include/factory.h"


TFactory::TFactory() : Impl(std::make_unique<TImpl>()) {}
//TFactory::~TFactory() {}

std::vector<std::string> TFactory::GetAvailableObjects() const {
    return Impl->GetAvailableObjects();
}

std::shared_ptr<TFunction> TFactory::CreateObject(const std::string &name) const {
    return Impl->CreteObject(name);
}

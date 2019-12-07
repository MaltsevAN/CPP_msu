//
// Created by alexmal on 07.12.19.
//

#include "../include/TImpl.h"

TImpl::TImpl() {
    RegisterAll();
}

void TImpl::RegisterAll() {
    RegisterCreator<TCustomObject>("custom object");
    RegisterCreator<TSuperObject>("super object");
}

std::vector<std::string> TImpl::GetAvailableObjects() const {
    std::vector<std::string> result;
    for (const auto &creatorPair : RegisteredCreators) {
        result.push_back(creatorPair.first);
    }
    return result;
}

std::unique_ptr<TFunction> TImpl::CreteObject(const std::string &name) const {
    auto creator = RegisteredCreators.find(name);
    if (creator == RegisteredCreators.end()) {
        return nullptr;
    }

    return creator->second->Create();
}
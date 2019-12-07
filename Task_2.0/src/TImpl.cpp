//
// Created by alexmal on 07.12.19.
//

#include "../include/TImpl.h"

TImpl::TImpl() {
    RegisterAll();
}

void TImpl::RegisterAll() {
    RegisterCreator<TIdent>("ident");
    RegisterCreator<TConst>("const");
    RegisterCreator<TPower>("power");
    RegisterCreator<TExp>("exp");
    RegisterCreator<TPolynomial>("polynomial");
}

std::vector<std::string> TImpl::GetAvailableObjects() const {
    std::vector<std::string> result;
    for (const auto &creatorPair : RegisteredCreators) {
        result.push_back(creatorPair.first);
    }
    return result;
}
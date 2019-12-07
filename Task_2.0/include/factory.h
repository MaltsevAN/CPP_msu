//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_FUNCION_FUCTORY_H
#define TASK_2_0_FUNCION_FUCTORY_H

#include <vector>
#include <memory>
#include <map>

#include "objects.h"
#include "options.h"
#include "TImpl.h"

class TFactory {
    std::unique_ptr<const TImpl> Impl;

public:
    TFactory();

    ~TFactory() = default;

    std::vector<std::string> GetAvailableObjects() const;

    std::unique_ptr<TFunction> CreateObject(const std::string &name) const;

    template<class... Args>
    std::unique_ptr<TFunction> CreateObject(const std::string &name, Args &&... args) const {
        return Impl->CreteObject(name, args...);
    }

};

#endif //TASK_2_FUNCION_FUCTORY_H

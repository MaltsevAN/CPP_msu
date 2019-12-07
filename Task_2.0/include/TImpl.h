//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_TIMPL_H
#define TASK_2_0_TIMPL_H

#include <vector>
#include <memory>
#include <map>

#include "objects.h"
#include "options.h"
#include "ICreator.h"

class TImpl {


    using TCreatorPtr = std::shared_ptr<ICreator>;
    using TRegisteredCreators = std::map<std::string, TCreatorPtr>;

    TRegisteredCreators RegisteredCreators;

public:

    TImpl();

    void RegisterAll();

    std::vector<std::string> GetAvailableObjects() const;

    std::unique_ptr<TFunction> CreteObject(const std::string &name) const;

    template<class TCurrentObject>
    class TCreator : public ICreator {
        std::unique_ptr<TFunction> Create(const TOptions &opts) const override {
            return std::make_unique<TCurrentObject>();
        }

        std::unique_ptr<TFunction> Create() const override {
            return std::make_unique<TCurrentObject>();
        }
    };


    template<typename T>
    void RegisterCreator(const std::string &name) {
        RegisteredCreators[name] = std::make_shared<TCreator<T>>();
    }

    template<class... Args>
    std::unique_ptr<TFunction> CreteObject(const std::string &name, Args &&... args) const {
        auto creator = RegisteredCreators.find(name);
        if (creator == RegisteredCreators.end()) {
            return nullptr;
        }

        TOptions opts{args...};
        std::cout << "CREate" << std::endl;
        return creator->second->Create(opts);
    }

};


#endif //TASK_2_0_TIMPL_H

//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_ICREATOR_H
#define TASK_2_0_ICREATOR_H

#include <memory>

#include "objects.h"
#include "options.h"

class ICreator {
public:
    virtual ~ICreator() = default;

    virtual std::shared_ptr<TFunction> Create(const TOptions &opts) const = 0;

    virtual std::shared_ptr<TFunction> Create() const = 0;
};


#endif //TASK_2_0_ICREATOR_H

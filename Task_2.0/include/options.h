//
// Created by alexmal on 07.12.19.
//

#ifndef TASK_2_0_OPTIONS_H
#define TASK_2_0_OPTIONS_H


#include <vector>
#include <any>
#include <stdexcept>


struct TOptions {
    TOptions(std::initializer_list<std::any> il) {
        if (il.size() == 0) {
            options = {};
        } else {
            options.insert(options.begin(), il.begin(), il.end());
        }
    }


    template<class T, unsigned I>
    T get() const {
        if (I >= options.size())
            throw std::out_of_range("No options at required index");

        try {
            return std::any_cast<T>(options[I]);
        } catch (const std::bad_any_cast &) {
            throw std::domain_error("Option at required index has different type");
        }
    };

    std::any get(size_t i) const {
        return options[i];

    }

    bool is_empty() {
        return options.empty();
    }
    std::vector<std::any> options;
};


#endif //TASK_2_0_OPTIONS_H

#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"
#include <string>

class Cinnamon : public Ingredient {
public:
    Cinnamon(size_t units)
        : Ingredient { 5, units }
    {
        name = "Cinnamon";
    }

    virtual std::string get_name() { return this->name; }
};

#endif // SUB_INGREDIENTS_H
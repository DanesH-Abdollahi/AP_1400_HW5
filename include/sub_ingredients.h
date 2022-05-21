#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"
#include <string>

#define DEFCLASS(class_name, per_unit)                  \
                                                        \
    class class_name : public Ingredient {              \
    public:                                             \
        class_name(size_t units)                        \
            : Ingredient { per_unit, units }            \
        {                                               \
            name = #class_name;                         \
        }                                               \
        virtual std::string get_name() { return name; } \
    };

DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);

#endif // SUB_INGREDIENTS_H
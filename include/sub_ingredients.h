#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"
#include <string>

#define DEFCLASS(Class_Name, Per_Unit_Price)            \
                                                        \
    class Class_Name : public Ingredient {              \
    public:                                             \
        Class_Name(size_t units)                        \
            : Ingredient { Per_Unit_Price, units }      \
        {                                               \
            name = #Class_Name;                         \
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
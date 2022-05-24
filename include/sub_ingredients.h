#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"
#include <string>

// Define All Sub_Ingredients Classes With Macro

#define DEFCLASS(Class_Name, Price_Unit)                \
                                                        \
    class Class_Name : public Ingredient {              \
    public:                                             \
        Class_Name(size_t units)                        \
            : Ingredient { Price_Unit, units }          \
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
#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include "ftxui/dom/flexbox_config.hpp"
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/box.hpp"
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/terminal.hpp"

#include "ingredient.h"
#include "sub_ingredients.h"
#include <ftxui/dom/elements.hpp>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

class EspressoBased {
public:
    virtual std::string get_name() const = 0; // Pure virtual function
    virtual double price() const = 0; // Pure virtual function

    void brew();
    std::vector<Ingredient*>& get_ingredients() { return ingredients; };

    virtual ~EspressoBased(); // Destructor // Virtual ?!

protected:
    EspressoBased() = default; // Default constructor
    EspressoBased(const EspressoBased& esp); // Copy constructor
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;
};

#endif // ESPRESSO_BASED_H
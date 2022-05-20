#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include "ingredient.h"
#include <iostream>
#include <string>
#include <vector>

class EspressoBased {
public:
    virtual std::string get_name() const = 0; // Pure virtual function
    virtual double price() const = 0; // Pure virtual function

    void brew();
    std::vector<Ingredient*>& get_ingredients() { return ingredients; };

    virtual ~EspressoBased(); // Destructor // Virtual ?!

protected:
    EspressoBased(); // Default constructor
    EspressoBased(const EspressoBased& esp); // Copy constructor
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;
};

#endif // ESPRESSO_BASED_H
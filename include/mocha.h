#ifndef MOCHA_H
#define MOCHA_H

#include "espresso_based.h"
#include "ingredient.h"
#include "sub_ingredients.h"
#include <iostream>
#include <vector>

class Mocha : public EspressoBased {
public:
    Mocha(); // Default constructor
    Mocha(const Mocha& moc); // Copy constructor
    virtual ~Mocha(); // Destructor
    void operator=(const Mocha& moc);

    virtual std::string get_name() const override { return name; }
    virtual double price() const override;

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items() { return side_items; }

private:
    std::vector<Ingredient*> side_items;
};

#endif // MOCHA_H
#ifndef CAPPUCCINO
#define CAPPUCCINO

#include "espresso_based.h"
#include "ingredient.h"
#include "sub_ingredients.h"
#include <iostream>
#include <vector>

class Cappuccino : public EspressoBased {
public:
    Cappuccino(); // Default constructor
    Cappuccino(const Cappuccino& cap); // Copy constructor
    ~Cappuccino(); // Destructor
    void operator=(const Cappuccino& cap);

    virtual std::string get_name() const override { return name; }
    virtual double price() const override;

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items() { return side_items; }

private:
    std::vector<Ingredient*> side_items;
};
#endif // CAPPUCCINO
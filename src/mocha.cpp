#include "mocha.h"

Mocha::~Mocha() // Destructor
{
    for (const auto& i : side_items)
        delete i;

    side_items.clear();
}
//----------------------------------------------------------------------------------
Mocha::Mocha() // Default constructor
    : EspressoBased()
    , side_items {}
{
    // Add the Main Mocha Sub_ingredients
    ingredients.push_back(new Espresso { 2 });
    ingredients.push_back(new Chocolate { 1 });
    ingredients.push_back(new Milk { 2 });
    ingredients.push_back(new MilkFoam { 1 });

    name = "Mocha";
}
//----------------------------------------------------------------------------------
Mocha::Mocha(const Mocha& moc) // Copy constructor
    : EspressoBased { moc } // Copy the base class

{
    for (const auto& item : moc.side_items) {
        std::string Temp_Name { item->get_name() };
        size_t Temp_Units { item->get_units() };

        // Add the New_Side_items to the Side_items vector
        if (Temp_Name == "Cinnamon")
            side_items.push_back(new Cinnamon { Temp_Units });

        else if (Temp_Name == "Chocolate")
            side_items.push_back(new Chocolate { Temp_Units });

        else if (Temp_Name == "Sugar")
            side_items.push_back(new Sugar { Temp_Units });

        else if (Temp_Name == "Cookie")
            side_items.push_back(new Cookie { Temp_Units });

        else if (Temp_Name == "Espresso")
            side_items.push_back(new Espresso { Temp_Units });

        else if (Temp_Name == "Milk")
            side_items.push_back(new Milk { Temp_Units });

        else if (Temp_Name == "MilkFoam")
            side_items.push_back(new MilkFoam { Temp_Units });

        else if (Temp_Name == "Water")
            side_items.push_back(new Water { Temp_Units });
    }
}
//----------------------------------------------------------------------------------
void Mocha::operator=(const Mocha& moc) // Copy Version of Operator =
{
    if (this != &moc) { // Check if the object is not the same
        for (const auto& i : side_items)
            delete i;
        side_items.clear(); // Delete the current side_items

        for (const auto& item : moc.side_items) {
            std::string Temp_Name { item->get_name() };
            size_t Temp_Units { item->get_units() };

            // Add the New_Side_items to the Side_items vector
            if (Temp_Name == "Cinnamon")
                side_items.push_back(new Cinnamon { Temp_Units });

            else if (Temp_Name == "Chocolate")
                side_items.push_back(new Chocolate { Temp_Units });

            else if (Temp_Name == "Sugar")
                side_items.push_back(new Sugar { Temp_Units });

            else if (Temp_Name == "Cookie")
                side_items.push_back(new Cookie { Temp_Units });

            else if (Temp_Name == "Espresso")
                side_items.push_back(new Espresso { Temp_Units });

            else if (Temp_Name == "Milk")
                side_items.push_back(new Milk { Temp_Units });

            else if (Temp_Name == "MilkFoam")
                side_items.push_back(new MilkFoam { Temp_Units });

            else if (Temp_Name == "Water")
                side_items.push_back(new Water { Temp_Units });
        }
    }
}

//----------------------------------------------------------------------------------
void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}
//----------------------------------------------------------------------------------
double Mocha::price() const
{
    double Totall_Price {};
    for (const auto& integ : ingredients)
        Totall_Price += integ->price();

    for (const auto& i : side_items)
        Totall_Price += i->price();

    return Totall_Price;
}
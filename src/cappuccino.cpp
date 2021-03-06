#include "cappuccino.h"
Cappuccino::~Cappuccino() // Destructor
{
    for (const auto& i : side_items)
        delete i;

    side_items.clear(); // Clear the Side_items vector
}
//----------------------------------------------------------------------------------
Cappuccino::Cappuccino() // Default constructor
    : EspressoBased()
    , side_items {}
{
    // Add the Main Cappucchino Sub_ingredients
    ingredients.push_back(new Espresso { 2 });
    ingredients.push_back(new Milk { 2 });
    ingredients.push_back(new MilkFoam { 1 });

    name = "Cappuccino";
}
//----------------------------------------------------------------------------------
Cappuccino::Cappuccino(const Cappuccino& cap) // Copy constructor
    : EspressoBased { cap } // Copy the base class

{
    for (const auto& item : cap.side_items) {
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
void Cappuccino::operator=(const Cappuccino& cap) // Copy Version Of Operator =
{
    if (this != &cap) { // Check if the object is not the same
        for (const auto& i : side_items)
            delete i; // Delete the current side_items
        side_items.clear();

        for (const auto& item : cap.side_items) {
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
void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}
//----------------------------------------------------------------------------------
double Cappuccino::price() const
{
    double Totall_Price {};
    for (const auto& integ : ingredients)
        Totall_Price += integ->price();

    for (const auto& i : side_items)
        Totall_Price += i->price();

    return Totall_Price;
}
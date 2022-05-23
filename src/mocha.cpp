#include "mocha.h"

Mocha::~Mocha()
{
    // std::cout << "haminjaaa" << std::endl;
    for (const auto& i : side_items)
        delete i;

    side_items.clear();
}
//----------------------------------------------------------------------------------
Mocha::Mocha()
    : EspressoBased()
{
    // for (auto& integ : { new Espresso { 2 }, new Milk { 2 }, new MilkFoam { 1 } })

    ingredients.push_back(new Espresso { 2 });
    ingredients.push_back(new Chocolate { 1 });
    ingredients.push_back(new Milk { 2 });
    ingredients.push_back(new MilkFoam { 1 });

    // for (size_t i; i < side_items.size(); i++)
    //     side_items[i] = nullptr;

    name
        = "Mocha";
}
//----------------------------------------------------------------------------------
Mocha::Mocha(const Mocha& moc)
    : EspressoBased { moc }

{

    side_items.clear();

    for (const auto& item : moc.side_items) {
        std::string Temp_Name { item->get_name() };
        size_t Temp_Units { item->get_units() };
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
void Mocha::operator=(const Mocha& moc) // Copy Version
{
    if (this != &moc) {
        for (const auto& i : side_items)
            delete i;
        side_items.clear();

        // EspressoBased::operator=(cap);

        for (const auto& item : moc.side_items) {
            std::string Temp_Name { item->get_name() };
            size_t Temp_Units { item->get_units() };
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
//----------------------------------------------------------------------------------
#include "espresso_based.h"

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
}
//----------------------------------------------------------------------------------
EspressoBased::EspressoBased()
{
    // for (size_t i; i < ingredients.size(); i++)
    //     ingredients[i] = nullptr;
}
//----------------------------------------------------------------------------------
EspressoBased::EspressoBased(const EspressoBased& esp)
    : name { esp.name }
{
    ingredients.clear();
    for (const auto& item : esp.ingredients) {
        std::string Temp_Name { item->get_name() };
        size_t Temp_Units { item->get_units() };
        if (Temp_Name == "Cinnamon")
            ingredients.push_back(new Cinnamon { Temp_Units });

        else if (Temp_Name == "Chocolate")
            ingredients.push_back(new Chocolate { Temp_Units });

        else if (Temp_Name == "Sugar")
            ingredients.push_back(new Sugar { Temp_Units });

        else if (Temp_Name == "Cookie")
            ingredients.push_back(new Cookie { Temp_Units });

        else if (Temp_Name == "Espresso")
            ingredients.push_back(new Espresso { Temp_Units });

        else if (Temp_Name == "Milk")
            ingredients.push_back(new Milk { Temp_Units });

        else if (Temp_Name == "MilkFoam")
            ingredients.push_back(new MilkFoam { Temp_Units });

        else if (Temp_Name == "Water")
            ingredients.push_back(new Water { Temp_Units });
    }
}
//----------------------------------------------------------------------------------
void EspressoBased::operator=(const EspressoBased& esp)
{
    if (this != &esp) {
        name = esp.name;

        for (const auto& i : ingredients)
            delete i;
        ingredients.clear();

        for (const auto& item : esp.ingredients) {
            std::string Temp_Name { item->get_name() };
            size_t Temp_Units { item->get_units() };
            if (Temp_Name == "Cinnamon")
                ingredients.push_back(new Cinnamon { Temp_Units });

            else if (Temp_Name == "Chocolate")
                ingredients.push_back(new Chocolate { Temp_Units });

            else if (Temp_Name == "Sugar")
                ingredients.push_back(new Sugar { Temp_Units });

            else if (Temp_Name == "Cookie")
                ingredients.push_back(new Cookie { Temp_Units });

            else if (Temp_Name == "Espresso")
                ingredients.push_back(new Espresso { Temp_Units });

            else if (Temp_Name == "Milk")
                ingredients.push_back(new Milk { Temp_Units });

            else if (Temp_Name == "MilkFoam")
                ingredients.push_back(new MilkFoam { Temp_Units });

            else if (Temp_Name == "Water")
                ingredients.push_back(new Water { Temp_Units });
        }
    }
}

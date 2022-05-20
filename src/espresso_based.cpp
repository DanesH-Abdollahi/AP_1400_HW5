#include "espresso_based.h"

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients) {
        delete i;
        // std::cout << "ESP" << std::endl;
    }

    ingredients.clear();
}
//----------------------------------------------------------------------------------
EspressoBased::EspressoBased()
{
    for (size_t i; i < ingredients.size(); i++)
        ingredients[i] = nullptr;
}
//----------------------------------------------------------------------------------
EspressoBased::EspressoBased(const EspressoBased& esp)
    : ingredients { esp.ingredients }
    , name { esp.name }
{
}
//----------------------------------------------------------------------------------
void EspressoBased::operator=(const EspressoBased& esp)
{
    this->name = esp.name;
    this->ingredients.clear();
    this->ingredients = esp.ingredients;
}

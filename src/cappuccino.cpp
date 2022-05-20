#include "cappuccino.h"
Cappuccino::~Cappuccino()
{
    // std::cout << "haminjaaa" << std::endl;
    for (auto& i : side_items) {
        delete i;
    }

    side_items.clear();
}
//----------------------------------------------------------------------------------
Cappuccino::Cappuccino()
    : EspressoBased()
{
    // for (auto& integ : { new Espresso { 2 }, new Milk { 2 }, new MilkFoam { 1 } })

    ingredients.push_back(new Espresso { 2 });
    ingredients.push_back(new Milk { 2 });
    ingredients.push_back(new MilkFoam { 1 });

    for (size_t i; i < side_items.size(); i++)
        side_items[i] = nullptr;

    name = "Cappuccino";
}
//----------------------------------------------------------------------------------
Cappuccino::Cappuccino(const Cappuccino& cap)
    : EspressoBased(cap)
    , side_items { cap.side_items }
{
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
//----------------------------------------------------------------------------------
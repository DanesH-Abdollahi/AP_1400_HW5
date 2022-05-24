#include "espresso_based.h"

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
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
//----------------------------------------------------------------------------------
void EspressoBased::brew()
{
    std::vector<int> Numbers {};
    std::vector<std::string> Names {};
    std::vector<double> Percentages {};

    std::string Sub_Ingridents {};
    for (const auto& ing : ingredients) {
        if (ing != ingredients[ingredients.size() - 1])
            Sub_Ingridents += std::to_string((*ing).get_units()) + " Units of " + (*ing).get_name() + " + ";

        else
            Sub_Ingridents += std::to_string((*ing).get_units()) + " Units of " + (*ing).get_name();

        Numbers.push_back((*ing).get_units());
        Names.push_back((*ing).get_name());
    }

    double Sum { static_cast<double>(accumulate(Numbers.begin(), Numbers.end(), 0)) };

    for (size_t i { 0 }; i < Numbers.size(); i++)
        Percentages.push_back(Numbers[i] / Sum);

    std::vector<double> Add_Percentages {};

    for (size_t i { 0 }; i < Percentages.size(); i++) {
        double Temp {};
        for (size_t j { 0 }; j < i; j++)
            Temp += Percentages[j];

        Add_Percentages.push_back(Temp);
    }

    Add_Percentages.push_back(1.01);

    ftxui::Element Heading
        = ftxui::vbox({
            ftxui::hbox({
                ftxui::text(" Wel ") | ftxui::borderDouble | ftxui::color(ftxui::Color::Red),
                ftxui::text(" Your Order is " + this->get_name() + ". ") | ftxui::borderDouble | ftxui::center | ftxui::color(ftxui::Color::Blue),
                ftxui::text(" Come ") | ftxui::borderDouble | ftxui::color(ftxui::Color::Red),
            }),
            ftxui::hbox({
                ftxui::text(" Sub_Ingredients Ur Coffee Has : ") | ftxui::borderHeavy | ftxui::color(ftxui::Color::White),
                ftxui::text(Sub_Ingridents) | ftxui::borderHeavy | ftxui::center | ftxui::color(ftxui::Color::White),
            }),
        });

    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Fit(Heading), // Width
        ftxui::Dimension::Fit(Heading) // Height
    );
    std::cout << std::endl;
    ftxui::Render(screen, Heading);
    screen.Print();
    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<double> Cup_percent(Names.size());

    std::string reset_position;
    int Fixed_Len { 13 };

    for (size_t iter { 1 }; iter <= Percentages.size(); iter++) {
        for (double Percentage { Add_Percentages[iter - 1] }; Percentage <= Add_Percentages[iter]; Percentage += 0.01) {
            Cup_percent[iter - 1] = (Percentage - Add_Percentages[iter - 1]) * (1.0 / (Add_Percentages[iter] - Add_Percentages[iter - 1]));

            // std::string Percentage_disp = std::to_string(int(Percentage * 100)) + "/100";
            // Element Gauge { ftxui::hbox({
            //     ftxui::text("Brewing : " + Names[iter - 1] + " : " + std::string(Fixed_Len - Names[iter - 1].length(), ' ')) | ftxui::color(ftxui::Color::Yellow),
            //     ftxui::gauge(Percentage) | ftxui::flex | ftxui::color(ftxui::Color::GrayLight),
            //     ftxui::text(" " + Percentage_disp) | ftxui::color(ftxui::Color::White),
            // }) };
            // auto Gauge_Screen { ftxui::Screen::Create(
            //     Dimension::Fit(Heading), // Width
            //     Dimension::Fit(Gauge) // Height
            //     ) };

            // ftxui::Render(Gauge_Screen, Gauge);
            // std::cout << reset_position;
            // Gauge_Screen.Print();
            // reset_position = Gauge_Screen.ResetPosition();
            // // std::cout << std::endl;
            // usleep(80000); // Time in Microseconds
            // Gauge_Screen.ResetPosition();

            std::string Percentage_disp = std::to_string(int(Percentage * 100)) + "/100";
            ftxui::Element Gauge {};

            if (this->get_name() == "Mocha") {
                Gauge = ftxui::hbox({
                    ftxui::hbox({
                        ftxui::text(" Brewing : ") | ftxui::center | ftxui::color(ftxui::Color::Yellow),
                        ftxui::text(Names[iter - 1] + std::string(Fixed_Len - Names[iter - 1].length(), ' ')) | ftxui::center | ftxui::color(ftxui::Color::White),
                    }),
                    ftxui::vbox({
                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                            ftxui::gaugeUp(Cup_percent[3]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[3] * 2),
                        }) | ftxui::flex,
                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                        }) | ftxui::flex,
                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::Red) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                        }) | ftxui::flex,

                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                        }) | ftxui::flex,

                    }) | ftxui::center
                        | ftxui::border,

                    ftxui::text("  "),
                    ftxui::vbox({
                        ftxui::text(Percentage_disp) | ftxui::color(ftxui::Color::White),
                    }) | ftxui::center,

                });
            }

            else {
                Gauge = ftxui::hbox({
                    ftxui::hbox({
                        ftxui::text(" Brewing : ") | ftxui::center | ftxui::color(ftxui::Color::Yellow),
                        ftxui::text(Names[iter - 1] + std::string(Fixed_Len - Names[iter - 1].length(), ' ')) | ftxui::center | ftxui::color(ftxui::Color::White),
                    }),
                    ftxui::vbox({
                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                            ftxui::gaugeUp(Cup_percent[2]) | ftxui::color(ftxui::Color::GrayDark) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[2] * 2),
                        }) | ftxui::flex,
                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                            ftxui::gaugeUp(Cup_percent[1]) | ftxui::color(ftxui::Color::White) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[1] * 2),
                        }) | ftxui::flex,

                        ftxui::hbox({
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                            ftxui::gaugeUp(Cup_percent[0]) | ftxui::color(ftxui::Color::Blue) | ftxui::flex | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, Numbers[0] * 2),
                        }) | ftxui::flex,

                    }) | ftxui::center
                        | ftxui::borderDouble,

                    ftxui::text("  "),
                    ftxui::vbox({
                        ftxui::text(Percentage_disp) | ftxui::color(ftxui::Color::White),
                    }) | ftxui::center,

                });
            }
            // auto Gauge_Screen = ftxui::Screen(60, 12);
            auto Gauge_Screen = ftxui::Screen::Create(
                ftxui::Dimension::Fit(Heading), // Width
                ftxui::Dimension::Fit(Gauge) // Height
            );

            ftxui::Render(Gauge_Screen, Gauge);
            std::cout << reset_position;
            Gauge_Screen.Print();
            reset_position = Gauge_Screen.ResetPosition();
            usleep(100000); // Time in Microseconds
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;

    ftxui::Element End {
        ftxui::hbox({ ftxui::text(" Your Coffee Is Raedy. Enjoy Ur Coffee :) ") | ftxui::borderDouble | ftxui::color(ftxui::Color::Green) })
    };
    auto End_Screen = ftxui::Screen::Create(
        ftxui::Dimension::Fit(Heading),
        ftxui::Dimension::Fit(End));
    ftxui::Render(End_Screen, End);
    End_Screen.Print();
    usleep(3000000); // Sleep for 3 Seconds
    std::cout << std::endl;
    std::cout << std::endl;
}

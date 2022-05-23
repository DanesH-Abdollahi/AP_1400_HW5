#include "cappuccino.h"
#include "espresso_based.h"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (0) // make false to run unit-tests
    {
        using namespace ftxui;
        using namespace std::chrono_literals;

        std::string reset_position;
        for (float percentage = 0.0f; percentage <= 1.001f; percentage += 0.001f) {

            std::string Percentage_disp = std::to_string(int(percentage * 100)) + "/100";
            auto gauge_up = //
                hbox({

                    hbox({ text("Brewing : ") | center,
                        text("Milk  ") | center }),
                    hbox({
                        gaugeUp(percentage) | ftxui::color(ftxui::Color::Yellow),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                        gaugeUp(percentage),
                    }) | border,
                });

            auto document = hbox({
                gauge_up,
                text("  "),
                vbox({
                    filler(),
                    text(Percentage_disp),
                    filler(),
                }),
            });

            auto screen = Screen(50, 18);

            Render(screen, document);
            std::cout << reset_position;
            screen.Print();
            reset_position = screen.ResetPosition();

            std::this_thread::sleep_for(0.01s);
        }
        std::cout << std::endl;
    }

    else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}

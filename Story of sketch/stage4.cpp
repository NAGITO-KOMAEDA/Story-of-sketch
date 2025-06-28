#include "game_functions.h"
#include "text_loader.h"
#include "print_utils.h"
#include "globals.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <map>

void fourth_play_game() {
    int ending = 0;
    std::ifstream file("save.txt");
    if (file.is_open()) {
        file >> ending;
        file.close();
    }

    clear_console();
    print_section("intro");

    print_section("creator_warning");
    print_section("distraction");

    for (int i = 0; i < 3; i++) {
        std::cout << "...\n";
        Sleep(2000);
    }

    print_section("time_passed");
    print_section("portal_appearance");

    print_section("nightmare_appearance");
    print_section("nightmare_dialogue_1");
    print_section("orange_paint_effect");
    print_section("nightmare_dialogue_2");

    print_section("trust_prompt", 0);
    int decision;
    std::cin >> decision;

    if (decision == 1) {
        print_section("bad_ending");
        Sleep(5000);
    }
    else {
        print_section("reject_nightmare");
        print_section("nightmare_departure");

        print_section("error_appearance");
        print_section("error_dialogue_1");
        print_section("orange_paint_effect");
        print_section("error_dialogue_2");
        print_section("error_dialogue_3");
        print_section("error_attack");

        clear_console();
        battle_error();

        print_section("post_battle_1");
        print_section("post_battle_2");
        print_section("soul_revelation");
        print_section("error_reaction");
        print_section("truce_offer");
        print_section("ink_decision");

        clear_console();
        finale_battle(ending);
    }
}
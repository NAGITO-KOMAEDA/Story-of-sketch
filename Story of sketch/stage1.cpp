#include "game_functions.h"
#include "print_utils.h"
#include "monster_loader.h"
#include "text_loader.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <map>

extern std::map<std::string, std::vector<std::string>> game_texts;
extern std::vector<VoidMonster> void_monsters;

void play_game() {
    system("color F0");

    print_section("title");
    print_section("intro");

    int talked_count = 0;
    while (talked_count < void_monsters.size()) {
        print_section("direction_prompt", 0);

        int direction;
        std::cin >> direction;

        bool found_monster = false;
        for (auto& monster : void_monsters) {
            if (monster.direction == direction && !monster.talked_to) {
                std::cout << game_texts["meet_monster"][0] << monster.name << ".\n";
                std::cout << monster.name << " " << game_texts["monster_says"][0] << "\"" << monster.dialogue << "\"\n";
                monster.talked_to = true;
                talked_count++;
                found_monster = true;
                break;
            }
        }

        if (!found_monster) {
            std::cout << (direction >= 1 && direction <= 4 ?
                game_texts["already_talked"][0] :
                game_texts["invalid_direction"][0]) << "\n";
        }
    }

    print_section("daily_routine");
    print_section("decision_prompt", 0);

    int decision;
    std::cin >> decision;

    if (decision == 1) {
        second_play_game();
    }
    else {
        print_section("bad_ending");
    }
}
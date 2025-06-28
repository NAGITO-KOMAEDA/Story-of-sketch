#include "game_functions.h"
#include "print_utils.h"
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include "text_loader.h"

extern std::map<std::string, std::vector<std::string>> game_texts;
extern std::vector<Universe> universes;
extern std::map<std::string, std::vector<std::string>> food_items;

void explore_universes(Player& player) {
    bool allVisited = false;
    while (!allVisited) {
        print_section("universe_prompt", 0);

        std::vector<size_t> availableUniverses;
        for (size_t i = 0; i < universes.size(); ++i) {
            if (!universes[i].visited) {
                std::cout << availableUniverses.size() + 1 << ". " << universes[i].name << "\n";
                availableUniverses.push_back(i);
            }
        }

        if (availableUniverses.empty()) {
            print_section("all_universes_visited");
            allVisited = true;
            continue;
        }

        int choice;
        std::cin >> choice;
        if (choice < 1 || choice > availableUniverses.size()) {
            print_section("invalid_choice");
            continue;
        }

        size_t selectedIndex = availableUniverses[choice - 1];
        Universe& selected = universes[selectedIndex];
        int confirm;

        if (selected.name == "UNDERTALE") {
            print_section("ut_portal");
            clear_console();
            system("color F0");

            std::cout << "\n" << game_texts["entering_universe"][0] << selected.name << ".\n";
            std::cout << selected.startText << "\n";
            print_section("ut_experience");

            Food snowman_piece = {
                food_items["food"][0],
                food_items["food"][1],
                std::stoi(food_items["food"][2])
            };
            player.inventory.push_back(snowman_piece);

            print_section("ut_papyrus_memory");
            print_section("leave_prompt", 0);

            std::cin >> confirm;
            if (confirm == 1) {
                print_section("ut_return");
                std::cout << selected.finalText << std::endl;
                clear_console();
                system("color E0");
                print_section("doodlesphere_return");
            }
            selected.visited = true;
        }
        else if (selected.name == "UNDERSWAP") {
            print_section("us_portal");
            clear_console();
            system("color 4F");

            std::cout << "\n" << game_texts["entering_universe"][0] << selected.name << ".\n";
            std::cout << selected.startText << "\n";
            print_section("us_experience");

            Food instant_noodles = {
                food_items["food"][3],
                food_items["food"][4],
                std::stoi(food_items["food"][5]) 
            };
            player.inventory.push_back(instant_noodles);

            print_section("us_discoveries");
            print_section("leave_prompt", 0);

            std::cin >> confirm;
            if (confirm == 1) {
                print_section("us_return");
                std::cout << selected.finalText << std::endl;
                clear_console();
                system("color E0");
                print_section("doodlesphere_return");
            }
            selected.visited = true;
        }
        else if (selected.name == "UNDERFELL") {
            print_section("uf_portal");
            clear_console();
            system("color 1F");

            std::cout << "\n" << game_texts["entering_universe"][0] << selected.name << ".\n";
            std::cout << selected.startText << "\n";
            print_section("uf_experience");

            Food chocolate = {
                food_items["food"][6],
                food_items["food"][7],
                std::stoi(food_items["food"][8])
            };
            player.inventory.push_back(chocolate);

            print_section("uf_conclusion");
            print_section("leave_prompt", 0);

            std::cin >> confirm;
            if (confirm == 1) {
                print_section("uf_return");
                std::cout << selected.finalText << std::endl;
                clear_console();
                system("color E0");
                print_section("doodlesphere_return");
            }
            selected.visited = true;
        }

        allVisited = true;
        for (const auto& universe : universes) {
            if (!universe.visited) {
                allVisited = false;
                break;
            }
        }
    }
}

void third_play_game() {
    Player player;
    print_section("awakening");
    print_section("doodlesphere_arrival");
    print_section("creator_message");

    explore_universes(player);

    print_section("return_to_doodlesphere");
    print_section("scarf_reminder");
    print_section("chest_pain");
    print_section("universe_destruction");
    print_section("outertale_reveal");
    print_section("battle_prompt", 0);

    int confirm;
    std::cin >> confirm;

    if (confirm == 1) {
        print_section("portal_creation");
        Sleep(1500);
        clear_console();
        system("color 80");
        battle_bad_guys();
    }
    else {
        print_section("no_choice");
        print_section("portal_creation_forced");
        Sleep(1500);
        clear_console();
        system("color 80");
        battle_bad_guys();
    }

    print_section("post_battle");
    print_section("dream_appearance");
    print_section("dream_dialogue");
    print_section("ink_revelation");
    print_section("dream_introduction");
    print_section("story_explanation");
    print_section("brother_reveal");
    print_section("help_request");
    print_section("decision_prompt", 0);

    int ending;
    std::cin >> ending;
    if (ending == 1) {
        std::ofstream outFile("save.txt");
        if (outFile.is_open()) {
            outFile << 1;
            outFile.close();
        }

        print_section("help_agreement");
        print_section("dream_departure");
        clear_console();
        system("color E0");
        fourth_play_game();
    }
}
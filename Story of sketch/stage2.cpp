#include "game_functions.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

std::map<std::string, std::vector<std::string>> load_stage_text(const std::string& filename) {
    std::map<std::string, std::vector<std::string>> text_map;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open text file: " << filename << "\n";
        return text_map;
    }

    std::string line;
    std::string current_section;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line[0] == '[' && line.back() == ']') {
            current_section = line.substr(1, line.size() - 2);
            continue;
        }

        if (!current_section.empty()) {
            text_map[current_section].push_back(line);
        }
    }

    return text_map;
}

auto stage_texts = load_stage_text("texts/stage2_text.txt");

void print_text_with_delay(const std::string& section, int delay_ms = 2000) {
    if (stage_texts.find(section) == stage_texts.end()) {
        std::cerr << "Error: Text section '" << section << "' not found!\n";
        return;
    }

    for (const auto& line : stage_texts[section]) {
        std::cout << line << "\n";
        Sleep(delay_ms);
    }
}

void second_play_game() {
    clear_console();
    system("color 70");

    print_text_with_delay("intro");

    print_text_with_delay("exploration");

    for (int i = 0; i < 3; i++) {
        std::cout << "...\n";
        Sleep(2000);
    }

    print_text_with_delay("search_results");

    print_text_with_delay("waiting");

    for (int i = 0; i < 3; i++) {
        std::cout << "...\n";
        Sleep(2000);
    }

    print_text_with_delay("paint_discovery");

    int decision = 0;
    while (decision != 2) {
        for (const auto& option : stage_texts["paint_options"]) {
            std::cout << option << "\n";
        }

        std::cin >> decision;

        switch (decision) {
        case 1:
            print_text_with_delay("paint_examine");
            break;
        case 2:
            print_text_with_delay("paint_taste");
            break;
        default:
            print_text_with_delay("invalid_choice");
            break;
        }
    }

    print_text_with_delay("after_paint");

    for (int i = 0; i < 3; i++) {
        std::cout << "...\n";
        Sleep(2000);
    }

    print_text_with_delay("red_paint");

    print_text_with_delay("paint_realization");

    print_text_with_delay("paint_collection");

    std::vector<int> available_options = { 1, 2, 3, 4 };
    bool created_something = false;

    while (!created_something) {
        for (const auto& action : stage_texts["creation_options"]) {
            std::cout << action << "\n";
        }

        std::cin >> decision;
        auto it = std::find(available_options.begin(), available_options.end(), decision);
        if (it == available_options.end()) {
            print_text_with_delay("invalid_creation_choice");
            continue;
        }

        switch (decision) {
        case 1:
            print_text_with_delay("study_paints");
            available_options.erase(std::remove(available_options.begin(), available_options.end(), 1), available_options.end());
            break;
        case 2:
            print_text_with_delay("collect_paints");
            available_options.erase(std::remove(available_options.begin(), available_options.end(), 2), available_options.end());
            break;
        case 3:
            print_text_with_delay("create_clothes");
            available_options.erase(std::remove(available_options.begin(), available_options.end(), 3), available_options.end());
            break;
        case 4:
            print_text_with_delay("create_garden");
            available_options.erase(std::remove(available_options.begin(), available_options.end(), 4), available_options.end());
            break;
        }

        if (available_options.empty()) {
            print_text_with_delay("create_world");
            created_something = true;
        }
    }

    print_text_with_delay("creator_secret");

    print_text_with_delay("portal_instructions");

    for (const auto& line : stage_texts["confirmation"]) {
        std::cout << line << "\n";
    }

    int confirm;
    std::cin >> confirm;

    clear_console();
    system("color E0");
    third_play_game();
}
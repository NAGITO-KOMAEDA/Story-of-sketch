#include "print_utils.h"
#include <iostream>
#include <windows.h>

void print_section(const std::string& section, int delay_ms) {
    if (game_texts.find(section) == game_texts.end()) {
        std::cerr << "Error: Section '" << section << "' not found!\n";
        return;
    }

    for (const auto& line : game_texts[section]) {
        std::cout << line << "\n";
        Sleep(delay_ms);
    }
}
#include "game_functions.h"
#include "universe_loader.h"
#include <fstream>
#include <iostream>

std::vector<Universe> load_universes(const std::string& filename) {
    std::vector<Universe> universes;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return universes;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        Universe universe;
        universe.name = line;

        if (!std::getline(file, line)) break;
        universe.startText = line;

        if (!std::getline(file, line)) break;
        universe.finalText = line;

        universes.push_back(universe);
        std::getline(file, line);
    }

    return universes;
}

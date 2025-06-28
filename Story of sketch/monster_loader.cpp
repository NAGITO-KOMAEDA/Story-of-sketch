#include "monster_loader.h"
#include <fstream>
#include <iostream>

std::vector<VoidMonster> load_monsters(const std::string& filename) {
    std::vector<VoidMonster> monsters;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return monsters;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        VoidMonster monster;
        monster.name = line;

        if (!std::getline(file, line)) break;
        monster.direction = std::stoi(line);

        if (!std::getline(file, line)) break;
        monster.dialogue = line;

        monsters.push_back(monster);
        std::getline(file, line);
    }

    return monsters;
}
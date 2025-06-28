#include "game_functions.h"
#include "text_loader.h"
#include "monster_loader.h"
#include "universe_loader.h" 
#include "globals.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>

Player ink;
std::vector<Enemy> enemies;
std::map<std::string, std::vector<std::string>> game_texts;
std::vector<VoidMonster> void_monsters;
std::vector<Universe> universes;
std::map<std::string, std::vector<std::string>> food_items;

void load_global_files() {
    void_monsters = load_monsters("texts/monsters.txt");
    universes = load_universes("texts/universes.txt");
    food_items = load_texts("texts/food_items.txt");

    if (void_monsters.empty()) std::cerr << "Failed to load monsters.txt\n";
    if (universes.empty()) std::cerr << "Failed to load universes.txt\n";
    if (food_items.empty()) std::cerr << "Failed to load food_items.txt\n";
}
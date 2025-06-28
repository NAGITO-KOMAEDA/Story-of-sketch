#pragma once
#include <map>
#include <vector>
#include <string>

struct Player;
struct Enemy;
struct VoidMonster;
struct Universe;

extern std::map<std::string, std::vector<std::string>> game_texts;
extern Player ink;
extern std::vector<Enemy> enemies;
extern std::vector<VoidMonster> void_monsters;
extern std::vector<Universe> universes;
extern std::map<std::string, std::vector<std::string>> food_items;
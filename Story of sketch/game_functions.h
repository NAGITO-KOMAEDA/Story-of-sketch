#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <string>
#include <vector>
#include <map>

class Food {
public:
    Food(const std::string& name, const std::string& description, int heal);
    std::string name;
    std::string description;
    int heal;
};

class Player {
public:
    Player();
    int health;
    int max_health;
    std::vector<int> attack;
    std::vector<Food> inventory;
    int attack_buff_turns;
};

struct Enemy {
    std::string name;
    int health;
    int attack;
};

struct VoidMonster {
    std::string name;
    int direction;
    std::string dialogue;
    bool talked_to = false;
};

struct Universe {
    std::string name;
    std::string startText;
    std::string finalText;
    bool visited = false;
};

void play_game();
void second_play_game();
void third_play_game();
void fourth_play_game();
void battle_bad_guys();
void battle_error();
void finale_battle(int ending);
void explore_universes(Player& player);
void clear_console();
void init_game(bool with_error = false);
void draw_battle_hud(const Player& player, const std::vector<Enemy>& enemies);
void enemies_attack(Player& player, const std::vector<Enemy>& enemies);
std::vector<Universe> load_universes(const std::string& filename);
bool player_turn(Player& player, std::vector<Enemy>& enemies);
std::vector<VoidMonster> load_monsters(const std::string& filename);

extern Player ink;
extern std::vector<Enemy> enemies;
extern std::vector<VoidMonster> void_monsters;
extern std::map<std::string, std::vector<std::string>> game_texts;
extern std::vector<Universe> universes;
extern std::map<std::string, std::vector<std::string>> food_items;

#endif
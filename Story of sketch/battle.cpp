#include "game_functions.h"
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <map>

std::map<std::string, std::vector<std::string>> load_battle_texts(const std::string& filename) {
    std::map<std::string, std::vector<std::string>> text_map;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open battle text file: " << filename << "\n";
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

auto battle_texts = load_battle_texts("texts/battle_text.txt");

void print_battle_text(const std::string& section, int delay_ms = 1500) {
    if (battle_texts.find(section) == battle_texts.end()) {
        std::cerr << "Error: Battle text section '" << section << "' not found!\n";
        return;
    }

    for (const auto& line : battle_texts[section]) {
        std::cout << line << "\n";
        Sleep(delay_ms);
    }
}

void draw_battle_hud(const Player& player, const std::vector<Enemy>& enemies) {
    clear_console();
    std::cout << battle_texts["battle_title"][0] << "\n";

    for (const auto& enemy : enemies) {
        if (enemy.health > 0) {
            std::cout << enemy.name << " " << battle_texts["enemy_hp"][0] << enemy.health << ")\n";
        }
    }

    std::cout << battle_texts["separator"][0] << "\n";
    std::cout << battle_texts["player_hp"][0] << player.health << "/" << player.max_health << " HP\n";

    if (player.attack_buff_turns > 0) {
        std::cout << battle_texts["attack_buff"][0] << player.attack_buff_turns
            << battle_texts["turns_left"][0] << "\n";
    }

    std::cout << battle_texts["separator"][0] << "\n";
}

void enemies_attack(Player& player, const std::vector<Enemy>& enemies) {
    for (const auto& enemy : enemies) {
        if (enemy.health <= 0) continue;

        std::cout << enemy.name << " " << battle_texts["enemy_attacks"][0] << "\n";
        Sleep(1500);

        int damage = enemy.attack;
        player.health -= damage;
        std::cout << battle_texts["damage_dealt"][0] << damage << "!\n";
        Sleep(1000);
    }
}

bool player_turn(Player& player, std::vector<Enemy>& enemies) {
    int decision;
    for (const auto& option : battle_texts["battle_options"]) {
        std::cout << option << "\n";
    }
    std::cin >> decision;

    switch (decision) {
    case 1: {
        std::vector<size_t> aliveEnemies;
        for (size_t i = 0; i < enemies.size(); ++i) {
            if (enemies[i].health > 0) {
                aliveEnemies.push_back(i);
            }
        }

        if (aliveEnemies.empty()) {
            print_battle_text("no_targets");
            return false;
        }

        int targetIndex = rand() % aliveEnemies.size();
        size_t target = aliveEnemies[targetIndex];
        int attackDamage = player.attack[rand() % player.attack.size()];

        if (player.attack_buff_turns > 0) {
            attackDamage += 2;
        }

        enemies[target].health -= attackDamage;
        std::cout << battle_texts["player_attacks"][0] << enemies[target].name
            << battle_texts["and_deals"][0] << attackDamage
            << battle_texts["damage"][0] << "\n";

        if (enemies[target].health <= 0) {
            enemies[target].health = 0;
            std::cout << enemies[target].name << " " << battle_texts["enemy_defeated"][0] << "\n";
        }
        break;
    }
    case 2: {
        if (player.inventory.empty()) {
            print_battle_text("empty_inventory");
            return false;
        }

        std::cout << battle_texts["inventory_title"][0] << "\n";
        for (size_t i = 0; i < player.inventory.size(); ++i) {
            std::cout << i + 1 << ". " << player.inventory[i].name
                << " (" << player.inventory[i].description << ")\n";
        }

        int choice;
        std::cin >> choice;
        if (choice > 0 && choice <= player.inventory.size()) {
            Food used = player.inventory[choice - 1];
            player.health += used.heal;
            if (player.health > player.max_health) {
                player.health = player.max_health;
            }
            std::cout << battle_texts["item_used"][0] << used.name << "! +"
                << used.heal << " HP\n";
            player.inventory.erase(player.inventory.begin() + choice - 1);
        }
        break;
    }
    case 3:
        if (player.attack_buff_turns <= 0) {
            player.attack_buff_turns = 2;
            print_battle_text("red_paint_effect");
        }
        else {
            print_battle_text("red_paint_active");
        }
        break;
    case 4:
        print_battle_text("try_negotiate");
        break;
    default:
        print_battle_text("invalid_choice");
        return false;
    }

    if (player.attack_buff_turns > 0) {
        player.attack_buff_turns--;
        if (player.attack_buff_turns == 0) {
            print_battle_text("red_paint_ends");
        }
    }
    return false;
}

void battle_bad_guys() {
    init_game(false);
    print_battle_text("bad_guys_intro");
    print_battle_text("nightmare_dialogue");
    print_battle_text("horror_dialogue");
    print_battle_text("killer_dialogue");
    print_battle_text("dust_dialogue");
    print_battle_text("realization");
    print_battle_text("nightmare_response");
    print_battle_text("killer_response");
    print_battle_text("horror_attack");

    while (ink.health > 0) {
        draw_battle_hud(ink, enemies);
        bool enemySkipped = player_turn(ink, enemies);

        bool allDead = true;
        for (const auto& enemy : enemies) {
            if (enemy.health > 0) {
                allDead = false;
                break;
            }
        }

        if (allDead) {
            print_battle_text("player_wins");
            return;
        }

        if (!enemySkipped) {
            enemies_attack(ink, enemies);
        }

        Sleep(2000);

        if (ink.health <= 0) {
            print_battle_text("player_defeated");
            return;
        }
    }
}

void battle_error() {
    init_game(true);
    ink.attack_buff_turns = 0;

    print_battle_text("error_intro");

    while (ink.health > 0) {
        draw_battle_hud(ink, enemies);
        bool enemySkipped = player_turn(ink, enemies);

        if (enemies[0].health <= 0) {
            print_battle_text("error_defeated");
            return;
        }

        if (!enemySkipped) {
            enemies_attack(ink, enemies);
        }

        Sleep(2000);

        if (ink.health <= 0) {
            print_battle_text("player_defeated_error");
            return;
        }
    }
}

void finale_battle(int ending) {
    ink.health = 70;
    ink.max_health = 70;
    ink.attack = { 10 };
    ink.attack_buff_turns = 0;

    enemies.clear();
    enemies = {
        {"Найтмер", 20, 7},
        {"Хоррор", 15, 3},
        {"Киллер", 15, 4},
        {"Даст", 15, 4}
    };

    std::vector<Enemy> allies = { {"Эррор", 9999, 10} };
    if (ending == 1) {
        allies.push_back({ "Дрим", 9999, 10 });
    }

    auto drawFinalHUD = [&]() {
        clear_console();
        std::cout << battle_texts["final_battle_title"][0] << "\n";
        for (const auto& enemy : enemies) {
            if (enemy.health > 0) {
                std::cout << enemy.name << " " << battle_texts["enemy_hp"][0] << enemy.health << ")\n";
            }
        }
        std::cout << battle_texts["separator"][0] << "\n";
        std::cout << battle_texts["player_hp"][0] << ink.health << "/70 HP | "
            << battle_texts["attack"][0] << "10";
        if (ink.attack_buff_turns > 0) {
            std::cout << " (+2 " << battle_texts["buff"][0] << ", "
                << battle_texts["turns_left"][0] << ink.attack_buff_turns << ")";
        }
        std::cout << "\n" << battle_texts["separator"][0] << "\n";
        };

    auto playerFinalTurn = [&]() {
        int decision;
        for (const auto& option : battle_texts["final_battle_options"]) {
            std::cout << option << "\n";
        }
        std::cin >> decision;

        switch (decision) {
        case 1: {
            std::vector<size_t> aliveEnemies;
            for (size_t i = 0; i < enemies.size(); ++i) {
                if (enemies[i].health > 0) aliveEnemies.push_back(i);
            }

            if (aliveEnemies.empty()) {
                print_battle_text("no_targets");
                return false;
            }

            size_t target = aliveEnemies[rand() % aliveEnemies.size()];
            int attackDamage = 10;
            if (ink.attack_buff_turns > 0) {
                attackDamage += 2;
            }
            enemies[target].health -= attackDamage;

            std::cout << battle_texts["player_attacks"][0] << enemies[target].name
                << battle_texts["and_deals"][0] << attackDamage
                << battle_texts["damage"][0] << "\n";

            if (enemies[target].health <= 0) {
                enemies[target].health = 0;
                std::cout << enemies[target].name << " " << battle_texts["enemy_defeated"][0] << "\n";
            }
            break;
        }
        case 2: {
            if (ink.inventory.empty()) {
                print_battle_text("empty_inventory");
                return false;
            }

            std::cout << battle_texts["inventory_title"][0] << "\n";
            for (size_t i = 0; i < ink.inventory.size(); ++i) {
                std::cout << i + 1 << ". " << ink.inventory[i].name
                    << " (" << ink.inventory[i].description << ")\n";
            }

            int choice;
            std::cin >> choice;
            if (choice > 0 && choice <= ink.inventory.size()) {
                Food used = ink.inventory[choice - 1];
                ink.health += used.heal;
                if (ink.health > ink.max_health) {
                    ink.health = ink.max_health;
                }
                std::cout << battle_texts["item_used"][0] << used.name << "! +"
                    << used.heal << " HP\n";
                ink.inventory.erase(ink.inventory.begin() + choice - 1);
            }
            break;
        }
        case 3:
            if (ink.attack_buff_turns <= 0) {
                ink.attack_buff_turns = 2;
                print_battle_text("red_paint_effect");
            }
            else {
                print_battle_text("red_paint_active");
            }
            return false;
        case 4: {
            std::vector<size_t> aliveEnemies;
            for (size_t i = 0; i < enemies.size(); ++i) {
                if (enemies[i].health > 0) aliveEnemies.push_back(i);
            }

            if (aliveEnemies.empty()) {
                print_battle_text("no_targets");
                return false;
            }

            for (const auto& ally : allies) {
                size_t target = aliveEnemies[rand() % aliveEnemies.size()];
                enemies[target].health -= ally.attack;
                std::cout << ally.name << " " << battle_texts["player_attacks"][0]
                    << enemies[target].name << battle_texts["and_deals"][0]
                    << ally.attack << battle_texts["damage"][0] << "\n";
                if (ending == 1) {
                    ink.health += 10;
                    std::cout << "Дрим " << battle_texts["heals"][0] << "10 "
                        << battle_texts["hp"][0] << "\n";
                }
                if (enemies[target].health <= 0) {
                    enemies[target].health = 0;
                    std::cout << enemies[target].name << " " << battle_texts["enemy_defeated"][0] << "\n";
                }
            }
            return false;
        }
        default:
            print_battle_text("invalid_choice");
            return false;
        }
        return false;
        };

    while (ink.health > 0) {
        drawFinalHUD();
        bool enemySkipped = playerFinalTurn();

        bool allDead = true;
        for (const auto& enemy : enemies) {
            if (enemy.health > 0) {
                allDead = false;
                break;
            }
        }

        if (allDead) {
            std::cout << battle_texts["victory_title"][0] << "\n";
            if (ending == 1) {
                print_battle_text("good_ending");
            }
            else {
                print_battle_text("neutral_ending");
            }
            Sleep(3000);
            return;
        }

        if (!enemySkipped) {
            for (auto& enemy : enemies) {
                if (enemy.health > 0) {
                    std::cout << enemy.name << " " << battle_texts["enemy_attacks_player"][0] << "\n";
                    Sleep(1000);
                    int damage = enemy.attack;
                    ink.health -= damage;
                    std::cout << battle_texts["damage_dealt"][0] << damage << "!\n";
                    Sleep(1000);
                }
            }
        }

        if (ink.health <= 0) {
            std::cout << battle_texts["defeat_title"][0] << "\n";
            std::cout << battle_texts["bad_ending"][0] << "\n";
            Sleep(3000);
            return;
        }

        if (ink.attack_buff_turns > 0) {
            ink.attack_buff_turns--;
            if (ink.attack_buff_turns == 0) {
                print_battle_text("red_paint_ends");
            }
        }

        Sleep(2000);
    }
}
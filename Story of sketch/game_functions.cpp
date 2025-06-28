#include "game_functions.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <fstream>

Food::Food(const std::string& name, const std::string& description, int heal)
    : name(name), description(description), heal(heal) {
}

Player::Player() : health(50), max_health(50), attack_buff_turns(0) {
    attack = { 1, 5, 7, 12, 15, 18, 20 };
}

void clear_console() {
    std::cout << "\033[2J\033[H";
}

void init_game(bool with_error) {
    ink = Player();
    ink.inventory = {
        Food("Кусок снеговика", "Кусок снеговика, который Инк украл из оригинального Сноудина", 20),
        Food("Заваримая лапша", "Лапша, взятая из лабаратории Андайн", 15),
        Food("Шоколад с перцем", "Шоколад, сворованный у Санса из Андерфелла", 10)
    };

    if (with_error) {
        enemies = { {"Эррор", 10, 5} };
    }
    else {
        enemies = {
            {"Хоррор", 8, 2},
            {"Найтмер", 10, 5},
            {"Даст", 8, 3},
            {"Киллер", 8, 3}
        };
    }
}
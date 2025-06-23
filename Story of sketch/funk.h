#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <vector>
#include <string>

void playGame();
void secondPLayGame();
void battleBadGuys();
void thirdPlayGame();
void fourthPlayGame();

class Food {
public:
    std::string name;
    std::string description;
    int heal;

    Food(std::string n, std::string d, int h) : name(n), description(d), heal(h) {}
};

class Player {
public:
    int health = 50;
    int maxHealth = 50;
    std::vector<int> attack = { 1, 5, 7, 12, 15, 18, 20 };
    std::vector<Food> inventory;
};

struct Enemy {
    std::string name;
    int health;
    int attack;
};

extern std::vector<Food> availableFood;

#endif
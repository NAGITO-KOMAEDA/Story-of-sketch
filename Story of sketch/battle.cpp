#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "funk.h"

void drawBattleHUD(const Player& player, const std::vector<Enemy>& enemies) {
    system("cls");
    std::cout << "=== БИТВА ===\n";
    for (const auto& enemy : enemies) {
        if (enemy.health > 0) {
            std::cout << enemy.name << " (HP: " << enemy.health << ")\n";
        }
    }
    std::cout << "-----------------\n";
    std::cout << "Инк: " << player.health << "/" << player.maxHealth << " HP\n";
    std::cout << "-----------------\n";
}

void enemiesAttack(Player& player, std::vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        if (enemy.health <= 0) continue;
        std::cout << enemy.name << " атакует." << std::endl;
        Sleep(1500);
        int damage = enemy.attack;
        if (damage < 0) damage = 0;
        player.health -= damage;
        std::cout << "Урон: " << damage << "!\n";
        Sleep(1000);
    }
}

bool playerTurn(Player& player, std::vector<Enemy>& enemies) {
    int decision;
    std::cout << "1. Атака\n2. Предмет\n3. Действие (попытка договориться)\n";
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
            std::cout << "Нет целей для атаки!\n";
            break;
        }

        int targetIndex = rand() % aliveEnemies.size();
        size_t target = aliveEnemies[targetIndex];
        int attackDamage = player.attack[rand() % player.attack.size()];
        enemies[target].health -= attackDamage;

        std::cout << "Инк атакует " << enemies[target].name << " и наносит " << attackDamage << " урона!\n";

        if (enemies[target].health <= 0) {
            enemies[target].health = 0;
            std::cout << enemies[target].name << " побежден!\n";
        }
        break;
    }
    case 2:
        if (player.inventory.empty()) {
            std::cout << "Инвентарь пуст!\n";
            return false;
        }

        std::cout << "Инвентарь:\n";
        for (size_t i = 0; i < player.inventory.size(); ++i) {
            std::cout << i + 1 << ". " << player.inventory[i].name
                << " (" << player.inventory[i].description << ")\n";
        }
        int choice;
        std::cin >> choice;
        if (choice > 0 && choice <= player.inventory.size()) {
            Food used = player.inventory[choice - 1];
            player.health += used.heal;
            if (player.health > player.maxHealth) {
                player.health = player.maxHealth;
            }
            std::cout << "Использован " << used.name << "! +" << used.heal << " HP\n";
            player.inventory.erase(player.inventory.begin() + choice - 1);
        }
        break;
    case 3: {
        std::cout << "Инк пытается договориться...\n";
        std::cout << "Это бесполезно. Они само зло.\n";
        break;
    }
    default:
        std::cout << "Неверный выбор!\n";
        return false;
    }
    return false;
}

void battleBadGuys() {
    Player ink;
    ink.inventory = {
        Food("Кусок снеговика", "Кусок снеговика, который Инк украл из оригинального Сноудина", 20),
        Food("Заваримая лапша", "Лапша, взятая из лабаратории Андайн", 15),
        Food("Шоколад с перцем", "Шоколад, сворованный у Санса из Андерфелла", 10)
    };

    std::vector<Enemy> enemies = {
        {"Хоррор", 8, 2},
        {"Найтмер", 10, 5},
        {"Даст", 8, 3},
        {"Киллер", 8, 3}
    };

    std::cout << "Как только ты вышел из портала, мимо тебя пролетела пара костей..\n";
    std::cout << "Впереди ты видишь 4 Сансов. Видимо они из каких-то других вселенных, но могут также перемещаться между ними, как и ты?.\n";
    std::cout << "Кажется, ты привлёк их внимание, потому что все 4 теперь смотрят на тебя.\n";
    std::cout << "Найтмер:\n";
    std::cout << "О. А это ещё что за чудик? Киллер, Даст, вы такого не припоминаете?\n";
    Sleep(3000);
    std::cout << "Хоррор:\n";
    std::cout << "Босс, а почему вы не спросили у меня?.\n";
    Sleep(3000);
    std::cout << "Киллер:\n";
    std::cout << "Это очевидно: у тебя буквально дырявая башка. Но отвечая на твой вопрос, босс, я такого красавчика не помню.\n";
    Sleep(3000);
    std::cout << "Даст:\n";
    std::cout << "Может он пришёл нам помочь добить этих монстров?\n";
    Sleep(3000);
    std::cout << "В это время для тебя становится всё предельно ясно.\n";
    std::cout << "Именно от них тебе и нужно защищать мультивселенную.\n";
    std::cout << "Но зачем они это делают? Они же сами создания альтернативных вселенных. Ты решил озвучить свой вопрос.\n";
    std::cout << "Найтмер:\n";
    std::cout << "О нет, он такая же зануда, как и мой братец.\n";
    Sleep(3000);
    std::cout << "Киллер:\n";
    std::cout << "Мы не обязаны тебе что-то объяснять чудак.\n";
    Sleep(3000);
    std::cout << "Хоррор:\n";
    std::cout << "Давайте мы убьём его, раз он мешает нашему веселью!\n";
    std::cout << "О нет, похоже придётся драться...\n";
    Sleep(3000);

    while (ink.health > 0) {
        drawBattleHUD(ink, enemies);
        bool enemySkipped = playerTurn(ink, enemies);

        bool allDead = true;
        for (const auto& enemy : enemies) {
            if (enemy.health > 0) allDead = false;
        }
        if (allDead) {
            std::cout << "Инк победил!\n";
            Sleep(1000);
            return;
        }

        if (!enemySkipped) {
            enemiesAttack(ink, enemies);
        }
        Sleep(2000);

        if (ink.health <= 0) {
            std::cout << "Инк повержен...\n";
            Sleep(1000);
            return;
        }
    }
}
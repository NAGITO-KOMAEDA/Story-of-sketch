#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "funk.h"

void drawBattleHUD(const Player& player, const std::vector<Enemy>& enemies) {
    system("cls");
    std::cout << "=== ����� ===\n";
    for (const auto& enemy : enemies) {
        if (enemy.health > 0) {
            std::cout << enemy.name << " (HP: " << enemy.health << ")\n";
        }
    }
    std::cout << "-----------------\n";
    std::cout << "���: " << player.health << "/" << player.maxHealth << " HP\n";
    std::cout << "-----------------\n";
}

void enemiesAttack(Player& player, std::vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        if (enemy.health <= 0) continue;
        std::cout << enemy.name << " �������." << std::endl;
        Sleep(1500);
        int damage = enemy.attack;
        if (damage < 0) damage = 0;
        player.health -= damage;
        std::cout << "����: " << damage << "!\n";
        Sleep(1000);
    }
}

bool playerTurn(Player& player, std::vector<Enemy>& enemies) {
    int decision;
    std::cout << "1. �����\n2. �������\n3. �������� (������� ������������)\n";
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
            std::cout << "��� ����� ��� �����!\n";
            break;
        }

        int targetIndex = rand() % aliveEnemies.size();
        size_t target = aliveEnemies[targetIndex];
        int attackDamage = player.attack[rand() % player.attack.size()];
        enemies[target].health -= attackDamage;

        std::cout << "��� ������� " << enemies[target].name << " � ������� " << attackDamage << " �����!\n";

        if (enemies[target].health <= 0) {
            enemies[target].health = 0;
            std::cout << enemies[target].name << " ��������!\n";
        }
        break;
    }
    case 2:
        if (player.inventory.empty()) {
            std::cout << "��������� ����!\n";
            return false;
        }

        std::cout << "���������:\n";
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
            std::cout << "����������� " << used.name << "! +" << used.heal << " HP\n";
            player.inventory.erase(player.inventory.begin() + choice - 1);
        }
        break;
    case 3: {
        std::cout << "��� �������� ������������...\n";
        std::cout << "��� ����������. ��� ���� ���.\n";
        break;
    }
    default:
        std::cout << "�������� �����!\n";
        return false;
    }
    return false;
}

void battleBadGuys() {
    Player ink;
    ink.inventory = {
        Food("����� ���������", "����� ���������, ������� ��� ����� �� ������������� ��������", 20),
        Food("��������� �����", "�����, ������ �� ����������� ������", 15),
        Food("������� � ������", "�������, ����������� � ����� �� ����������", 10)
    };

    std::vector<Enemy> enemies = {
        {"������", 8, 2},
        {"�������", 10, 5},
        {"����", 8, 3},
        {"������", 8, 3}
    };

    std::cout << "��� ������ �� ����� �� �������, ���� ���� ��������� ���� ������..\n";
    std::cout << "������� �� ������ 4 ������. ������ ��� �� �����-�� ������ ���������, �� ����� ����� ������������ ����� ����, ��� � ��?.\n";
    std::cout << "�������, �� ������ �� ��������, ������ ��� ��� 4 ������ ������� �� ����.\n";
    std::cout << "�������:\n";
    std::cout << "�. � ��� ��� ��� �� �����? ������, ����, �� ������ �� ������������?\n";
    Sleep(3000);
    std::cout << "������:\n";
    std::cout << "����, � ������ �� �� �������� � ����?.\n";
    Sleep(3000);
    std::cout << "������:\n";
    std::cout << "��� ��������: � ���� ��������� ������� �����. �� ������� �� ���� ������, ����, � ������ ���������� �� �����.\n";
    Sleep(3000);
    std::cout << "����:\n";
    std::cout << "����� �� ������ ��� ������ ������ ���� ��������?\n";
    Sleep(3000);
    std::cout << "� ��� ����� ��� ���� ���������� �� ��������� ����.\n";
    std::cout << "������ �� ��� ���� � ����� �������� ���������������.\n";
    std::cout << "�� ����� ��� ��� ������? ��� �� ���� �������� �������������� ���������. �� ����� �������� ���� ������.\n";
    std::cout << "�������:\n";
    std::cout << "� ���, �� ����� �� ������, ��� � ��� ������.\n";
    Sleep(3000);
    std::cout << "������:\n";
    std::cout << "�� �� ������� ���� ���-�� ��������� �����.\n";
    Sleep(3000);
    std::cout << "������:\n";
    std::cout << "������� �� ����� ���, ��� �� ������ ������ �������!\n";
    std::cout << "� ���, ������ ������� �������...\n";
    Sleep(3000);

    while (ink.health > 0) {
        drawBattleHUD(ink, enemies);
        bool enemySkipped = playerTurn(ink, enemies);

        bool allDead = true;
        for (const auto& enemy : enemies) {
            if (enemy.health > 0) allDead = false;
        }
        if (allDead) {
            std::cout << "��� �������!\n";
            Sleep(1000);
            return;
        }

        if (!enemySkipped) {
            enemiesAttack(ink, enemies);
        }
        Sleep(2000);

        if (ink.health <= 0) {
            std::cout << "��� ��������...\n";
            Sleep(1000);
            return;
        }
    }
}
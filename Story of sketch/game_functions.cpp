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
        Food("����� ���������", "����� ���������, ������� ��� ����� �� ������������� ��������", 20),
        Food("��������� �����", "�����, ������ �� ����������� ������", 15),
        Food("������� � ������", "�������, ����������� � ����� �� ����������", 10)
    };

    if (with_error) {
        enemies = { {"�����", 10, 5} };
    }
    else {
        enemies = {
            {"������", 8, 2},
            {"�������", 10, 5},
            {"����", 8, 3},
            {"������", 8, 3}
        };
    }
}
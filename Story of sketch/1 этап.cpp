#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include "funk.h"

class VoidMonster {
public:
    std::string name;
    int direction;
    std::string dialogue;
    bool talkedTo;

    VoidMonster(std::string n, int dir, std::string d) : name(n), direction(dir), dialogue(d), talkedTo(false) {}
};

void playGame() {
    system("color F0");
    Player ink;
    std::vector<VoidMonster> voidMonsters = {
        VoidMonster("�������", 1, "���, �� ����� ������, ��� � ��� �������..."),
        VoidMonster("���������� ������", 4, "���, ���� ��������� ��������� �� ������, �� ��� � ��������� ���������� ��� ����� �������������."),
        VoidMonster("������ ��� �����������", 2, "� �������� ���� �������������, ������ ��� �������� ��� � ����� ���������?!"),
        VoidMonster("�������", 3, "���, ���� ������� ������ ���� �� ���, � ���� ���� ����, �� ������ �����������...")
    };

    std::cout << "=== _TALE ===" << std::endl;
    std::cout << "�� ������������ � ����������� �������. ��� �� �����, �� �����, ������ ����������� �����.\n";
    std::cout << "�����-�� ������-����� ���� ������������� �������� ������� �� ��� ��������� �������������� ��������� UNDERTALE.\n";
    std::cout << "�� ���-�� ���������.\n";
    std::cout << "��� �������� ���, ������� ���� ��������� ���������.\n";
    std::cout << "�� ��� ���� �������� ��� ��� ������ �� ������� � �������� � ������� ���������� ���������.\n";

    int talkedCount = 0;
    while (talkedCount < voidMonsters.size()) {
        std::cout << "���� �� ������ �����?\n1. �����\n2. ������\n3. ��\n4. �����\n";
        int direction;
        std::cin >> direction;
        bool foundMonster = false;
        for (auto& monster : voidMonsters) {
            if (monster.direction == direction && !monster.talkedTo) {
                std::cout << "�� ����� � ��������� ����������� � ���������� " + monster.name + ".\n";
                std::cout << monster.name + " �������: \"" + monster.dialogue + "\"\n";
                monster.talkedTo = true;
                talkedCount++;
                foundMonster = true;
                break;
            }
        }
        if (!foundMonster) {
            if (direction >= 1 && direction <= 4) {
                std::cout << "�� ��� ������� � �������� � ���� �����������. �������� ������ �����������.\n";
            }
            else {
                std::cout << "��� ������ �����������. �������� ��� ���.\n";
            }
        }
    }

    std::cout << "������� �� �� ������� ������ ������.\n";
    std::cout << "�� �� �������, �� �� ���������, �� �� ���������� ����������.\n";
    std::cout << "�� ������ �� ������ ��� �������.\n";
    std::cout << "�� ������ ��������� ������ ����� ������� ����� ����.\n";
    std::cout << "���� � ������ �������� ������ ����, ��� ����� ��������� ���� ���� ��.\n";
    std::cout << "���� �� ��� ��� ������ �������� � �����?\n";
    std::cout << "����� �� ����������??\n1. ��\n2. �� ����� ��� ���������\n";

    int decision;
    std::cin >> decision;

    switch (decision) {
    case 1:
        secondPLayGame();
        break;
    case 2:
        std::cout << "=== ������ �������� ===\n";
        std::cout << "��� ����� �� ��������� ����� ������ � ������� ���� � ������ ���������. �� �� �� ���� ��������. �� ����� �������� ��� ���� ���������� ����� (�� ���� �������������).";
        break;
    default:
        std::cout << "� ���� ���� ������ ��� ������, �� �� ������� ������ ��������������.";
        break;
    }
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    playGame();

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include "funk.h"

void secondPLayGame() {
    system("cls");
    system("color 70");
    std::cout << "�� ������������ � �����-�� �����.\n";
    std::cout << "�� ��� �� ����������?\n";
    std::cout << "��� �� ����� ��������?\n";
    std::cout << "� ����� ������� - ��� �� ������?\n";
    std::cout << "������������ ������, �� ���������, ��� ���������� � �����-�� ������� ������-������ �����.\n";
    std::cout << "��� ���� �������� �� ������ ������ ����� � ������-�� ������� ����������\n";
    std::cout << "�� ������ ����� � ������ �� �� �������.\n";
    std::cout << "��� �� ��������� � �����?\n";
    std::cout << "�� ��������� �������� �� ������� � ������� ���� �� ����-��.\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "�� �� ������ ������� ������� ������ � ��� ���, ��� �� ����� �� ������ ���� �� ����-������ � ���� �������.\n";
    std::cout << "�� �� ������ �� �����.\n";
    std::cout << "�������� ��, �� ������ ����������� ������������, ��������, �� ��� ���� �� ����.\n";
    std::cout << "�� �� �� ���������� ������.\n";
    std::cout << "�� ����� ����� �� '���' � ����� ������-�� ����.\n";
    std::cout << "����� ���� ���� ������ ��-���� ������� � ����.\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "�� ����� �� ������ ������� ������� �� ������ �����, ���� ������� �� ���� �� ������ ���-�� ������.\n";
    std::cout << "�� �������� �� ��� ����� ������ ����� � ���������, ��� ��� ������.\n";
    int decision = 0;
    while (decision != 2) {
        std::cout << "��� ���� ����� �������?\n1.��������� �\n2. ����������� � �� ����\n";
        std::cin >> decision;
        switch (decision) {
        case 1:
            std::cout << "��� ������ ������ �����. ������� ������, �� ���� ������ �� �����.\n";
            break;
        case 2:
            std::cout << "�� ������� ����������� ������ �� ����.\n";
            std::cout << "����� � ���� ���-�� ��������.\n";
            std::cout << "�� ��������� �����������...�������?\n";
            std::cout << "��� �� ����� ������, �� �� ��� ���, ��� �������-�� ���-�� ����������, ��� ��������� �������.\n";
            break;
        default:
            std::cout << "��� �� ��� ����������� ������ � �������???\n";
            break;
        }
    }
    std::cout << "����� ������� ��� �������!\n";
    std::cout << "�� �������� �����-�� ����� � �� ����� �� ������ �����������.\n";
    std::cout << "�� ����� ������� ����������� ����������� ���� �����...\n";
    std::cout << "�� ����� �������� �� '���' � �������� ��������� ������.\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "�������� �����-�� �����, ���� �� ���� �� ������ ��������� ����� ������.\n";
    std::cout << "�� ���� ��� ��� ������� ������.\n";
    std::cout << "������ ���� ������ ���� ��������� ����.\n";
    std::cout << "������ �� ������� � ���� �����? ������ �� ������ �� �������? ������ �� ����?\n";
    std::cout << "� �� ���� ������ �� ������ ������� � ���� ���������!\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "����� �� ����������, �� ���������, ��� ������ ������ ���-�� ��������� �� ����, � ������ �������� ������.\n";
    std::cout << "�, �������������, ��� ������ �������, ���� � ���� ��� ����, ��� � ������� ��������.\n";
    std::cout << "���� ����, ��� �� ��� ��� ����, �������� ������������ ��� �� ����, ��� ��� �� ������ ����������� ������������ ����������.\n";
    std::cout << "����� ������ ��������� ���� ������.\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "�������� ��� ������� �������, � � ���� ���� ����� ��������� ������.\n";
    std::cout << "�� �������-�� ��������� ������������ ������, ������� �� ����, �� �� ��������������.\n";
    std::cout << "�..���!\n";
    std::cout << "� ������� ������ �� ������ �������� ��������.\n";
    std::cout << "��� �������� ���������� �����������.\n";
    std::vector<int> availableOptions = { 1, 2, 3, 4 };
    bool createdSomething = false;
    while (!createdSomething) {
        std::cout << "��� �� ������ ������� � ��������?\n";
        for (int option : availableOptions) {
            switch (option) {
            case 1: std::cout << "1. ������� ��� ������\n"; break;
            case 2: std::cout << "2. ���-�� ����������� ������� ������\n"; break;
            case 3: std::cout << "3. ���������� ���� ������\n"; break;
            case 4: std::cout << "4. ���������� ���-������ � �������\n"; break;
            }
        }
        std::cin >> decision;
        auto it = std::find(availableOptions.begin(), availableOptions.end(), decision);
        if (it == availableOptions.end()) {
            std::cout << "��� ��� �� ������ ������� � ��������???\n";
            continue;
        }
        switch (decision) {
        case 1:
            std::cout << "�� ��������� ���������, ��� ������ ������ ������.\n";
            std::cout << "������� - ����, ��������� - ���������, ����� - �������, ������ - ����������, ������� - ������, ����� - �����, ���������� - ����, ������� - ������.\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 1), availableOptions.end());
            break;
        case 2:
            std::cout << "�� ��������� ������� ������ � ����������������� �������...\n";
            std::cout << "��� ��������! ������ � ���� ���� ����� ������.\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 2), availableOptions.end());
            break;
        case 3:
            std::cout << "�� ������� ���� �������� ������...\n";
            std::cout << "������ �� ��������� ����� �����.\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 3), availableOptions.end());
            break;
        case 4:
            std::cout << "�� ��������� �������� � �������...\n";
            Sleep(2000);
            std::cout << "...\n";
            std::cout << "���������� ���������� ������ ���!\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 4), availableOptions.end());
            break;
        default:
            std::cout << "��� ��� �� ������ ������� � ��������???\n";
            break;
        }
        if (availableOptions.size() == 0) {
            std::cout << "�� ����� �� ��������� �������� � �������...\n";
            Sleep(2000);
            std::cout << "...\n";
            Sleep(2000);
            std::cout << "...\n";
            std::cout << "���������� ���������� ����� ���!\n";
            createdSomething = true;
        }
    }
    std::cout << "� ��� ���� ������� ������� �����.\n";
    std::cout << "����� ���� �����-�� ���������, � �������� �� ������ �������� � ����� ������.\n";
    std::cout << "�� ���� �� ������ ������ ����� � ���.\n";
    std::cout << "������, ������� ����� ����� �� ����, ���� �� ���.\n";
    std::cout << "��������� �������, ��� �� ����� ��������� ���������������, ��� ���� ����� ������� � ���������, ��� ��� ��� ��������, ���� ��� � ���������.\n";
    std::cout << "�������, ��� �� ������ ���-�� ������� ������.\n";
    std::cout << "�� �� ��� � ���� ����, ��� ��� ������ � ���� ����������� ����� � ���� ������.\n";
    std::cout << "��������, ���� �� ������� �������� �������� � ��������� ���� ������ �� '����', ��...\n";
    int confirm;
    std::cout << "�� ����� �����?\n1. ��\n";
    std::cin >> confirm;
    if (confirm == 1) {
        system("cls");
        system("color E0");
        thirdPlayGame();
    }
    else {
        std::cout << "�� ����� ���� � ���� ��� ������!";
        Sleep(1000);
        system("cls");
        system("color E0");
        thirdPlayGame();
    }
}
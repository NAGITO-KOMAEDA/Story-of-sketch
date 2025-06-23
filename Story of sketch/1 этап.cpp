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
        VoidMonster("Папирус", 1, "Инк, всё будет хорошо, она к нам вернётся..."),
        VoidMonster("Безымянный монстр", 4, "Инк, пора перестать надеяться на лучшее, мы так и останемся черновиком для нашей создательницы."),
        VoidMonster("Монстр без конечностей", 2, "Я ненавижу нашу создательницу, почему она оставила нас в таком состоянии?!"),
        VoidMonster("Призрак", 3, "Инк, тебе повезло больше всех из нас, у тебя есть душа, ты умеешь чувствовать...")
    };

    std::cout << "=== _TALE ===" << std::endl;
    std::cout << "Ты просыпаешься в бесконечной пустоте. Нет ни звука, ни света, только бесконечное ничто.\n";
    std::cout << "Когда-то давным-давно твоя создательница пыталась сделать из вас очередную альтернативную вселенную UNDERTALE.\n";
    std::cout << "Но что-то произошло.\n";
    std::cout << "Она покинула вас, отсавив лишь небрежным наброском.\n";
    std::cout << "Всё что тебе осталось так это ходить по пустоте и общаться с другими бездушными монстрами.\n";

    int talkedCount = 0;
    while (talkedCount < voidMonsters.size()) {
        std::cout << "Куда ты хочешь пойти?\n1. Север\n2. Восток\n3. Юг\n4. Запад\n";
        int direction;
        std::cin >> direction;
        bool foundMonster = false;
        for (auto& monster : voidMonsters) {
            if (monster.direction == direction && !monster.talkedTo) {
                std::cout << "Ты идешь в выбранном направлении и встречаешь " + monster.name + ".\n";
                std::cout << monster.name + " говорит: \"" + monster.dialogue + "\"\n";
                monster.talkedTo = true;
                talkedCount++;
                foundMonster = true;
                break;
            }
        }
        if (!foundMonster) {
            if (direction >= 1 && direction <= 4) {
                std::cout << "Ты уже говорил с монстром в этом направлении. Попробуй другое направление.\n";
            }
            else {
                std::cout << "Нет такого направления. Попробуй еще раз.\n";
            }
        }
    }

    std::cout << "Сегодня ты не услышал ничего нового.\n";
    std::cout << "Те же монстры, те же разговоры, то же равнодушие окружающих.\n";
    std::cout << "Ты больше не можешь это терпеть.\n";
    std::cout << "Ты хочешь выбраться отсюда всеми фибрами своей души.\n";
    std::cout << "Тебе с голову приходит глупая идея, как можно завершить весь этот ад.\n";
    std::cout << "Есть ли рай для убитых монстров с душой?\n";
    std::cout << "Стоит ли попытаться??\n1. ДА\n2. Не стоит так рисковать\n";

    int decision;
    std::cin >> decision;

    switch (decision) {
    case 1:
        secondPLayGame();
        break;
    case 2:
        std::cout << "=== ПЛОХАЯ КОНЦОВКА ===\n";
        std::cout << "Инк решил не рисковать своей жизнью и остался жить в родной вселенной. Но он не стал счастлив. Он будет мучаться всю свою оставшуюся жизнь (то есть бесконечность).";
        break;
    default:
        std::cout << "У тебя есть только два выбора, ты не намерен больше бездействовать.";
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
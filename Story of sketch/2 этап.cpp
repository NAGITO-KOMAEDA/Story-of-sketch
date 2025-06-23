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
    std::cout << "Ты просыпаешься в каком-то месте.\n";
    std::cout << "Но где ты находишься?\n";
    std::cout << "Как ты здесь оказался?\n";
    std::cout << "А самое главное - кто ты вообще?\n";
    std::cout << "Осмотревшись вокруг, ты понимаешь, что находишься в какой-то пустоту светло-жёлтого цвета.\n";
    std::cout << "Твоё тело состоишь из костей белого цвета с какими-то чёрными отметинами\n";
    std::cout << "Но своего имени и судьбы ты не помнишь.\n";
    std::cout << "Что же случилось с тобой?\n";
    std::cout << "Ты решаешься пройтись по пустоте в поисках хотя бы чего-то.\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "Ты не знаешь сколько времени прошло с тех пор, как ты пошёл на поиски хотя бы чего-нибудь в этой пустоте.\n";
    std::cout << "Но ты ничего не нашёл.\n";
    std::cout << "Казалось бы, ты должен чувствовать расстройство, отчаяние, ну или хотя бы гнев.\n";
    std::cout << "Но ты не чувствуешь ничего.\n";
    std::cout << "Ты решил сесть на 'пол' и ждать какого-то чуда.\n";
    std::cout << "Может быть твоя память всё-таки вернётся к тебе.\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "Ты опять не знаешь сколько времени ты сидишь здесь, пока однажды на тебя не падает что-то жидкое.\n";
    std::cout << "Ты смотришь на это нечто жёлтого цвета и понимаешь, что это краска.\n";
    int decision = 0;
    while (decision != 2) {
        std::cout << "Что тебе стоит сделать?\n1.Осмотреть её\n2. Попробовать её на вкус\n";
        std::cin >> decision;
        switch (decision) {
        case 1:
            std::cout << "Это краска жёлтого цвета. Немного густая, по виду похоже на гуашь.\n";
            break;
        case 2:
            std::cout << "Ты решаешь попробовать краску на вкус.\n";
            std::cout << "Резко в тебе что-то меняется.\n";
            std::cout << "Ты начинаешь чувствовать...радость?\n";
            std::cout << "Это не имеет смысла, но ты так рад, что наконец-то что-то чувствуешь, что начинаешь плакать.\n";
            break;
        default:
            std::cout << "Что ты ещё собираешься делать с краской???\n";
            break;
        }
    }
    std::cout << "Твоей радости нет предела!\n";
    std::cout << "Но проходит какое-то время и ты снова не модешь чувствовать.\n";
    std::cout << "Ты снова потерял возможность чувствовать себя живым...\n";
    std::cout << "Ты снова садишься на 'пол' в ожидании очередной краски.\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "Проходит какое-то время, пока на тебя не падает очередная капля краски.\n";
    std::cout << "На этот раз это красная краска.\n";
    std::cout << "Спустя пару секунд тебя наполняет гнев.\n";
    std::cout << "Почему ты застрял в этом месте? Почему ты ничего не помнишь? ПОЧЕМУ ТЫ ОДИН?\n";
    std::cout << "И ты даже ничего не можешь сделать с этой ситуацией!\n";
    Sleep(2000);
    std::cout << "...\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "Когда ты успокоился, ты понимаешь, что каждая краска как-то действует на тебя, а именно вызывает эмоции.\n";
    std::cout << "И, действительно, это звучит логично, ведь у тебя нет души, как у обычных монстров.\n";
    std::cout << "Факт того, что ты жив без души, является удивительным сам по себе, так что ты можешь попробовать притворяться нормальным.\n";
    std::cout << "Стоит только дождаться всех красок.\n";
    Sleep(2000);
    std::cout << "...\n";
    std::cout << "Проходит ещё немного времени, и у тебя есть целая коллекция красок.\n";
    std::cout << "Ты наконец-то решаешься использовать краски, упавшие на тебя, по их предназначению.\n";
    std::cout << "И..вау!\n";
    std::cout << "С помощью красок ты можешь создават предметы.\n";
    std::cout << "Это довольно интересная способность.\n";
    std::vector<int> availableOptions = { 1, 2, 3, 4 };
    bool createdSomething = false;
    while (!createdSomething) {
        std::cout << "Что ты хочешь сделать с красками?\n";
        for (int option : availableOptions) {
            switch (option) {
            case 1: std::cout << "1. Изучить все краски\n"; break;
            case 2: std::cout << "2. Как-то попробовать собрать краски\n"; break;
            case 3: std::cout << "3. Нарисовать себе одежду\n"; break;
            case 4: std::cout << "4. Нарисовать что-нибудь в пустоте\n"; break;
            }
        }
        std::cin >> decision;
        auto it = std::find(availableOptions.begin(), availableOptions.end(), decision);
        if (it == availableOptions.end()) {
            std::cout << "Что ещё ты хочешь сделать с красками???\n";
            continue;
        }
        switch (decision) {
        case 1:
            std::cout << "Ты пытаешься вспомнить, что делает каждая краска.\n";
            std::cout << "Красная - гнев, оранжевая - удивление, жёлтая - радость, зелёная - отвращение, голубая - грусть, синяя - страх, фиолетовая - стыд, розовая - любовь.\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 1), availableOptions.end());
            break;
        case 2:
            std::cout << "Ты пытаешься собрать краски в импровизированную баночку...\n";
            std::cout << "Это работает! Теперь у тебя есть запас красок.\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 2), availableOptions.end());
            break;
        case 3:
            std::cout << "Ты рисуешь себе стильный костюм...\n";
            std::cout << "Теперь ты выглядишь менее голым.\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 3), availableOptions.end());
            break;
        case 4:
            std::cout << "Ты начинаешь рисовать в пустоте...\n";
            Sleep(2000);
            std::cout << "...\n";
            std::cout << "Постепенно появляется уютный сад!\n";
            availableOptions.erase(std::remove(availableOptions.begin(), availableOptions.end(), 4), availableOptions.end());
            break;
        default:
            std::cout << "Что ещё ты хочешь сделать с красками???\n";
            break;
        }
        if (availableOptions.size() == 0) {
            std::cout << "От скуки ты начинаешь рисовать в пустоте...\n";
            Sleep(2000);
            std::cout << "...\n";
            Sleep(2000);
            std::cout << "...\n";
            std::cout << "Постепенно появляется целый мир!\n";
            createdSomething = true;
        }
    }
    std::cout << "А ещё тебе удалось открыть тайну.\n";
    std::cout << "Здесь есть какие-то создатели, с которыми ты можешь общаться в своей голове.\n";
    std::cout << "Ну либо ты просто совсем сошёл с ума.\n";
    std::cout << "Краска, которая упала тогда на тебя, была от них.\n";
    std::cout << "Создатели говорят, что ты новый хранитель мультивселенных, что тебе нужно перейти в дудлсферу, где все они хранятся, ведь они в опасности.\n";
    std::cout << "Говорят, что ты должен как-то сделать портал.\n";
    std::cout << "Но всё что у тебя есть, так это краски и твоя собственная магия в виде чернил.\n";
    std::cout << "Возможно, если ты создашь огромную кисточку и нарисуешь лужу чернил на 'полу', то...\n";
    int confirm;
    std::cout << "Ты точно готов?\n1. Да\n";
    std::cin >> confirm;
    if (confirm == 1) {
        system("cls");
        system("color E0");
        thirdPlayGame();
    }
    else {
        std::cout << "На самом деле у тебя нет выбора!";
        Sleep(1000);
        system("cls");
        system("color E0");
        thirdPlayGame();
    }
}
#include "game_functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

int main() {
    setvbuf(stdin, nullptr, _IONBF, 0);
    setvbuf(stdout, nullptr, _IONBF, 0);
    srand(time(0));
    setlocale(LC_ALL, "Russian");

    play_game();
    return 0;
}
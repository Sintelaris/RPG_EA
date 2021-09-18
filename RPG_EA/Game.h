//
// Created by Sintelaris on 18.09.2021.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include <iostream>
#include "Map.h"
using namespace std;



class Game {
public:
    Game();
    int isRunning = 1;
    void menu();
    void game();
    void final_menu();
    void saveGame();
private:
    int win_or_lose;
    bool game_continue;
    Map field;
};



#endif //UNTITLED_GAME_H

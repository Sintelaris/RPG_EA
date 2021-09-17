//
// Created by Sintelaris on 15.09.2021.
//
#include "Map.cpp"
#include <iostream>
using namespace std;
#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

/*
class Game {
private:
    bool win_or_lose = 0;
    bool game_continue = 0;
public:
    int isRunning = 1;
    void menu(){
    };
    void game(){
    };
    void final_menu(){
    };

    Game(bool win_or_lose, bool game_continue, int isRunning) {
        this->win_or_lose = win_or_lose;
        this->game_continue = game_continue;
        this->isRunning = isRunning;
    }
};*/



#include "Game.h"

class Game {
private:
    bool win_or_lose;
    bool game_continue;
    Map field;
public:
    int isRunning = 1;
    void menu();
    void game();
    void final_menu();
    Game();

};



#endif //UNTITLED_GAME_H

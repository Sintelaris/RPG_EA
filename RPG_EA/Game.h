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
    bool win_or_lose = 0;
    bool game_continue = 0;
    Map field;
public:
    int isRunning = 1;
    void menu(){
        cout << "Run game? 2 for 'yes', 0 for 'no'"<< endl;
        cin >> isRunning;
        if (isRunning > 3 and isRunning < 0){
            isRunning = 1;
        }
    };
    void game(){
        field.walk;
    };
    void final_menu(){
        if (win_or_lose == 1){
            cout << "You won! New game?" << endl << "Type 1 if yes and 0 if no";
        }
        else {
            cout << "You lose! New game?))))" << endl << "Type 1 if yes and 0 if no";
        }
        cin >> game_continue;
        if (game_continue == 0){
            isRunning = 0;
        }
    };
    Game() {
        this->win_or_lose = 0;
        this->game_continue = 0;
        this->isRunning = 1;
    }
};



#endif //UNTITLED_GAME_H

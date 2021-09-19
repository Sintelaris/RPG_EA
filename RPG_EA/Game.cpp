//
// Created by Sintelaris on 18.09.2021.
//

#include "Game.h"
#include <iostream>


Game::Game() {
    int win_or_lose = 0;
    game_continue = 0;
    isRunning = 1;
}
void Game::menu(){
    cout << "Run game? 2 for 'yes', 0 for 'no'"<< endl;
    cin >> isRunning;
    if (isRunning > 3 || isRunning < 0){
        isRunning = 1;
    }
    cout << isRunning << endl;
};
void Game::game(){
    field.mapPrint();
    field.walk();
    field.walkEnemy();
    win_or_lose = field.Death_Checker();
    if (win_or_lose == 1 || win_or_lose == 2){
        isRunning = 3;
    }
};

void Game::final_menu(){
    if (win_or_lose == 2){
        cout << "You won! New game?" << endl << "Type 1 if yes and 0 if no" << endl;
    }
    else {
        cout << "You lose! New game?))))" << endl << "Type 1 if yes and 0 if no" << endl;
    }
    cin >> game_continue;
    if (game_continue == 0){
        isRunning = 0;
    }
    else {
        isRunning = 2;
        field.restart();
    }
}

void Game::saveGame() {
    field.saveStats();
}
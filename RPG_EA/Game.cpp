//
// Created by Sintelaris on 15.09.2021.
//

#include "Game.h"

void Game::menu(){
    cout << "Run game? 2 for 'yes', 0 for 'no'"<< endl;
    cin >> isRunning;
    if (isRunning > 3 and isRunning < 0){
        isRunning = 1;
    }
};
void Game::game(){
    field.walk;
};
void Game::final_menu(){
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
Game::Game() {
    field.createMap();
    this->win_or_lose = 0;
    this->game_continue = 0;
    this->isRunning = 1;
}

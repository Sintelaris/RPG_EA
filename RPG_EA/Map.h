//
// Created by Sintelaris on 16.09.2021.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H

#include "Character.cpp"
#include <ctime>


class Map {
private:
    Character Player;
    Character enemy1, enemy2, enemy3, enemy4, enemy5;
    bool checkerEnemy(int positionX, int positionY);
    string checkMove(Character player);
    char checkA(int X);
    char checkS(int Y);
    char checkD(int X);
    char checkW(int Y);
    void moveEnemy();
public:
    Map();
    int map[5][5];
    void walk(int (*arr)[5], Character current);
    void fill(int (*arr)[5], Character player);
    int random(int num);
    void move(char direction, Character Body);
};


#endif //UNTITLED_MAP_H

//
// Created by Sintelaris on 16.09.2021.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H

#include "Character.cpp"
#include <ctime>


class Map {
private:
    int X, Y;
    Character Player;
    bool checkerEnemy(int positionX, int positionY);
public:
    int map[5][5];
    void walk(int (*arr)[5]);
    void fill(int (*arr)[5], Character player);
    int random(int num);
    void move(char direction, Character Body);
};


#endif //UNTITLED_MAP_H

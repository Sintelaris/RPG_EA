//
// Created by Sintelaris on 18.09.2021.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H


#include "Character.h"
#include <ctime>


class Map {
private:
    Character Player;
    Character enemy1, enemy2, enemy3, enemy4, enemy5;
    bool checkerEnemy(int positionY, int positionX, int CharType);
    string checkMove(int navY, int navX);
    char checkA(int Y, int X);
    char checkS(int X, int Y);
    char checkD(int Y, int X);
    char checkW(int X, int Y);
    void AIwalk(Character *enemy);
    void Attack_enemy(int positionY, int positionX);
    void setPositions(int CharType, int navY, int navX, Character *current);
    void ifEmpty(int navY, int navX, int charType, Character *current);

    void addExperience(int add, bool kill);
    bool ifAlive(Character *current);
public:
    int Player_HP;
    void mapPrint();
    Map();
    int map[5][5]{};
    void walk();
    void walkEnemy();
    void fill();
    int random(int num);
    void move(char direction, Character *Body);
    void rest(Character *current);
    int Death_Checker();
    void saveStats();
    int Player_damage;
    void restart();
};


#endif //UNTITLED_MAP_H

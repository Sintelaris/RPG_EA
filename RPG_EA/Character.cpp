//
// Created by Sintelaris on 15.09.2021.
//

#include "Character.h"


Character::Character() {
    maxHP = 50;
    HP = maxHP;
    atk = 8;
    exp = 0;
    level = 0;
    CharType = 1;
    navX = 0;
    navY = 0;
}

Character::Character(int enemy, int Y, int X) {
    maxHP = 50;
    HP = maxHP;
    atk = 8;
    exp = 0;
    level = 0;
    CharType = enemy;
    navX = X;
    navY = Y;
}


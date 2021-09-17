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
}*/
void Character::setNavX(int navX) {
    this->navX = navX;
}

void Character::setNavY(int navY) {
    this->navY = navY;
}

void Character::setCharType(int type){
    CharType = type;
}

void Character::setMaxHp(int maxHp) {
    maxHP = maxHp;
}

void Character::setHp(int hp) {
    HP = hp;
}

int Character::getMaxHp() const {
    return maxHP;
}

int Character::getHp() const {
    return HP;
}




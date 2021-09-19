//
// Created by Sintelaris on 15.09.2021.
//

#include "Character.h"


Character::Character() {
    maxHP = 50;
    HP = maxHP;
    atk = 15;
    exp = 0;
    level = 0;
    CharType = 1;
    navX = 0;
    navY = 0;
    ifAlive = true;
    for (int i = 0; i < 3; i++){
        inventory[i].setItemConst("nothing");
    }
    loop_item_save = 0;
}
void Character::setName(const string &name) {
    Character::name = name;
}

void Character::setAtk(int atk) {
    Character::atk = atk;
}

void Character::setLevel(int level) {
    Character::level = level;
}

const string &Character::getName() const {
    return name;
}

int Character::getLevel() const {
    return level;
}

void Character::setExp(int exp) {
    Character::exp = exp;
}

int Character::getAtk() const {
    return atk;
}

/*Character::Character(int enemy) {
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

int Character::getExp() const {
    return exp;
}




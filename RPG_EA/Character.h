//
// Created by Sintelaris on 15.09.2021.
//

#ifndef UNTITLED_CHARACTER_H
#define UNTITLED_CHARACTER_H

#include <string>
#include <ctime>

using namespace std;

class Character {
public:
    int CharType;
    int navX, navY;

    Character();
    //Character(int enemy);

private:
    string name;
    int maxHP = 50, HP, atk = 5, exp = 0, level = 0;
public:
    int getMaxHp() const;

public:
    int getHp() const;

public:
    void setHp(int hp);

    void setMaxHp(int maxHp);

    void setNavX(int navX);

    void setNavY(int navY);

    void setCharType(int type);


};


#endif //UNTITLED_CHARACTER_H

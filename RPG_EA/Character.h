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
    Character(int enemy, int X, int Y);

private:
    string name;
    int maxHP, HP, atk, exp, level;

};


#endif //UNTITLED_CHARACTER_H

//
// Created by Sintelaris on 16.09.2021.
//

#include "Map.h"
#include <iostream>
using namespace std;
void Map::walk(int (*arr)[5]) {

    cout << "You can move, rest and attack.......";

}

void Map::fill(int (*arr)[5],Character player){
    arr[5][5] = 0;
    arr[player.navY][player.navX] = 1;

    Character enemy1(2,  random(4), random(4));
    int e2X = random(4), e2Y = random(4), e3X = random(4), e3Y = random(4), e4X = random(4), e4Y = random(4), e5X = random(4), e5Y = random(4);
    if (e2Y != enemy1.navY && e2X != enemy1.navX){
        Character enemy2(2, e2Y, e2X);
    } else {
        while ((e2Y == enemy1.navY && e2X == enemy1.navX)){
            e2Y = random(4);
        }
    }
    if ((e3Y != enemy1.navY && e3X != enemy1.navX) && (e3Y != e2Y && e3X != e2X)){
        Character enemy3(2, e3Y, e3X);
    } else {
        while ((e3Y == enemy1.navY && e3X == enemy1.navX) || (e3Y == e2Y && e3X == e2X)){
            e3Y = random(4);
        }
    }
    if ((e4Y != enemy1.navY && e4X != enemy1.navX) && (e4Y != e3Y && e4X != e3Y) && (e4Y != e2Y && e4X != e2X)){
        Character enemy4(2, e4Y, e4X);
    } else {
        while ((e4Y == enemy1.navY && e4X == enemy1.navX) || (e4Y == e3Y && e4X == e3Y) || (e4Y == e2Y && e4X == e2X))
        {
            e4Y = random(4);
            e4X = random(4);
        }
    }
    if ((e5Y != enemy1.navY && e5X != enemy1.navX) && (e5Y != e4Y && e5X != e4Y) && (e5Y != e3Y && e5X != e3Y) && (e5Y != e2Y && e5X != e2X)){
        Character enemy5(2, e5Y, e5X);
    } else {
        while ((e5Y == enemy1.navY && e5X == enemy1.navX) || (e5Y == e4Y && e5X == e4Y) || (e5Y == e3Y && e5X == e3Y) || (e5Y == e2Y && e5X == e2X))
        {
            e5Y = random(4);
            e5X = random(4);
        }
    }


};

bool Map::checkerEnemy(int positionX, int positionY){
    if (    (map[positionY][positionX] != map[positionY - 1][positionX - 1] and map[positionY - 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX] and map[positionY - 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX + 1] and map[positionY - 1][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX - 1] and map[positionY][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX + 1] and map[positionY][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX - 1] and map[positionY + 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX] and map[positionY + 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX + 1] and map[positionY + 1][positionX + 1] != 0))
        return false;
}

void Map::move(char direction, Character Body){
    switch(direction){
        case 'w': {
            map[Body.navY][Body.navX] = 0;
            map[Body.navY - 1][Body.navX] = Body.CharType;
        };
        case 'a':{
            map[Body.navY][Body.navX] = 0;
            map[Body.navY][Body.navX - 1] = Body.CharType;
        };
        case 's':{
            map[Body.navY][Body.navX] = 0;
            map[Body.navY + 1][Body.navX] = Body.CharType;
        };
        case 'd':{
            map[Body.navY][Body.navX] = 0;
            map[Body.navY][Body.navX + 1] = Body.CharType;
        };
    }
}

int Map::random(int num) {
    srand(time(NULL));
    return rand()%num;
}
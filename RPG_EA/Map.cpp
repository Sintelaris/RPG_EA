//
// Created by Sintelaris on 16.09.2021.
//

#include "Map.h"
#include <iostream>
#include <string>

using namespace std;
Map::Map() {
    map[5][5] = {0};
    fill(map, Player);
}
void Map::walk(int (*arr)[5], Character current) {
    cout << "You can move and rest. Input 'move' to select move direction, input 'rest' to heal yourself." << endl;
    string action;
    bool attack_availability = false;
    if(checkerEnemy(current.navY, current.navX)) {
        cout << "Enemy is near. You are also able to attack." << endl;
        attack_availability = true;
    }
    cin >> action;

    if (action.compare("move") == 0) {
        cout << "Input direction. 'w' to move up, 'a' to move left, 's' to move down, 'd' to move right." << endl;
        bool check = true;
        string Direction_available = checkMove(current); //WASD
        while (check) {
            char direction;
            cin >> direction;
            switch (direction) {
                case 'w':
                    if (Direction_available[0] == 'W') {
                        move('w', current);
                        check = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 'a':
                    if (Direction_available[0] == 'W') {
                        move('w', current);
                        check = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 's':
                    if (Direction_available[0] == 'W') {
                        move('w', current);
                        check = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 'd':
                    if (Direction_available[0] == 'W') {
                        move('w', current);
                        check = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                default: "This direction is not exist. Please try again."; break;
            }


        }
    }
    else if (action.compare("rest") == 0){
        int currentHP = current.getHp();
        int currentMaxHP = current.getMaxHp();
        if (currentHP < currentMaxHP){
            current.setHp(currentHP+5);
        }
        if (current.getHp() > current.getMaxHp()){
            current.setHp(current.getMaxHp());
            cout << "Health restored fully." << endl;
        }
        cout << "Current health: " << current.getHp() << " hp." << endl;
    }
    else if (action.compare("attack") == 0) {
        if (attack_availability == false){
            cout << "You are unable to attack." << endl;
        }
        else {
            cout << "Select attack direction." << endl << "'w' to attack up, 'a' to attack left, 's' to attack down, 'd' to attack right." << endl << "'q' to attack up-left, 'a' to attack left, 's' to attack down, 'd' to attack right." << endl;

        }
    }

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
            (map[positionY][positionX] != map[positionY + 1][positionX + 1] and map[positionY + 1][positionX + 1] != 0)
            )*/
    if ((map[positionY][positionX] != map[positionY - 1][positionX] and map[positionY - 1][positionX] != 0) and
        (map[positionY][positionX] != map[positionY][positionX - 1] and map[positionY][positionX - 1] != 0) and
        (map[positionY][positionX] != map[positionY][positionX + 1] and map[positionY][positionX + 1] != 0) and
        (map[positionY][positionX] != map[positionY + 1][positionX] and map[positionY + 1][positionX] != 0))
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
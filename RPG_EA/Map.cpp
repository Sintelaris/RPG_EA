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
        bool check_move = true;
        string Direction_available = checkMove(current); //WASD
        while (check_move) {
            char direction;
            cin >> direction;
            switch (direction) {
                case 'w':
                    if (Direction_available[0] == 'W') {
                        move('w', current);

                        check_move = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 'a':
                    if (Direction_available[1] == 'A') {
                        move('a', current);
                        check_move = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 's':
                    if (Direction_available[2] == 'S') {
                        move('s', current);
                        check_move = false;
                    }
                    else {
                        cout << "this direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 'd':
                    if (Direction_available[3] == 'D') {
                        move('d', current);
                        check_move = false;
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
            cout << "Select attack direction." << endl << "'w' to attack up, 'a' to attack left, 's' to attack down, 'd' to attack right." << endl;
            cout << "'q' to attack up-left, 'e' to attack up-right, 'z' to attack down-left, 'd' to attack down-right." << endl;
            char Attack_direction;
            cin >> Attack_direction;
            switch(Attack_direction){
                case 'w': Attack_enemy(Player.navY - 1 , Player.navX + 0); break;
                case 'a': Attack_enemy(Player.navY + 0, Player.navX - 1); break;
                case 's': Attack_enemy(Player.navY + 1, Player.navX + 0); break;
                case 'd': Attack_enemy(Player.navY + 0, Player.navX + 1); break;
                case 'q': Attack_enemy(Player.navY - 1, Player.navX - 1); break;
                case 'e': Attack_enemy(Player.navY - 1, Player.navX + 1); break;
                case 'z': Attack_enemy(Player.navY + 1, Player.navX - 1); break;
                case 'c': Attack_enemy(Player.navY + 1, Player.navX + 1); break;
            }
        }
    }

}
void Map::add_Experience(int add_exp){
    Player.setExp(Player.getExp() + add_exp);
    int previous_level = Player.getLevel();
};
void Map::fill(int (*arr)[5],Character player){
    arr[player.navY][player.navX] = 1;
    enemy1.setCharType(2);
    enemy1.setNavY(random(4)); enemy1.setNavX(random(4));
    arr[enemy1.navY][enemy1.navX] = 2;
    int e2X = random(4), e2Y = random(4), e3X = random(4), e3Y = random(4), e4X = random(4), e4Y = random(4), e5X = random(4), e5Y = random(4);
    if (e2Y != enemy1.navY && e2X != enemy1.navX){
        enemy2.setCharType(2);
        enemy2.setNavY(random(4)); enemy1.setNavX(random(4));
        arr[enemy2.navY][enemy2.navX] = 2;
    } else {
        while ((e2Y == enemy1.navY && e2X == enemy1.navX)){
            e2Y = random(4);
        }
        enemy2.setCharType(2);
        enemy2.setNavY(random(4)); enemy1.setNavX(random(4));
        arr[enemy2.navY][enemy2.navX] = 2;
    }
    if ((e3Y != enemy1.navY && e3X != enemy1.navX) && (e3Y != e2Y && e3X != e2X)){
        enemy3.setCharType(2);
        enemy3.setNavY(random(4)); enemy1.setNavX(random(4));
        arr[enemy3.navY][enemy3.navX] = 2;
    } else {
        while ((e3Y == enemy1.navY && e3X == enemy1.navX) || (e3Y == e2Y && e3X == e2X)){
            e3Y = random(4);
        }
        enemy3.setCharType(2);
        enemy3.setNavY(random(4)); enemy1.setNavX(random(4));
        arr[enemy3.navY][enemy3.navX] = 2;
    }
    if ((e4Y != enemy1.navY && e4X != enemy1.navX) && (e4Y != e3Y && e4X != e3Y) && (e4Y != e2Y && e4X != e2X)){
        enemy4.setCharType(2);
        enemy4.setNavY(random(4)); enemy1.setNavX(random(4));
        arr[enemy4.navY][enemy4.navX] = 2;
    } else {
        while ((e4Y == enemy1.navY && e4X == enemy1.navX) || (e4Y == e3Y && e4X == e3Y) || (e4Y == e2Y && e4X == e2X))
        {
            e4Y = random(4);
            e4X = random(4);
        }
        enemy4.setCharType(2);
        enemy4.setNavY(random(4)); enemy1.setNavX(random(4));
        arr[enemy4.navY][enemy4.navX] = 2;
    }
    if ((e5Y != enemy1.navY && e5X != enemy1.navX) && (e5Y != e4Y && e5X != e4Y) && (e5Y != e3Y && e5X != e3Y) && (e5Y != e2Y && e5X != e2X)){
        enemy5.setCharType(2);
        enemy5.setNavY(random(4)); enemy1.setNavX(random(4));
    } else {
        while ((e5Y == enemy1.navY && e5X == enemy1.navX) || (e5Y == e4Y && e5X == e4Y) || (e5Y == e3Y && e5X == e3Y) || (e5Y == e2Y && e5X == e2X))
        {
            e5Y = random(4);
            e5X = random(4);
        }
    }

};

bool Map::checkerEnemy(int positionY, int positionX){
    /*if (    (map[positionY][positionX] != map[positionY - 1][positionX - 1] and map[positionY - 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX] and map[positionY - 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX + 1] and map[positionY - 1][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX - 1] and map[positionY][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX + 1] and map[positionY][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX - 1] and map[positionY + 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX] and map[positionY + 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX + 1] and map[positionY + 1][positionX + 1] != 0)
            )*/
    if ((map[positionY][positionX] != map[positionY - 1][positionX] and map[positionY - 1][positionX] != 0) or
        (map[positionY][positionX] != map[positionY][positionX - 1] and map[positionY][positionX - 1] != 0) or
        (map[positionY][positionX] != map[positionY][positionX + 1] and map[positionY][positionX + 1] != 0) or
        (map[positionY][positionX] != map[positionY + 1][positionX] and map[positionY + 1][positionX] != 0))
        return true;
    else return false;
}

string Map::checkMove(Character player){
    string checker;
    checker = checkW(player.navX);
    checker += checkA(player.navY);
    checker += checkS(player.navX);
    checker += checkD(player.navY);
    return checker;
}
char Map::checkW(int X) {
    if (X != 0){
        return 'W';
    } else {
        return '0';
    }
}
char Map::checkA(int Y){
    if (Y != 0) {
        return 'A';
    } else{
        return '0';
    }
}
char Map::checkS(int X){
    if (X != 4) {
        return 'S';
    } else{
        return '0';
    }
}
char Map::checkD(int Y){
    if (Y != 4) {
        return 'D';
    } else{
        return '0';
    }
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
void Map::moveEnemy(){

};
int Map::random(int num) {
    srand(time(NULL));
    return rand()%num;
}
void Map::Attack_enemy(int positionY, int positionX){
    if (enemy1.navY == positionY and enemy1.navX == positionX){
        enemy1.setHp(enemy1.getHp() - Player.getAtk());
    }
    else if (enemy2.navY == positionY and enemy2.navX == positionX){
        enemy2.setHp(enemy2.getHp() - Player.getAtk());
    }
    else if (enemy3.navY == positionY and enemy3.navX == positionX){
        enemy3.setHp(enemy3.getHp() - Player.getAtk());
    }
    else if (enemy4.navY == positionY and enemy4.navX == positionX){
        enemy4.setHp(enemy4.getHp() - Player.getAtk());
    }
    else if (enemy5.navY == positionY and enemy5.navX == positionX){
        enemy5.setHp(enemy5.getHp() - Player.getAtk());
    }
    else cout << "Miss!";
};
void Map::rest(Character current){
    if (current.getHp() < current.getMaxHp()){
        current.setHp(current.getHp()+5);
    }
    if (current.getHp() > current.getMaxHp()){
        current.setHp(current.getMaxHp());
    }
};
void Map::explore(Character current) {

}

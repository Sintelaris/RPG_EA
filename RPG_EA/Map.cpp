//
// Created by Sintelaris on 18.09.2021.
//

#include "Map.h"

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>


using namespace std;
Map::Map() {
    map[4][4] = {0};
    fill();
}

void Map::mapPrint() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Player HP: " << Player.getHp() << " Position: " << Player.navX << " " << Player.navY << endl;
    cout << "Player level: " << Player.getLevel() << endl;
    cout << "Player damage: " << Player.getAtk() << endl;
    cout << "Player experience: " << Player.getExp() << endl;
    cout << "Player MaxHP: " << Player.getMaxHp() << endl;

    cout << "Enemy1 HP: " << enemy1.getHp() << " Position: " << enemy1.navX << " " << enemy1.navY << endl;
    cout << "Enemy2 HP: " << enemy2.getHp() << " Position: " << enemy2.navX << " " << enemy2.navY << endl;
    cout << "Enemy3 HP: " << enemy3.getHp() << " Position: " << enemy3.navX << " " << enemy3.navY << endl;
    cout << "Enemy4 HP: " << enemy4.getHp() << " Position: " << enemy4.navX << " " << enemy4.navY << endl;
    cout << "Enemy5 HP: " << enemy5.getHp() << " Position: " << enemy5.navX << " " << enemy5.navY << endl;
}
void Map::addExperience(int add){
    int currentExp = Player.getExp();
    Player.setExp(add + Player.inventory[0].exp_Bonus + Player.inventory[1].exp_Bonus + Player.inventory[2].exp_Bonus);
    int currentLevel = Player.getLevel();
    currentExp = Player.getExp();
    Player.setLevel(currentExp/30);
    int currentAtk = Player.getAtk();
    int currentMaxHp = Player.getMaxHp();
    //int currentHp = Player.getHp();
    Player.setMaxHp(currentLevel * 2 + 50 + Player.inventory[0].maxHP_bonus + Player.inventory[1].maxHP_bonus + Player.inventory[2].maxHP_bonus);
    Player.setAtk(currentLevel * 1 + 8 + Player.inventory[0].damage_bonus + Player.inventory[1].damage_bonus + Player.inventory[2].damage_bonus);
}

void Map::walk() {
    cout << "You can move and rest. Input 'move' to select move direction, input 'rest' to heal yourself." << endl;
    string action;
    bool attack_availability = false;
    if(checkerEnemy(Player.navY, Player.navX, Player.CharType)) {
        cout << "Enemy is near. You are also able to attack. Input 'attack' to attack." << endl;
        attack_availability = true;
    }
    cin >> action;

    if (action.compare("move") == 0) {
        cout << "Input direction. 'w' to move up, 'a' to move left, 's' to move down, 'd' to move right." << endl;
        bool check_move = true;
        string Direction_available = checkMove(Player.navY, Player.navX); //WASD
        cout << Direction_available << endl;
        while (check_move) {
            char direction;
            cin >> direction;
            switch (direction) {
                case 'w':
                    if (Direction_available[0] == 'W') {
                        move('w', &Player);

                        check_move = false;
                    }
                    else {
                        cout << "This direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 'a':
                    if (Direction_available[1] == 'A') {
                        move('a', &Player);
                        check_move = false;
                    }
                    else {
                        cout << "This direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 's':
                    if (Direction_available[2] == 'S') {
                        move('s', &Player);
                        check_move = false;
                    }
                    else {
                        cout << "This direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                case 'd':
                    if (Direction_available[3] == 'D') {
                        move('d', &Player);
                        check_move = false;
                    }
                    else {
                        cout << "This direction is not available. Enemy or end of the map placed here." << endl;
                    };
                    break;
                default: cout << "This direction is not exist. Please try again."; break;
            }
        }
        addExperience(5);
    }
    else if (action.compare("rest") == 0){
        int currentHP = Player.getHp();
        int currentMaxHP = Player.getMaxHp();
        if (currentHP <= currentMaxHP){
            Player.setHp(currentHP+5);
        }
        if (Player.getHp() > Player.getMaxHp()){
            Player.setHp(Player.getMaxHp());
            cout << "Health restored fully." << endl;
        }
        cout << "Current health: " << Player.getHp() << " hp." << endl;
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

void Map::ifEmpty(int navY, int navX, int charType, Character *current) {
    if (map[navY][navX] == 0){
        setPositions(charType, navY, navX, current);
    } else {
        while (map[navY][navX] != 0){
            navY = random(4);
            navX = random(4);
        }
        setPositions(charType, navY, navX, current);
    }
}
void Map::setPositions(int CharType, int navY, int navX, Character *current) {
    current->setCharType(CharType);
    current->setNavY(navY); current->setNavX(navX);
    map[current->navY][current->navX] = CharType;
}
void Map::fill(){
    int e1Y = random(4), e1X = random(4), e2X = random(4), e2Y = random(4), e3X = random(4), e3Y = random(4), e4X = random(4), e4Y = random(4), e5X = random(4), e5Y = random(4);
    int plY = random(4), plX = random(4);
    setPositions(2, e1Y, e1X, &enemy1);
    ifEmpty(e2Y, e2X, 2, &enemy2);
    ifEmpty(e3Y, e3X, 2, &enemy3);
    ifEmpty(e4Y, e4X, 2, &enemy4);
    ifEmpty(e5Y, e5X, 2, &enemy5);
    ifEmpty(plY, plX, 1, &Player);
}

bool Map::checkerEnemy(int positionY, int positionX, int CharType) {
    /*if (    (map[positionY][positionX] != map[positionY - 1][positionX - 1] and map[positionY - 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX] and map[positionY - 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX + 1] and map[positionY - 1][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX - 1] and map[positionY][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX + 1] and map[positionY][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX - 1] and map[positionY + 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX] and map[positionY + 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX + 1] and map[positionY + 1][positionX + 1] != 0)
            )*/

    if ((CharType != map[positionY - 1][positionX] && map[positionY - 1][positionX] != 0) ||
        (CharType != map[positionY][positionX - 1] && map[positionY][positionX - 1] != 0) ||
        (CharType != map[positionY][positionX + 1] && map[positionY][positionX + 1] != 0) ||
        (CharType != map[positionY + 1][positionX] && map[positionY + 1][positionX] != 0))
        return true;
    else return false;
}

string Map::checkMove(int navY, int navX){
    string checker;
    checker = checkW(navY, navX);
    checker += checkA(navX, navY);
    checker += checkS(navY, navX);
    checker += checkD(navX, navY);
    return checker;
}
char Map::checkW(int Y, int X) {
    if (Y != 0){
        if (map[Y-1][X] != 0) {
            return '0';
        }
        return 'W';
    }
    else {
        return '0';
    }
}
char Map::checkA(int X, int Y){
    if (X != 0) {
        if (map[Y][X-1] != 0) {
            return '0';
        }
        return 'A';
    }
    else{
        return '0';
    }
}
char Map::checkS(int Y, int X){
    if (Y != 4) {
        if (map[Y+1][X] != 0) {
            return '0';
        }
        return 'S';
    }
    else{
        return '0';
    }
}
char Map::checkD(int X, int Y){
    if (X != 4) {
        if (map[Y][X+1] != 0) {
            return '0';
        }
        return 'D';
    }
    else{
        return '0';
    }
}

void Map::move(char direction, Character *Body){
    switch(direction){
        case 'w': {
            map[Body->navY][Body->navX] = 0;
            map[Body->navY - 1][Body->navX] = Body->CharType;
            Body->setNavY(Body->navY - 1);
            break;
        }
        case 'a':{
            map[Body->navY][Body->navX] = 0;
            map[Body->navY][Body->navX - 1] = Body->CharType;
            Body->setNavX(Body->navX - 1);
            break;
        }
        case 's':{
            map[Body->navY][Body->navX] = 0;
            map[Body->navY + 1][Body->navX] = Body->CharType;
            Body->setNavY(Body->navY + 1);
            break;
        }
        case 'd':{
            map[Body->navY][Body->navX] = 0;
            map[Body->navY][Body->navX + 1] = Body->CharType;
            Body->setNavX(Body->navX + 1);
            break;
        }
    }
}
void Map::AIwalk(Character *enemy){
    string directionAV = checkMove(enemy->navY, enemy->navX);
    int choice;
    if (checkerEnemy(enemy->navY, enemy->navX, enemy->CharType)){
        choice = random(2);
        if (enemy->getHp() < 20){
            if (enemy->getHp() < enemy->getMaxHp()){
                enemy->setHp(enemy->getHp()+5);
            }
            if (enemy->getHp() > enemy->getMaxHp()){
                enemy->setHp(enemy->getMaxHp());
            }
        } else{
            switch (choice) {
                case 0:
                    cout << "\nYou've been attacked by ENEMY that locates at " << enemy->navX << " " << enemy->navY << endl;
                    Player.setHp(Player.getHp() - enemy->getAtk());
                    cout << "Your current HP is " << Player.getHp() << endl;
                    break;
                case 1:{
                    int i = 0;
                    while (directionAV[i] == '0'){
                        i++;
                    }
                    cout << enemy->navX << " " << enemy->navY << " has moved";
                    move(tolower(directionAV[i]), enemy);
                    cout << " to " << enemy->navX << " " << enemy->navY << endl;
                    break;
                }

                case 2:
                {
                    if (enemy->getHp() < enemy->getMaxHp()){
                        enemy->setHp(enemy->getHp()+5);
                    }
                    if (enemy->getHp() > enemy->getMaxHp()){
                        enemy->setHp(enemy->getMaxHp());
                    }
                    cout << enemy->navX << " " << enemy->navY << " has rest" << endl;
                    break;
                }
            }
        }

    }
    else {
        choice = random(1);
        switch (choice) {
            case 0:
            {
                int i = 0;
                while (directionAV[i] == '0'){
                    i++;
                }
                cout << enemy->navX << " " << enemy->navY << " has moved";
                move(tolower(directionAV[i]), enemy);
                cout << " to " << enemy->navX << " " << enemy->navY << endl;
                break;
            }

            case 1: {
                rest(enemy);
                cout << enemy->navX << " " << enemy->navY << " has rest" << endl;
                break;
            }
        }
    }


}
void Map::walkEnemy() {
    AIwalk(&enemy1);
    AIwalk(&enemy2);
    AIwalk(&enemy3);
    AIwalk(&enemy4);
    AIwalk(&enemy5);
}
int Map::random(int num) {
    srand(time(NULL));
    return rand() % num;
}
void Map::Attack_enemy(int positionY, int positionX){
    if (enemy1.navY == positionY && enemy1.navX == positionX){
        enemy1.setHp(enemy1.getHp() - Player.getAtk());
    }
    else if (enemy2.navY == positionY && enemy2.navX == positionX){
        enemy2.setHp(enemy2.getHp() - Player.getAtk());
    }
    else if (enemy3.navY == positionY && enemy3.navX == positionX){
        enemy3.setHp(enemy3.getHp() - Player.getAtk());
    }
    else if (enemy4.navY == positionY && enemy4.navX == positionX){
        enemy4.setHp(enemy4.getHp() - Player.getAtk());
    }
    else if (enemy5.navY == positionY && enemy5.navX == positionX){
        enemy5.setHp(enemy5.getHp() - Player.getAtk());
    }
    else cout << "Miss!";

};
void Map::rest(Character *current){
    if (current->getHp() < current->getMaxHp()){
        current->setHp(current->getHp()+5);
    }
    if (current->getHp() > current->getMaxHp()){
        current->setHp(current->getMaxHp());
    }
}



bool Map::ifAlive(Character *current){
    if (current->getHp() <= 0){
        if(current->ifAlive){
            current->setHp(0);
            addExperience(50);
            map[current->navY][current->navX] = 0;
            current->ifAlive = false;
        }
    }
    return current->ifAlive;
}

int Map::Death_Checker(){
    bool enemy1_alive = ifAlive(&enemy1);
    bool enemy2_alive = ifAlive(&enemy2);
    bool enemy3_alive = ifAlive(&enemy3);
    bool enemy4_alive = ifAlive(&enemy4);
    bool enemy5_alive = ifAlive(&enemy5);
    bool lose = ifAlive(&Player);
    if (enemy1_alive == false && enemy2_alive == false && enemy3_alive == false && enemy4_alive == false && enemy5_alive == false){
        return 2;
    }
    if (lose == false){
        return 1;
    }
    return 0;
}

void Map::saveStats() {
    ofstream gamefile ("SaveGame.txt");
}























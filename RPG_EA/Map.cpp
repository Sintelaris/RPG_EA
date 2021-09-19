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
    Player_HP = 50;
    Player_damage = 20;
    map[4][4] = {0};
    fill();
    Player.setAtk(Player_damage);
    Player.setHp(Player_HP);
}
void Map::mapPrint() { //prints the map and current stats
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl << "Player HP: " << Player.getHp() << " Position: " << Player.navX << " " << Player.navY << endl;
    cout << "Player level: " << Player.getLevel() << endl;
    cout << "Player damage: " << Player.getAtk() + Player.inventory[0].damage_bonus + Player.inventory[1].damage_bonus + Player.inventory[2].damage_bonus << endl;
    cout << "Player experience: " << Player.getExp() << endl;
    cout << "Player MaxHP: " << Player.getMaxHp() + Player.inventory[0].maxHP_bonus + Player.inventory[1].maxHP_bonus + Player.inventory[2].maxHP_bonus << endl;
    cout << "Player inventory: " << endl;
    cout << "Player Item 1: " << Player.inventory[0].type << endl;
    cout << "Player Item 2: " << Player.inventory[1].type << endl;
    cout << "Player Item 3: " << Player.inventory[2].type << endl << endl;

    cout << "Enemy1 HP: " << enemy1.getHp() << " Position: " << enemy1.navX << " " << enemy1.navY << endl;
    cout << "Enemy2 HP: " << enemy2.getHp() << " Position: " << enemy2.navX << " " << enemy2.navY << endl;
    cout << "Enemy3 HP: " << enemy3.getHp() << " Position: " << enemy3.navX << " " << enemy3.navY << endl;
    cout << "Enemy4 HP: " << enemy4.getHp() << " Position: " << enemy4.navX << " " << enemy4.navY << endl;
    cout << "Enemy5 HP: " << enemy5.getHp() << " Position: " << enemy5.navX << " " << enemy5.navY << endl;
}
void Map::addExperience(int add, bool kill){ //adding experience when moving and killing
    if (kill){
        Player.inventory[Player.loop_item_save].setItemConst(Player.inventory[Player.loop_item_save].Types_of_items[random(9)]);
        Player.loop_item_save++;
        Player.loop_item_save = Player.loop_item_save % 3;
    }

    int currentExp = Player.getExp();
    Player.setExp(currentExp + add + Player.inventory[0].exp_Bonus + Player.inventory[1].exp_Bonus + Player.inventory[2].exp_Bonus);

    currentExp = Player.getExp();
    Player.setLevel(currentExp/30);
    int currentLevel = Player.getLevel();
    int currentAtk = Player.getAtk();
    int currentMaxHp = Player.getMaxHp();
    //int currentHp = Player.getHp();
    Player.setMaxHp(currentLevel * 2 + 50 /*+ Player.inventory[0].maxHP_bonus + Player.inventory[1].maxHP_bonus + Player.inventory[2].maxHP_bonus*/);
    Player.setAtk((currentLevel * 1) + Player_damage /*+ Player.inventory[0].damage_bonus + Player.inventory[1].damage_bonus + Player.inventory[2].damage_bonus*/);
}

void Map::walk() { //implements all three actions of the player
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
        addExperience(5, false);
    }
    else if (action.compare("rest") == 0){
        int currentHP = Player.getHp();
        int currentMaxHP = Player.getMaxHp();
        if (currentHP <= currentMaxHP){
            Player.setHp(currentHP + 5 + Player.inventory[0].rest_bonus + Player.inventory[1].rest_bonus + Player.inventory[2].rest_bonus);
        }
        if (Player.getHp() > Player.getMaxHp() + Player.inventory[0].maxHP_bonus + Player.inventory[1].maxHP_bonus + Player.inventory[2].maxHP_bonus){
            Player.setHp(Player.getMaxHp() + Player.inventory[0].maxHP_bonus + Player.inventory[1].maxHP_bonus + Player.inventory[2].maxHP_bonus);
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
           // cout << "'q' to attack up-left, 'e' to attack up-right, 'z' to attack down-left, 'd' to attack down-right." << endl;
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

void Map::ifEmpty(int navY, int navX, int charType, Character *current) { //checks if the specific coordinate is empty
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
void Map::setPositions(int CharType, int navY, int navX, Character *current) { //assigns the coordinates to character
    current->setCharType(CharType);
    current->setNavY(navY); current->setNavX(navX);
    map[current->navY][current->navX] = CharType;
}
void Map::fill(){ //fills the map of the game
    int e1Y = random(4), e1X = random(4), e2X = random(4), e2Y = random(4), e3X = random(4), e3Y = random(4), e4X = random(4), e4Y = random(4), e5X = random(4), e5Y = random(4);
    int plY = random(4), plX = random(4);
    setPositions(2, e1Y, e1X, &enemy1);
    ifEmpty(e2Y, e2X, 2, &enemy2);
    ifEmpty(e3Y, e3X, 2, &enemy3);
    ifEmpty(e4Y, e4X, 2, &enemy4);
    ifEmpty(e5Y, e5X, 2, &enemy5);
    ifEmpty(plY, plX, 1, &Player);
}

bool Map::checkerEnemy(int positionY, int positionX, int CharType) { //checks if there is any rival nearby
    /*if (    (map[positionY][positionX] != map[positionY - 1][positionX - 1] and map[positionY - 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX] and map[positionY - 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY - 1][positionX + 1] and map[positionY - 1][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX - 1] and map[positionY][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY][positionX + 1] and map[positionY][positionX + 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX - 1] and map[positionY + 1][positionX - 1] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX] and map[positionY + 1][positionX] != 0) and
            (map[positionY][positionX] != map[positionY + 1][positionX + 1] and map[positionY + 1][positionX + 1] != 0)
            )*/

    if ((positionY != 0 && CharType != map[positionY - 1][positionX] && map[positionY - 1][positionX] != 0) ||
        (positionX != 0 && CharType != map[positionY][positionX - 1] && map[positionY][positionX - 1] != 0) ||
        (positionX != 4 && CharType != map[positionY][positionX + 1] && map[positionY][positionX + 1] != 0) ||
        (positionY != 4 && CharType != map[positionY + 1][positionX] && map[positionY + 1][positionX] != 0))
        return true;
    else return false;
}

string Map::checkMove(int navY, int navX){ //checks the possibility to move to the 4 directions
    string checker;
    checker = checkW(navY, navX);
    checker += checkA(navX, navY);
    checker += checkS(navY, navX);
    checker += checkD(navX, navY);
    return checker;
}
char Map::checkW(int Y, int X) { //checks the up cell
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
char Map::checkA(int X, int Y){ //checks the left cell
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
char Map::checkS(int Y, int X){ //checks the right  cell
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
char Map::checkD(int X, int Y){ //checks the down cell
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

void Map::move(char direction, Character *Body){ //moves the character to the specific direction
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
void Map::AIwalk(Character *enemy){ //implements AI actions
    string directionAV = checkMove(enemy->navY, enemy->navX);
    int choice;
    if (checkerEnemy(enemy->navY, enemy->navX, enemy->CharType)){
        choice = random(2);
        if (enemy->getHp() < 15){
            if (enemy->getHp() <= 0){
                return;
            }
            if (enemy->getHp() < enemy->getMaxHp()){
                enemy->setHp(enemy->getHp()+5);
            }
            if (enemy->getHp() > enemy->getMaxHp()){
                enemy->setHp(enemy->getMaxHp());
            }
            cout << enemy->navX << " " << enemy->navY << " has rest" << endl;
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
        if (enemy->getHp() < 15){
            if (enemy->getHp() <= 0){
                return;
            }
            if (enemy->getHp() < enemy->getMaxHp()){
                enemy->setHp(enemy->getHp()+5);
            }
            if (enemy->getHp() > enemy->getMaxHp()){
                enemy->setHp(enemy->getMaxHp());
            }
            cout << enemy->navX << " " << enemy->navY << " has rest" << endl;
        }
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
void Map::walkEnemy() { //implements all moves of all enemies
    AIwalk(&enemy1);
    AIwalk(&enemy2);
    AIwalk(&enemy3);
    AIwalk(&enemy4);
    AIwalk(&enemy5);
}
int Map::random(int num) { //returns the random number in the given rank
    srand(time(NULL));
    return rand() % num;
}
void Map::Attack_enemy(int positionY, int positionX){ //implements attack to the enemy by coordinates
    int plAt = Player.getAtk() + Player.inventory[0].damage_bonus + Player.inventory[1].damage_bonus + Player.inventory[2].damage_bonus;
    cout << "player attack is " << plAt <<endl;
    if (enemy1.navY == positionY && enemy1.navX == positionX){
        enemy1.setHp(enemy1.getHp() - plAt);
    }
    else if (enemy2.navY == positionY && enemy2.navX == positionX){
        enemy2.setHp(enemy2.getHp() - plAt);
    }
    else if (enemy3.navY == positionY && enemy3.navX == positionX){
        enemy3.setHp(enemy3.getHp() - plAt);
    }
    else if (enemy4.navY == positionY && enemy4.navX == positionX){
        enemy4.setHp(enemy4.getHp() - plAt);
    }
    else if (enemy5.navY == positionY && enemy5.navX == positionX){
        enemy5.setHp(enemy5.getHp() - plAt);
    }
    else cout << "Miss!";

};
void Map::rest(Character *current){ //implements the rest action by increasing the HP
    if (current->getHp() < current->getMaxHp()){
        current->setHp(current->getHp()+5);
    }
    if (current->getHp() > current->getMaxHp()){
        current->setHp(current->getMaxHp());
    }
}



bool Map::ifAlive(Character *current){ //checks if the character is alive
    if (current->getHp() <= 0){
        if(current->ifAlive){
            current->setHp(0);
            addExperience(50, true);
            map[current->navY][current->navX] = 0;
            current->ifAlive = false;
            current->setNavY(-1); current->setNavX(-1);
        }
    }
    return current->ifAlive;
}

int Map::Death_Checker(){ //checks all characters for aliveness
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
void Map::resetEnemy(Character *enemy){
    enemy->setMaxHp(50); enemy->setHp(enemy->getMaxHp());
    enemy->setAtk(15);
    enemy->setExp(0); enemy->setLevel(0);
    enemy->ifAlive = true;
}
void Map::restart(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            map[i][j] = 0;
    }
    resetEnemy(&enemy1);
    resetEnemy(&enemy2);
    resetEnemy(&enemy3);
    resetEnemy(&enemy4);
    resetEnemy(&enemy5);
    Player.setAtk(Player_damage);
    Player.setHp(Player_HP);
    Player.setMaxHp(Player_HP);
    Player.setLevel(0);
    Player.ifAlive = true;
    Player.setExp(0);
    Player.setLevel(0);
    Player.inventory[0].setItemConst("nothing");
    Player.inventory[1].setItemConst("nothing");
    Player.inventory[2].setItemConst("nothing");

    fill();
}























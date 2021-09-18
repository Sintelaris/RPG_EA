//
// Created by Sintelaris on 18.09.2021.
//

#include "Item.h"
#include <string>
using namespace std;
Item::Item(){

    damage_bonus = 0;
    maxHP_bonus = 0;
    rest_bonus = 0;
    exp_Bonus = 0;
    type = "nothing";
}
void Item::setItemConst(string type) {
    if (type.compare("Sword") == 0){
        damage_bonus = 5;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare("Shield")  == 0){
        damage_bonus = 0;
        maxHP_bonus = 10;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare("Bloodshield")  == 0){
        damage_bonus = 0;
        maxHP_bonus = 50;
        rest_bonus = -2;
        exp_Bonus = -1;
    }
    else if (type.compare("Eye of Ktulkhu")  == 0){
        damage_bonus = 10;
        maxHP_bonus = 10;
        rest_bonus = -2;
        exp_Bonus = 0;
    }
    else if (type.compare("Star ring")  == 0){
        damage_bonus = 0;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 5;
    }
    else if (type.compare("Ring of power")  == 0){
        damage_bonus = 30;
        maxHP_bonus = -30;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare("Soulbreaker") == 0){
        damage_bonus = 1000;
        maxHP_bonus = -10;
        rest_bonus = -100000;
        exp_Bonus = -10;
    }
    else{
        damage_bonus = 0;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
        }


        this->type = type;
}

/*
Item::Item(string type) {
    if (type.compare("Sword of power")){
        damage_bonus = 15;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare("Bloodshield")){
        damage_bonus = 0;
        maxHP_bonus = 30;
        rest_bonus = -5;
        exp_Bonus = 0;
    }
    else if (type.compare("Eye of Ktulkhu")){
        damage_bonus = 10;
        maxHP_bonus = 10;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare("Star ring")){
        damage_bonus = 0;
        maxHP_bonus = 15;
        rest_bonus = -5;
        exp_Bonus = 0;
    }
    else if (type.compare("Ring of power")){
        damage_bonus = 30;
        maxHP_bonus = -30;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare("Soulbreaker")){
        damage_bonus = 1000;
        maxHP_bonus = -10;
        rest_bonus = -100000;
        exp_Bonus = -10;
    }
    else{
        damage_bonus = 0;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
    //}


    this->type = type;
}

*/





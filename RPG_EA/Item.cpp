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
    Types_of_items[0] = "Sword";
    Types_of_items[1] = "Shield";
    Types_of_items[2] = "Bloodshield";
    Types_of_items[3] = "Eye of Ktulkhu";
    Types_of_items[4] = "Star ring";
    Types_of_items[5] = "Ring of power";
    Types_of_items[6] = "Soulbreaker";
    Types_of_items[7] = "Crown_of_energy";
    Types_of_items[8] = "Golden apple";
    Types_of_items[9] = "Star platinum!";
}
void Item::setItemConst(string type) {
    if (type.compare(Types_of_items[0]) == 0){ //sword
        damage_bonus = 5;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare(Types_of_items[1])  == 0){ //shield
        damage_bonus = 0;
        maxHP_bonus = 10;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare(Types_of_items[2])  == 0){ //Bloodshield
        damage_bonus = 0;
        maxHP_bonus = 50;
        rest_bonus = -2;
        exp_Bonus = -1;
    }
    else if (type.compare(Types_of_items[3])  == 0){ //Eye of Ktulkhu
        damage_bonus = 10;
        maxHP_bonus = 10;
        rest_bonus = -2;
        exp_Bonus = 0;
    }
    else if (type.compare(Types_of_items[4])  == 0){ //Star ring
        damage_bonus = 0;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 5;
    }
    else if (type.compare(Types_of_items[5])  == 0){ //Ring of Power
        damage_bonus = 30;
        maxHP_bonus = -30;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else if (type.compare(Types_of_items[6]) == 0){ //Soulbreaker
        damage_bonus = 1000;
        maxHP_bonus = -10;
        rest_bonus = -100000;
        exp_Bonus = -10;
    }
    else if (type.compare(Types_of_items[7]) == 0){ //Crown of Energy
        damage_bonus = -1;
        maxHP_bonus = -5;
        rest_bonus = 0;
        exp_Bonus = 10;
    }
    else if (type.compare(Types_of_items[8]) == 0){ // Golden apple
        damage_bonus = 0;
        maxHP_bonus = 0;
        rest_bonus = 10;
        exp_Bonus = 0;
    }
    else if (type.compare(Types_of_items[9]) == 0){ //Star Platinum!
        damage_bonus = 30;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
    }
    else{
        damage_bonus = 0;
        maxHP_bonus = 0;
        rest_bonus = 0;
        exp_Bonus = 0;
        }


        this->type = type;
}







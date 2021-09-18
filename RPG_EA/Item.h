//
// Created by Sintelaris on 18.09.2021.
//

#ifndef UNTITLED_ITEM_H
#define UNTITLED_ITEM_H
#include <string>
using namespace std;
class Item {
public:
    Item();
    //Item(string type);
    int damage_bonus;
    int maxHP_bonus;
    int rest_bonus;
    int exp_Bonus;
    string type;
    void setItemConst(string type);
};


#endif //UNTITLED_ITEM_H

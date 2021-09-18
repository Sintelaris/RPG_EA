
#include "Game.h"
#include "Item.h"
#include <iostream>
using namespace std;

int main(){

    Game RPG_EA;


    while (RPG_EA.isRunning){
        switch(RPG_EA.isRunning){
            case 1:
                RPG_EA.menu();
                break;
            case 2:
                RPG_EA.game();
                break;
            case 3:
                RPG_EA.final_menu();
                break;
        }
    }

}

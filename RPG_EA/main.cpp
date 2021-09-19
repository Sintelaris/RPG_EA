
#include "Game.h"
#include <thread>
#include <ctime>
using namespace std;
int random(int num){
    srand(time(NULL));
    return rand() % num;
}
void randomThought_by_Amira(){
    string thoughts[5] = {
            "~I wish I could fly...~",
            "~Sometimes I ask myself if this how I want to spend my time...~",
            "~All I want is nothing more to hear you knocking at my door~",
            "~Hm......~",
            "~I just called to say I love you..~" };
    cout << "\n" << thoughts[random(4)];
}
int main(){
    Game RPG_EA;


    while (RPG_EA.isRunning){
        thread func(randomThought_by_Amira);
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
        func.join();
    }
}


#include "Game.h"
#include <thread>
#include <ctime>
using namespace std;
int random(int num){
    srand(time(NULL));
    return rand() % num;
}
void randomThought_by_Amira(){
    string thoughts[11] = {
            "~I wish I could fly...~",
            "~Sometimes I ask myself if this how I want to spend my time...~",
            "~All I want is nothing more to hear you knocking at my door~",
            "~Hm......~",
            "~Osmanthus wine tastes the same as I remember... But where are those who shared the memories?~",
            "~What would be if I will put water on top of the lava...~",
            "~Also try Terraria!~",
            "~Also try Minecraft!~",
            "~Am I Looking good enough?~",
            "~I have 5 fingers: 2 on the left hand, 3 on the right hand!~",
            "~Somebody...~"
            };
    cout << "\n" << thoughts[random(10)];
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

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "Building.hpp"
#include "Room.hpp"
#include "Player.hpp"

using namespace std;

int main(){

    // Room names
    vector<string> STDR_NS {"Math Suite","Lynch 182","Mund","Vents","Closet"};
    vector<string> MGCR_NS {"Bathroom","Attic","Basement","Igor's house","Outside"};
    vector<string> LCKR_NS {"Yarny boi's room","Dromy boi's room","Gamer room","Boi's room"};

    // Creates the buildings and rooms
    Building B1(STDR_NS,LCKR_NS,MGCR_NS);
    
    // Builds the room layouts
    B1.build_building();

    // Initializes random number for selecting a starting room based on vectors of room names passed
    srand(time(nullptr));
    int numrooms = STDR_NS.size() + MGCR_NS.size() + LCKR_NS.size();
    Room* startroom = B1.get_rooms()->operator[](rand()%numrooms).get();

    // Initializes player with the start room selected above
    Player p1(startroom);


    // Game Loop
    while(true){

        // Clear system console each turn
        cout << "\033c";


        // User input
        string uin = p1.dis_state_get_intput();
        cout << endl;

        Direction dir;
        if     (uin=="WEST")  dir = WEST;
        else if(uin=="EAST")  dir = EAST;
        else if(uin=="NORTH") dir = NORTH;
        else if(uin=="SOUTH") dir = SOUTH;
        else if(uin=="exit") break;

        if(p1.try_move(dir)){
            p1.move(dir);
        }
        else{
            cout << "You cannot travel in this direction!" << "\n" <<endl;
        }

    }

    cout << "Thanks for playing!" << endl;
}
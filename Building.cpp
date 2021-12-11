#include "Building.hpp"
#include "Room.hpp"
#include "StdRoom.hpp"
#include "LckRoom.hpp"
#include "MgcRoom.hpp"

#include <math.h>

using namespace std;

// Takes vectors of strings to build a vector of unique pointers and then a building: StdRooms, LckRooms, MgcRooms respectively
Building::Building(const vector<string>& v1, const vector<string>& v2, const vector<string>& v3)
{
    if(v1.size()){
        for(auto& name: v1){
            rooms.push_back(make_unique<StdRoom>(name));
        }
    }

    if(v2.size()){
        for(auto& name: v2){
            rooms.push_back(make_unique<LckRoom>(name));
        }
    }

    if(v3.size()){
        for(auto& name: v3){
            rooms.push_back(make_unique<MgcRoom>(name, this));
        }
    }
}


// Builds layout and assigns rooms to room members based on dynamic type
void Building::build_building(int seed)
{
    // 2d vector square: side is the side length of one of map
    int side = ceil(sqrt(rooms.size()));
    vector<vector<Room*>> map(side, vector<Room*>(side, nullptr));

    // Assigns rooms to random spots in the map
    srand(seed);
    for(auto& r : rooms){
        int ind1, ind2;

        // Make sure a room does not replace another room
        do{
        ind1 = rand() % side;
        ind2 = rand() % side;
        }
        while(map[ind1][ind2]!=nullptr);
        map[ind1][ind2] = r.get();
    }

    // Print map layout
    /*
    for(int i=0; i<side; ++i){
        for(int j=0; j<side; ++j){

            cout << i << j << " ";
            if(map[i][j]!=nullptr) cout << map[i][j]->get_name() << endl;
            else cout << "null" << endl;
        }
    }
    */


    // Loops through each spot in the map and assigns doors if needed based on dynamic type
    for(int i=0; i<side; ++i){
        for(int j=0; j<side; ++j){
            if(map[i][j]!=nullptr){

                //check above
                if(i-1>=0){
                    map[i][j]->add_adjacent_room(NORTH, map[i-1][j]);
                }

                //check below
                if(i+1 < side){
                    map[i][j]->add_adjacent_room(SOUTH, map[i+1][j]);
                }

                //check right
                if(j+1 < side){
                    map[i][j]->add_adjacent_room(EAST, map[i][j+1]);
                }

                //check left
                if(j-1 >=0){
                    map[i][j]->add_adjacent_room(WEST, map[i][j-1]);
                }
                
            }
        }
    }
}

// Returns raw pointer to the vector it contains ///Note to ask yarny boi
const vector<unique_ptr<Room>>* Building::get_rooms() const{
    return &rooms;
}


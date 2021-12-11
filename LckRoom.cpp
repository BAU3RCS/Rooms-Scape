#include "LckRoom.hpp"

// Randum number gen
#include <stdlib.h>
#include <time.h>

using namespace std;

// Constructor
LckRoom::LckRoom(const std::string& name)
    : Room(name)
    {}

// Make "room" the room we get to if we go through the door in a given direction
void LckRoom::add_adjacent_room(Direction dir, Room* room)
{
    switch(dir){
        case NORTH:
        north = room;
        break;

        case SOUTH:
        south = room;
        break;
         
        case EAST:
        east = room;
        break;

        case WEST:
        west = room;
        break;
    }
    
}

// Returns a boolean, whether there is an accessible room in the requested direction
bool LckRoom::can_move(Direction dir) const
{
    Room* check {nullptr};
    switch(dir){
        case NORTH:
        check = north;
        break;

        case SOUTH:
        check = south;
        break;
        
        case EAST:
        check = east;
        break;

        case WEST:
        check = west;
        break;
        }
    return (check!=nullptr);
}

/*
Returns a pointer to the room that has been entered,
there is a 50% chance the door is locked. If the door is locked 
a nullptr is returned
*/
Room* LckRoom::take_door(Direction dir) const
{
    srand(time(nullptr));
    // 50% chance the door is locked, user will be notified
    if(rand()%2){
        switch(dir){
            case NORTH:
            return north;
            break;

            case SOUTH:
            return south;
            break;
        
            case EAST:
            return east;
            break;

            case WEST:
            return west;
            break;
        }
    }
    else{
        cout << "Uh oh the door seems to be Locked! Maybe try another door!\n" << endl;
        return nullptr;
    }

   return nullptr;
}
#include "StdRoom.hpp"

using namespace std;

// Constructor: takes room name
StdRoom::StdRoom(const string& name)
    : Room{name}
    {}

// Make "room" the room we get to if we go through the door in a given direction
void StdRoom::add_adjacent_room(Direction dir, Room* room)
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
bool StdRoom::can_move(Direction dir) const
{
    return (take_door(dir)!=nullptr);
}

 // Returns a pointer to the room that has been entered
Room* StdRoom::take_door(Direction dir) const
{
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

   return nullptr;
}
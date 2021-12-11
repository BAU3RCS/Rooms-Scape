#include "MgcRoom.hpp"
#include "Building.hpp"

// Randum number gen
#include <stdlib.h>
#include <time.h>

using namespace std;

// Constructor: takes room name and th building that it is a part of
MgcRoom::MgcRoom(const std::string& name, Building* building)
    :Room{name}, building(building)
    {}

/* 
Magic room has no corelatted side rooms so this function does nothing,
but is needed since the function is pure virtual
 */
void MgcRoom::add_adjacent_room(Direction dir, Room* room)
{}

// Returns true as from a magic room you can always use any door
bool MgcRoom::can_move(Direction dir) const
{
    return true;
}

// Returns a pointer to the room that has been entered
Room* MgcRoom::take_door(Direction dir) const
{
    srand(time(nullptr));
    int rind = rand()% (building->get_rooms()->size());
    auto rooms = building->get_rooms();
    return rooms->operator[](rind).get();
    //return building->get_rooms()->operator[](rand()%(building->get_rooms()->size())).get(); yikes
}
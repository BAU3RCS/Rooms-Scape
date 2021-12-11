#include "Room.hpp"
#include <string>

using namespace std;


// Constructor: takes room name and sets it
Room::Room(const string& name)
    : name{name}
    {}

// Returns the name of the room
string Room::get_name() const
{
    return name;
}
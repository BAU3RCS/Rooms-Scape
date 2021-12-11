#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

enum Direction {NORTH=1, SOUTH=-1, WEST=2, EAST=-2}; //future up/down hehehe

// Abstract base should only contain name
class Room{
    public:

    // Constructor: used for derived classes, stores room name
    Room(const std::string& name);

    // Virtual destructor
    virtual ~Room() = default;

    // Make sure we don't copy rooms
    Room(const Room&) = delete;


    // Methods
    /**************************************************************************************************************************************/

    // Make "room" the room we get to if we go through door dir.
    virtual void add_adjacent_room(Direction dir, Room* room)=0;

    // Returns a boolean, whether there is an accessible room in the requested direction
    virtual bool can_move(Direction dir) const = 0;

    // Returns a pointer to the room that has been entered
    virtual Room* take_door(Direction dir) const = 0;

    // Returns the room's name
    std::string get_name() const;

    private:
    std::string name;

};

#endif
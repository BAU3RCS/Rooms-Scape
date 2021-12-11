#ifndef LCKROOM_H
#define LCKROOM_H

#include "Room.hpp"

// Doors randomly lock
class LckRoom : public Room{
    public:

    // Constructor: takes room name
    LckRoom(const std::string& name);

    //Destructor
    ~LckRoom() override = default;

    // Make sure we don't copy rooms
    LckRoom(const LckRoom&) = delete;
    
    // Methods
    /**************************************************************************************************************************************/

    // Make "room" the room we get to if we go through the door in a given direction
    void add_adjacent_room(Direction dir, Room* room) override;

    // Returns a boolean, whether there is an accessible room in the requested direction
    bool can_move(Direction dir) const override;

    /*
    Returns a pointer to the room that has been entered,
    there is a 50% chance the door is locked. If the door is locked 
    a nullptr is returned
    */
    Room* take_door(Direction dir) const override;


    private:

    //adjacent rooms
    Room* north;
    Room* south;
    Room* east;
    Room* west;
};

#endif
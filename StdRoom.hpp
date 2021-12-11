#ifndef STDROOM_H
#define STDROOM_H

#include "Room.hpp"
// Normal room implementation

class StdRoom : public Room{
    public:

    // Constructor: takes room name
    StdRoom(const std::string& name);

    // Destrcutor
    ~StdRoom() override = default;

    // Make sure we don't copy rooms
    StdRoom(const StdRoom&) = delete;

    // Methods
    /**************************************************************************************************************************************/

    // Make "room" the room we get to if we go through door dir.
    void add_adjacent_room(Direction dir, Room* room) override;

    // Returns a boolean, whether there is an accessible room in the requested direction
    bool can_move(Direction dir) const override;

    // Returns a pointer to the room that has been entered
    Room* take_door(Direction dir) const override;

    private:

    // Adjacent rooms
    Room* north;
    Room* south;
    Room* east;
    Room* west;
};

#endif
#ifndef MGCROOM_H
#define MGCROOM_H

#include "Room.hpp"
#include "Building.hpp"

// Randum number gen
#include <stdlib.h>
#include <time.h>


class MgcRoom : public Room{
    public:

    // Constructor: takes room name and Building
    MgcRoom(const std::string& name, Building* building);

    // Destructor
    ~MgcRoom() override = default;

    // Make sure we don't copy rooms
    MgcRoom(const MgcRoom&) = delete;

    // Methods
    /**************************************************************************************************************************************/

    // Magic room so does nothing
    void add_adjacent_room(Direction dir, Room* room) override;

    // Returns a boolean, whether there is an accessible room in the requested direction
    bool can_move(Direction dir) const override;

    // Returns a pointer to the room that has been entered
    Room* take_door(Direction dir) const override;

    private:

    // Should only access rooms in the same building
    Building* building;

};


#endif
#ifndef PLAYER_H
#define PLAYER_H

#include "Room.hpp"


class Player {
    public:
    // constructors, etc
    Player(Room* current_room);
    ~Player()=default;

    // Methods
    /**************************************************************************************************************************************/

    // Returns a string containing info about the player (room we're in, doors that are available)
    std::string current_state();

    // Displays the current state to user and recieves user input for their next turn
    std::string dis_state_get_intput();

    // Checks whether a move is theoretically possible, returns bool
    bool try_move(Direction dir);

    // Attempts to move in the given direction, if valid current room is changed. Could fail given room conditions!
    void move(Direction dir);

    private:

    // Association not conncetion/communication
    Room* current_room;

};

#endif
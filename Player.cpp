#include "Player.hpp"
#include <sstream>

using namespace std;

// Constructor
Player::Player(Room* current_room)
   :current_room{current_room}
   {}

// Returns a string containing info about the player (room we're in, doors that are available)
string Player::current_state()
{
    stringstream stream;

    stream << "You are currently in the " << current_room->get_name() << ".\n"
           << "The north door " << (try_move(NORTH)? "is available!" : "is not available.") << "\n"
           << "The south door " << (try_move(SOUTH)? "is available!" : "is not available.") << "\n"
           << "The east door " << (try_move(EAST)? "is available!" : "is not available.") << "\n"
           << "The west door " << (try_move(WEST)? "is available!" : "is not available.")
           ;

      return stream.str();
}

// Displays the current state to user and recieves user input for their next turn
string Player::dis_state_get_intput()
{
    // Displays the players state in a room
    cout << current_state() << "\n\n";

    // Asks user to make decision
    cout << "What direction would you like to travel? (NORTH, SOUTH, EAST, or WEST)"
         << "\nIf you want to exit the game type \"exit\": " << endl;

    string dir;

    // Reads in user input while making sure it is valid
    while(true){
        if ((cin >> dir) && (dir=="WEST" || dir=="EAST" || dir=="NORTH" || dir=="SOUTH" || dir=="exit")) {
            return dir;
            }
            else {
                cin.clear();
                string trash;
                getline(cin, trash);
                cout << "Only input NORTH, SOUTH, EAST, WEST, or exit!: \n" << endl;
            }
    }
}

// Checks whether a move is theoretically possible, returns bool
bool Player::try_move(Direction dir)
{
    return current_room->can_move(dir);
}

// Attempts to move in the given direction, if valid current room is changed. Could fail given room conditions!
void Player::move(Direction dir)
{
    auto room = current_room->take_door(dir);
    if(room!=nullptr){
        current_room = current_room->take_door(dir);
    }
}

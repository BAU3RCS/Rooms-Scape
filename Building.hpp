#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>

// Randum number gen
#include <stdlib.h>

#include "Room.hpp"

// Owns and organizes rooms
class Building{
    public:
    // Takes vectors of strings to build a vector of unique pointers and then a building: StdRooms, LckRooms, MgcRooms respectively
    Building(const std::vector<std::string>& v1, const std::vector<std::string>& v2, const std::vector<std::string>& v3);

    //destructor
    ~Building() = default;

    // Methods
    /**************************************************************************************************************************************/

    // Builds layout and assigns rooms to room members based on dynamic type
    void build_building(int seed=time(nullptr));

    // Returns raw pointer to the vector it contains
    const std::vector<std::unique_ptr<Room>>* get_rooms() const;

    private:
    std::vector<std::unique_ptr<Room>> rooms;
};

#endif
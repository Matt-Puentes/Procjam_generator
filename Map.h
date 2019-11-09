#ifndef __MAP_H__
#define __MAP_H__

#include "Room.h"
#include <SFML/Graphics.hpp>

class Map { 
    private:
        std::vector<Room*> rooms;
        std::map<std::vector<int>, bool> positionLookupTable;
    public:
        Map();
        Map(std::vector<Room*> rooms);
        std::vector<Room*> getRooms() const;
        int drawToWindow(sf::RenderWindow *window) const;
};

#endif
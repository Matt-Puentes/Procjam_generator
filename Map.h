#ifndef __MAP_H__
#define __MAP_H__

#include "Room.h"
#include <SFML/Graphics.hpp>

class Map { 
    private:
        std::vector<Room*> rooms;
        std::vector<sf::Vector2f> usedPositions;
    public:
        Map();
        Map(std::vector<Room*> rooms);
        std::vector<Room*> getRooms() const;
        bool addRoom(Room* new_room);
        int drawToWindow(sf::RenderWindow *window) const;
};

#endif
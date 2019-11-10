#ifndef __MAP_H__
#define __MAP_H__

#include "Room.h"
#include <SFML/Graphics.hpp>

class Map { 
    private:
        std::vector<Room*> rooms;
    public:
        Map();
        ~Map();
        Map(std::vector<Room*> rooms);
        std::vector<Room*> getRooms() const;
        Room *getRootRoom() const;
        bool addRoom(Room* new_room);
        float drawToWindow(sf::RenderTarget *window, int smallest_x, int smallest_y, int selected_room_id = -1) const;
        std::vector<int> getBounds() const;
};

#endif
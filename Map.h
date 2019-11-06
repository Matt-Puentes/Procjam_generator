#include "Room.h"
#include <SFML/Graphics.hpp>

class Map { 
    private:
        std::vector<Room*> rooms;
    public:
        Map();
        Map(std::vector<Room*> rooms);
        std::vector<Room*> getRooms();
};

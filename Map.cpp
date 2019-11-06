#include "Map.h"

Map::Map(){
    rooms.clear();
}

Map::Map(std::vector<Room*> init_rooms){
    rooms = init_rooms;
}

std::vector<Room*> Map::getRooms() const{
    return rooms;
}

int Map::drawToWindow(sf::RenderWindow *window) const{
    for(int i = 0; i < rooms.size(); i++){
        window -> draw(*(rooms[i] -> getShape()));
    }
    return 1;
}
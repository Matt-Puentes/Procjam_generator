#include "Map.h"
Map::Map(){
    rooms.clear();
}

Map::Map(std::vector<Room*> init_rooms){
    rooms = init_rooms;
}

std::vector<Room*> Map::getRooms(){
    return rooms;
}

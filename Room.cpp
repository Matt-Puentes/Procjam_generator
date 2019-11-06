#include "Room.h"

Room::Room(sf::Shape *room_shape){
    shape = room_shape;
    position = std::vector<int>(0, 0);
}

Room::Room(sf::Shape *room_shape, std::vector<int> init_pos){
    shape = room_shape;
    position = init_pos;
}

Room::~Room(){
    delete shape;
}

sf::Shape *Room::getShape() const{
    return shape;
}

std::vector<Room*> Room::getNeighbors() const{
    return neighbors;
}

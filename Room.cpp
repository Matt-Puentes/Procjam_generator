#include "Room.h"

Room::Room(sf::Shape *room_shape, sf::Vector2f init_pos){
    shape = room_shape;
    position = init_pos;
    shape -> setPosition(init_pos);
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

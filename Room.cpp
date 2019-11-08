#include "Room.h"
#include <stdio.h>

Room::Room(sf::Shape *room_shape, sf::Vector2f init_pos){
    shape = room_shape;
    position = init_pos;
    shape -> setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape -> getLocalBounds().height / 2)));
}


sf::Vector2f get_random_position(){
    return sf::Vector2f(0, 0);
}

Room::Room(Room::RoomType room_type, sf::Vector2f init_pos){
    int width_range_low = 0;
    int width_range_high = 0;
    int height_range_low = 0;
    int height_range_high = 0;
    switch(room_type){
            case ROOM_BIG : 
                printf("BIG");
                width_range_low = 50;
                width_range_high = 200;
            break;
            case ROOM_SMALL : 
                printf("SMALL");
                width_range_low = 50;
                width_range_high = 200;
            break;
            case ROOM_CIRCLE : 
                printf("CIRCLE");
                width_range_low = 50;
                width_range_high = 200;
            break;
            case ROOM_TRIANGLE : 
                printf("TRIANGLE");
                width_range_low = 50;
                width_range_high = 200;
            break;
            case ROOM_LONG : 
                printf("LONG");
                width_range_low = 50;
                width_range_high = 200;
            break;
            case ROOM_WIDE : 
                printf("WIDE");
                width_range_low = 50;
                width_range_high = 200;
            break;
            default:
                printf("Default");
            break;
    }
    int width = rand() % (width_range_high - width_range_low) + width_range_low;
    int height = rand() % (height_range_high - height_range_low) + height_range_low;

    // sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(50, 50)), sf::Vector2f(200, 200));

    position = init_pos;
    shape -> setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape -> getLocalBounds().height / 2)));
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

sf::Vector2f Room::getPos() const{
    return position;
}
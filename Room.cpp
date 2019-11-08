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
                printf("BIG\n");
                width_range_low = 50;
                width_range_high = 200;
                height_range_high = 50;
                height_range_low = 20;
            break;
            case ROOM_SMALL : 
                printf("SMALL\n");
                width_range_low = 50;
                width_range_high = 200;
                height_range_high = 50;
                height_range_low = 20;
            break;
            case ROOM_CIRCLE : 
                printf("CIRCLE\n");
                width_range_low = 50;
                width_range_high = 200;
                height_range_high = 50;
                height_range_low = 20;
            break;
            case ROOM_TRIANGLE : 
                printf("TRIANGLE\n");
                width_range_low = 50;
                width_range_high = 200;
                height_range_high = 50;
                height_range_low = 20;
            break;
            case ROOM_LONG : 
                printf("LONG\n");
                width_range_low = 50;
                width_range_high = 200;
                height_range_high = 50;
                height_range_low = 20;
            break;
            case ROOM_WIDE : 
                printf("WIDE\n");
                width_range_low = 50;
                width_range_high = 200;
                height_range_high = 50;
                height_range_low = 20;
            break;
            default:
                printf("Default\n");
            break;
    }
    printf("%d, %d\n", width_range_high, width_range_low);
    int width = rand() % (width_range_high - width_range_low) + width_range_low;
    int height = rand() % (height_range_high - height_range_low) + height_range_low;
    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
    rectangle -> setPosition(sf::Vector2f(200, 200));
    position = init_pos;
    shape = rectangle;
    shape -> setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape -> getLocalBounds().height / 2)));
    printf("Helloooo \n");
}


Room::~Room(){
    delete shape;
}

sf::Shape *Room::getShape() const{
    printf("Shape get\n");
    return shape;
}

std::vector<Room*> Room::getNeighbors() const{
    return neighbors;
}

sf::Vector2f Room::getPos() const{
    printf("Hello\n");
    return position;
}
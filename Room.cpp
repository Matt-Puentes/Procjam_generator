#include "Room.h"
#include <stdio.h>

Room::Room(sf::Shape *room_shape, sf::Vector2f init_pos){
    shape = room_shape;
    position = init_pos;
    shape -> setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape -> getLocalBounds().height / 2)));
    neighbor_num = rand() % 2;
}

Room::Room(Room::RoomType room_type, sf::Vector2f init_pos){
    if(room_type == ROOM_UNDEFINED){
        printf("New room type\n");
        room_type = static_cast<Room::RoomType>(rand() % ROOM_UNDEFINED);
    }
    switch(room_type){
        case ROOM_BIG : makeRoomBig(init_pos); break;
        case ROOM_SMALL : makeRoomSmall(init_pos); break;
        case ROOM_CIRCLE : makeRoomCircle(init_pos); break;
        case ROOM_TRIANGLE : makeRoomTriangle(init_pos); break;
        case ROOM_LONG : makeRoomLong(init_pos); break;
        case ROOM_WIDE : makeRoomWide(init_pos); break;
        case ROOM_UNDEFINED : // Go to next case
        default : printf("Error: undefined room type.\n"); break;
    }

    position = init_pos;
    printf("Neighbor Number %d\n", neighbor_num);
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

void Room::addNeighbor(Room* room){
    neighbors.push_back(room);
}

sf::Vector2f Room::getPos() const{
    return position;
}

void Room::makeRoomBig(sf::Vector2f init_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(100, 150));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
    neighbor_num = 2;
}

void Room::makeRoomSmall(sf::Vector2f init_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(50, 50));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
    neighbor_num = rand() % 2;
}

void Room::makeRoomCircle(sf::Vector2f init_pos) {
	shape = new sf::CircleShape(50);
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
    neighbor_num = rand() % 2;
}

void Room::makeRoomTriangle(sf::Vector2f init_pos) {
	sf::ConvexShape *convex = new sf::ConvexShape();
	convex->setPointCount(3);
	convex->setPoint(0, init_pos);
	convex->setPoint(1, init_pos + sf::Vector2f(50, 0));
	convex->setPoint(2, init_pos - sf::Vector2f(0, 50));

	shape = convex;
    neighbor_num = rand() % 2;
}

void Room::makeRoomLong(sf::Vector2f init_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(50, 200));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
    neighbor_num = rand() % 2;
}

void Room::makeRoomWide(sf::Vector2f init_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(200, 50));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
    neighbor_num = rand() % 2;
}

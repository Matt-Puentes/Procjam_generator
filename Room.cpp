#include "Room.h"
#include <stdio.h>

Room::Room(Room::RoomType room_type, RoomDirection dir_from_parent, Room* parent){
    dir = dir_from_parent;
    parent = parent;
    neighbors.push_back(NULL);
    neighbors.push_back(NULL);
    neighbors.push_back(NULL);
    neighbors.push_back(NULL);
    int distance_x = -1;
    int distance_y = -1;
    if(parent != NULL){
        distance_x = (rand() % 25) + parent -> getShape() -> getLocalBounds().width;
        distance_y = (rand() % 25) + parent -> getShape() -> getLocalBounds().height;
    }
    printf("distance: %d, %d\n", distance_x, distance_y);
    sf::Vector2f init_pos = sf::Vector2f(1920 / 2, 1080 / 2);

    switch(dir_from_parent){
        case Room::UP_FROM_PARENT:
            init_pos.x = parent -> getPos().x;
            init_pos.y = parent -> getPos().y + distance_y;
            neighbors[DOWN_FROM_PARENT] = parent;
        break; 
        case Room::DOWN_FROM_PARENT:
            init_pos.x = parent -> getPos().x;
            init_pos.y = parent -> getPos().y - distance_y;
            neighbors[UP_FROM_PARENT] = parent;
        break; 
        case Room::LEFT_FROM_PARENT:
            init_pos.x = parent -> getPos().x + distance_x;
            init_pos.y = parent -> getPos().y;
            neighbors[RIGHT_FROM_PARENT] = parent;
        break; 
        case Room::RIGHT_FROM_PARENT:
            init_pos.x = parent -> getPos().x - distance_x;
            init_pos.y = parent -> getPos().y;
            neighbors[LEFT_FROM_PARENT] = parent;
        break; 
        default:
        break;
    }

    if(room_type == ROOM_UNDEFINED){
        room_type = static_cast<Room::RoomType>(rand() % ROOM_UNDEFINED);
    }
    if(room_type == ROOM_BIG)
        makeRoomBig(init_pos, 50, 150);
    if(room_type == ROOM_SMALL)
        makeRoomSmall(init_pos, 20, 50);
    if(room_type == ROOM_CIRCLE)
        makeRoomCircle(init_pos, 10, 200);
    if(room_type == ROOM_TRIANGLE)
        makeRoomTriangle(init_pos, 50, 150);
    if(room_type == ROOM_LONG)
        makeRoomLong(init_pos, 20, 10, 200, 100);
    if(room_type == ROOM_WIDE)
        makeRoomLong(init_pos, 200, 100, 20, 10);
        

    position = init_pos;
  	shape->setFillColor(getRandomColor());
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

bool Room::addNeighbor(Room* room, RoomDirection dir){
    if(dir == Room::ROOT)
        return false;
    if(neighbors[dir] == NULL){
        neighbors[dir] = room;
        return true;
    }
    return false;
}

std::vector<Room::RoomDirection> Room::getFreeDirections(){
    std::vector<Room::RoomDirection> freeDirs;

    if(neighbors[Room::UP_FROM_PARENT] == NULL)
        freeDirs.push_back(Room::UP_FROM_PARENT);
    if(neighbors[Room::DOWN_FROM_PARENT] == NULL)
        freeDirs.push_back(Room::DOWN_FROM_PARENT);
    if(neighbors[Room::RIGHT_FROM_PARENT] == NULL)
        freeDirs.push_back(Room::RIGHT_FROM_PARENT);
    if(neighbors[Room::LEFT_FROM_PARENT] == NULL)
        freeDirs.push_back(Room::LEFT_FROM_PARENT);

    return freeDirs;
}

sf::Vector2f Room::getPos() const{
    return position;
}

void Room::setPos(sf::Vector2f new_pos){
    position.x = new_pos.x;
    position.y = new_pos.y;
}

void Room::setNeighbor(Room::RoomDirection dir, Room* room){
    neighbors[dir] = room;
}

int Room::getNeighborCount() const{
    int count = 0;
    if(neighbors[Room::UP_FROM_PARENT] != NULL)
        count++;
    if(neighbors[Room::DOWN_FROM_PARENT] != NULL)
        count++;
    if(neighbors[Room::RIGHT_FROM_PARENT] != NULL)
        count++;
    if(neighbors[Room::LEFT_FROM_PARENT] != NULL)
        count++;
    return count;
}

sf::Color Room::getRandomColor() {
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;

	return sf::Color(r, g, b);
}

void Room::makeRoomBig(sf::Vector2f init_pos, int min_size, int max_size){
    sf::ConvexShape* big_room = new sf::ConvexShape();

    int points = (rand() % 4) + 5;
    big_room->setPointCount(points);

    for (int i = 0; i < points; i++) {
        int radius = (rand() % (max_size - min_size)) + min_size;
        int x = cos(((i * (360 / points)) * M_PI) / 180) * radius;
        int y = sin(((i * (360 / points)) * M_PI) / 180) * radius;
        big_room->setPoint(i, sf::Vector2f(init_pos.x + x, init_pos.y - y));
    }

    shape = big_room;
	neighbor_num = (rand() % 2) + 2;
}

void Room::makeRoomSmall(sf::Vector2f init_pos, int min_size, int max_size) {
    sf::ConvexShape* big_room = new sf::ConvexShape();

    int points = (rand() % 4) + 5;
    big_room->setPointCount(points);

    for (int i = 0; i < points; i++) {
        int radius = (rand() % (max_size - min_size)) + min_size;
        int x = cos(((i * (360 / points)) * M_PI) / 180) * radius;
        int y = sin(((i * (360 / points)) * M_PI) / 180) * radius;
        big_room->setPoint(i, sf::Vector2f(init_pos.x + x, init_pos.y - y));
    }

    shape = big_room;

	neighbor_num = (rand() % 2) + 1;
}

void Room::makeRoomCircle(sf::Vector2f init_pos, int min_size, int max_size) {
	int r_x = (rand() % (max_size - min_size)) + min_size;
	int r_y = (rand() % (max_size - min_size)) + min_size;
	shape = new EllipseShape(sf::Vector2f(r_x, r_y));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
	neighbor_num = 1;
}

void Room::makeRoomTriangle(sf::Vector2f init_pos, int min_size, int max_size) {
	sf::ConvexShape* triangle_room = new sf::ConvexShape();
	triangle_room->setPointCount(3);

	for (int i = 0; i < 3; i++) {
		int radius = (rand() % (max_size - min_size)) + min_size;
		int x = cos(((i * (360 / 3)) * M_PI) / 180) * radius;
		int y = sin(((i * (360 / 3)) * M_PI) / 180) * radius;
		triangle_room->setPoint(i, sf::Vector2f(init_pos.x + x, init_pos.y - y));
	}
	shape = triangle_room;
    neighbor_num = rand() % 3;
}

void Room::makeRoomLong(sf::Vector2f init_pos, int width_max, int width_min, int height_max, int height_min) {
	int x = (rand() % (width_max - width_min)) + width_min;
	int y = (rand() % (height_max - height_min)) + height_min;
	shape = new sf::RectangleShape(sf::Vector2f(x, y));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));

    neighbor_num = rand() % 3;
}

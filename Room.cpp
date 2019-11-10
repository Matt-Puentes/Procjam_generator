#include "Room.h"
#include <stdio.h>

Room::Room(Room::RoomType room_type, RoomDirection dir_from_parent, Room* new_parent){
    static int roomCount = 0;
    roomID = roomCount + 0;
    roomCount++;

    dir = dir_from_parent;
    parent = new_parent;

    // Initialize neighbors array
    neighbors.push_back(NULL);
    neighbors.push_back(NULL);
    neighbors.push_back(NULL);
    neighbors.push_back(NULL);

    // Create room shape according to type
    if(room_type == ROOM_UNDEFINED)
        room_type = static_cast<Room::RoomType>(rand() % ROOM_UNDEFINED);
    if(room_type == ROOM_BIG)
        makeRoomBig(50, 150);
    else if(room_type == ROOM_SMALL)
        makeRoomSmall(20, 50);
    else if(room_type == ROOM_CIRCLE)
        makeRoomCircle(10, 200);
    else if(room_type == ROOM_TRIANGLE)
        makeRoomTriangle(50, 150);
    else if(room_type == ROOM_LONG)
        makeRoomLong(20, 10, 200, 100);
    else if(room_type == ROOM_WIDE)
        makeRoomLong(200, 100, 20, 10);

    int distance_x = -1;
    int distance_y = -1;
    if(parent != NULL){
        distance_x = (rand() % 25) + (parent -> getShape() -> getLocalBounds().width + getShape() -> getLocalBounds().width);
        distance_y = (rand() % 25) + (parent -> getShape() -> getLocalBounds().height + getShape() -> getLocalBounds().height);
    }
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

    position = init_pos;
    shape -> setPosition(init_pos.x - (shape -> getLocalBounds().width / 2), init_pos.y - (shape -> getLocalBounds().height / 2));
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
    shape -> setPosition(new_pos.x - (shape -> getLocalBounds().width / 2), new_pos.y - (shape -> getLocalBounds().height / 2));
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

sf::ConvexShape *Room::makeConvexShape(int max_points, int min_points, int min_size, int max_size){
    sf::ConvexShape* convex_shape = new sf::ConvexShape();
    int points;
    if(max_points == min_points){
        points = min_points;
    } else {
        points = (rand() % (max_points - min_points)) + min_points;
    }
    convex_shape -> setPointCount(points);

    for (int i = 0; i < points; i++) {
        int radius = (rand() % (max_size - min_size)) + min_size;
        int x = cos(((i * (360 / points)) * M_PI) / 180) * radius;
        int y = sin(((i * (360 / points)) * M_PI) / 180) * radius;
        convex_shape -> setPoint(i, sf::Vector2f(x + radius, y + radius));
    }

    return convex_shape;
}

void Room::makeRoomBig(int min_size, int max_size){
    shape = makeConvexShape(9, 5, min_size, max_size);
	neighbor_num = (rand() % 2) + 2;
}

void Room::makeRoomSmall(int min_size, int max_size) {
    shape = makeConvexShape(9, 5, min_size, max_size);
	neighbor_num = (rand() % 2) + 1;
}

void Room::makeRoomTriangle(int min_size, int max_size) {
    shape = makeConvexShape(3, 3, min_size, max_size);
    neighbor_num = rand() % 3;
}

void Room::makeRoomCircle(int min_size, int max_size) {
	int r_x = (rand() % (max_size - min_size)) + min_size;
	int r_y = (rand() % (max_size - min_size)) + min_size;
	shape = new EllipseShape(sf::Vector2f(r_x, r_y));
	shape -> setPosition(sf::Vector2f(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2));
	neighbor_num = 1;
}

void Room::makeRoomLong(int width_max, int width_min, int height_max, int height_min) {
	int x = (rand() % (width_max - width_min)) + width_min;
	int y = (rand() % (height_max - height_min)) + height_min;
	shape = new sf::RectangleShape(sf::Vector2f(x, y));
	shape->setPosition(sf::Vector2f(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2));

    neighbor_num = rand() % 3;
}

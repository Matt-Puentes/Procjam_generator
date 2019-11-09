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

Room::Room(Room::RoomType room_type, sf::Vector2f init_pos, bool rect){
    switch(room_type){
            case ROOM_BIG : 
				makeRoomBig(init_pos, 50, 150, rect);
            break;
            case ROOM_SMALL : 
                makeRoomSmall(init_pos, 20, 50, rect);
            break;
            case ROOM_CIRCLE : 
				makeRoomCircle(init_pos, 10, 200);
            break;
            case ROOM_TRIANGLE : 
				makeRoomTriangle(init_pos, 50, 150);
            break;
            case ROOM_LONG : 
				makeRoomLong(init_pos, 20, 10, 200, 100);
            break;
            case ROOM_WIDE : 
				makeRoomLong(init_pos, 200, 100, 20, 10);
            break;
            default:
                printf("Default");
            break;
    }

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

sf::Vector2f Room::getPos() const{
    return position;
}

void Room::makeRoomBig(sf::Vector2f init_pos, int min_size, int max_size, bool rect){
	srand(time(0));
	
	if (rect){
		int width = rand() % (max_size - min_size) + min_size;
		int height = rand() % (max_size - min_size) + min_size;
		shape = new sf::RectangleShape(sf::Vector2f(width, height));
		shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
	}

	else {
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
	}

	neighbor_num = (rand() % 2) + 2;
}

void Room::makeRoomSmall(sf::Vector2f init_pos, int min_size, int max_size, bool rect) {
	srand(time(0));

	if (rect) {
		int width = rand() % (max_size - min_size) + min_size;
		int height = rand() % (max_size - min_size) + min_size;
		shape = new sf::RectangleShape(sf::Vector2f(width, height));
		shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
	}

	else {
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
	}

	neighbor_num = (rand() % 2) + 1;
}

void Room::makeRoomCircle(sf::Vector2f init_pos, int min_size, int max_size) {
	srand(time(0));
	int r_x = (rand() % (max_size - min_size)) + min_size;
	int r_y = (rand() % (max_size - min_size)) + min_size;
	shape = new EllipseShape(sf::Vector2f(r_x, r_y));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
	neighbor_num = 1;
}

void Room::makeRoomTriangle(sf::Vector2f init_pos, int min_size, int max_size) {
	srand(time(0));
	
	sf::ConvexShape* big_room = new sf::ConvexShape();

	int points = 3;
	big_room->setPointCount(points);

	for (int i = 0; i < points; i++) {
		int radius = (rand() % (max_size - min_size)) + min_size;
		int x = cos(((i * (360 / points)) * M_PI) / 180) * radius;
		int y = sin(((i * (360 / points)) * M_PI) / 180) * radius;
		big_room->setPoint(i, sf::Vector2f(init_pos.x + x, init_pos.y - y));
	}

	shape = big_room;

	neighbor_num = (rand() % 3) + 1;
}

void Room::makeRoomLong(sf::Vector2f init_pos, int width_max, int width_min, int height_max, int height_min) {
	srand(time(0));
	int x = (rand() % (width_max - width_min)) + width_min;
	int y = (rand() % (height_max - height_min)) + height_min;
	shape = new sf::RectangleShape(sf::Vector2f(x, y));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));

	neighbor_num = 2;
}

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
    int width_range_low = 0;
    int width_range_high = 0;
    int height_range_low = 0;
    int height_range_high = 0;
    switch(room_type){
            case ROOM_BIG : 
                //printf("BIG");
                width_range_low = 50;
                width_range_high = 200;
				height_range_low = 100;
				height_range_high = 300;
				makeRoomBig(init_pos, 50, 150, rect);
            break;
            case ROOM_SMALL : 
                //printf("SMALL");
                width_range_low = 50;
                width_range_high = 200;
				makeRoomSmall(init_pos, 20, 50, rect);
            break;
            case ROOM_CIRCLE : 
                //printf("CIRCLE");
                width_range_low = 50;
                width_range_high = 200;
				makeRoomCircle(init_pos);
            break;
            case ROOM_TRIANGLE : 
                //printf("TRIANGLE");
                width_range_low = 50;
                width_range_high = 200;
				makeRoomTriangle(init_pos);
            break;
            case ROOM_LONG : 
                //printf("LONG");
                width_range_low = 50;
                width_range_high = 200;
				makeRoomLong(init_pos);
            break;
            case ROOM_WIDE : 
                //printf("WIDE");
                width_range_low = 50;
                width_range_high = 200;
				makeRoomWide(init_pos);
            break;
            default:
                printf("Default");
            break;
    }

	position = init_pos;
	//shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
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
			printf("%f, %f\n", big_room->getPoint(i).x, big_room->getPoint(i).y);
		}

		shape = big_room;
	}

	neighbor_num = (rand() % 3) + 3;
	printf("%d\n", neighbor_num);
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
			printf("%f, %f\n", big_room->getPoint(i).x, big_room->getPoint(i).y);
		}

		shape = big_room;
	}

	neighbor_num = (rand() % 2) + 1;
	printf("%d\n", neighbor_num);
}

void Room::makeRoomCircle(sf::Vector2f init_pos) {
	shape = new sf::CircleShape(25);
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
}

void Room::makeRoomTriangle(sf::Vector2f init_pos) {
	sf::ConvexShape *convex = new sf::ConvexShape();
	convex->setPointCount(3);
	convex->setPoint(0, init_pos);
	convex->setPoint(1, init_pos + sf::Vector2f(50, 0));
	convex->setPoint(2, init_pos - sf::Vector2f(0, 50));

	shape = convex;
}

void Room::makeRoomLong(sf::Vector2f init_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(50, 200));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
}

void Room::makeRoomWide(sf::Vector2f init_pos) {
	shape = new sf::RectangleShape(sf::Vector2f(200, 50));
	shape->setPosition(sf::Vector2f(init_pos.x - (shape->getLocalBounds().width / 2), init_pos.y - (shape->getLocalBounds().height / 2)));
}

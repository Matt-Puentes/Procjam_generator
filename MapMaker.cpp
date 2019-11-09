#include "MapMaker.h"
#include <queue>
MapMaker::MapMaker(){}

Map* MapMaker::getMap(int screen_pixel_width, int screen_pixel_height){
    std::queue<Room *> roomsToGenerate;
    std::vector<Room *> roomList;
    
    Room *r = new Room(Room::ROOM_BIG, sf::Vector2f(rand() % 500 + 100, rand() % 500 + 100));
    roomsToGenerate.push(r);
    printf("-------new map-------\n");
    bool generating = true;
    while(!roomsToGenerate.empty()){
        Room* current_room = roomsToGenerate.front();
        printf("Iterating over room- this should room have %d neighbors\n", current_room -> neighbor_num);
        roomList.push_back(current_room);
        while(current_room -> getNeighbors().size() < current_room -> neighbor_num){
            Room * new_room = new Room(Room::ROOM_UNDEFINED, sf::Vector2f(rand() % 500 + 100, rand() % 500 + 100));
            roomsToGenerate.push(new_room);
            roomList.push_back(new_room);
            current_room -> addNeighbor(new_room);
        }
        roomsToGenerate.pop();
    }
    // printf("%lu\n", roomList.size());
        // std::vector<Room*> rooms;
        // rooms.push_back(new Room(new sf::CircleShape(50), sf::Vector2f(100, 100)));
		// rooms.push_back(new Room(new sf::CircleShape(50), sf::Vector2f(400, 100)));
		// rooms.push_back(new Room(Room::ROOM_BIG, sf::Vector2f(400, 450)));
		// rooms.push_back(new Room(Room::ROOM_SMALL, sf::Vector2f(150, 450)));
		// rooms.push_back(new Room(Room::ROOM_CIRCLE, sf::Vector2f(150, 300)));
		// rooms.push_back(new Room(Room::ROOM_TRIANGLE, sf::Vector2f(150, 150)));
		// rooms.push_back(new Room(Room::ROOM_WIDE, sf::Vector2f(400, 100)));
		// rooms.push_back(new Room(Room::ROOM_LONG, sf::Vector2f(700, 300)));
        // // Map map = Map(rooms);

    return new Map(roomList);
}
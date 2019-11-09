#include "MapMaker.h"
#include <queue>
MapMaker::MapMaker(){}

Map* MapMaker::getMap(int screen_pixel_width, int screen_pixel_height){
    std::queue<Room *> roomsToGenerate;
    // std::vector<Room *> roomList;
    
    Room *r = new Room(Room::ROOM_BIG, sf::Vector2f(rand() % 500 + 100, rand() % 500 + 100));
    roomsToGenerate.push(r);

    Map *newmap = new Map();
    newmap -> addRoom(r);
    fputs("------NEWMAP------\n", stdout);

    while(!roomsToGenerate.empty()){
        Room* current_room = roomsToGenerate.front();
        printf("Iterating over room- this should room have %d neighbors\n", current_room -> neighbor_num);
        while(current_room -> getNeighbors().size() < current_room -> neighbor_num){
            Room * new_room = new Room(Room::ROOM_UNDEFINED, sf::Vector2f(rand() % 500 + 100, rand() % 500 + 100));
            
            bool result = newmap -> addRoom(new_room);
            while(!result){
                fputs("Regenerating position!\n", stdout);
                new_room -> setPos(sf::Vector2f(rand() % 500 + 100, rand() % 500 + 100));
                result = newmap -> addRoom(new_room);
            }

            roomsToGenerate.push(new_room);
            int random = rand() % 4;
            Room::RoomDirection dir = Room::ROOT;
            if(random == 0)
                dir = Room::UP_FROM_PARENT;
            if(random == 1)
                dir = Room::DOWN_FROM_PARENT;
            if(random == 2)
                dir = Room::LEFT_FROM_PARENT;
            if(random == 3)
                dir = Room::RIGHT_FROM_PARENT;
                 
            current_room -> addNeighbor(new_room, dir);
        }
        roomsToGenerate.pop();
    }
    printf("Newmap rooms length: %lu", newmap -> getRooms().size());
    return newmap;
}
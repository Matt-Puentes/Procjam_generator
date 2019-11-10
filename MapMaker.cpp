#include "MapMaker.h"
#include <queue>
MapMaker::MapMaker(){}

Map* MapMaker::getMap(int screen_pixel_width, int screen_pixel_height){
    std::queue<Room *> roomsToGenerate;
    
    Room *r = new Room(Room::ROOM_BIG, Room::ROOT);
    roomsToGenerate.push(r);

    Map *newmap = new Map();
    newmap -> addRoom(r);

    fputs("------NEWMAP------\n", stdout);
    while(!roomsToGenerate.empty()){
        Room* current_room = roomsToGenerate.front();
        while(current_room -> getNeighborCount() < current_room -> neighbor_num){

            std::vector<Room::RoomDirection> freeDirs = current_room -> getFreeDirections();
            if(freeDirs.size() == 0){
                break; 
            }

            int random = rand() % freeDirs.size();
            Room::RoomDirection dir = freeDirs[random];
            Room * new_room = new Room(Room::ROOM_UNDEFINED, dir, current_room);

            bool success = newmap -> addRoom(new_room);
            if(success){
                current_room -> addNeighbor(new_room, dir);
                roomsToGenerate.push(new_room);         
            }
        }
        roomsToGenerate.pop();
    }
    return newmap;
}
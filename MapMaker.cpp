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
        printf("Iterating over room- this should room have %d neighbors\n", current_room -> neighbor_num);
        printf("Current room neighbors: %d, %d\n", current_room -> getNeighborCount(), current_room -> neighbor_num);
        while(current_room -> getNeighborCount() < current_room -> neighbor_num){
            printf("Current room neighbors: %d, %d\n", current_room -> getNeighborCount(), current_room -> neighbor_num);
            
            printf("aa\n");
            std::vector<Room::RoomDirection> freeDirs = current_room -> getFreeDirections();
            printf("aa\n");
            if(freeDirs.size() == 0){
                printf("THIS SHULDN'T HAPPEN\n");
                break; 
            }

            int random = rand() % freeDirs.size();
            printf("rand: %d\n", random);
            Room::RoomDirection dir = freeDirs[random];
            Room * new_room = new Room(Room::ROOM_UNDEFINED, dir, current_room);

            current_room -> addNeighbor(new_room, dir);
            newmap -> addRoom(new_room);
            roomsToGenerate.push(new_room);         
        }
        roomsToGenerate.pop();
    }
    printf("Newmap rooms length: %lu\n", newmap -> getRooms().size());
    return newmap;
}
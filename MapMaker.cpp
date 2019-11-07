#include "MapMaker.h"

MapMaker::MapMaker(){}

Map* MapMaker::getMap(int screen_pixel_width, int screen_pixel_height){
    Room *r = new Room(Room::ROOM_BIG);

    bool generating = true;
    while(generating){
        if(r -> neighbor_num < r -> getNeighbors().size()){
            //todo
        } else{
            //todo
        }
        break;
    }
    return new Map();
}
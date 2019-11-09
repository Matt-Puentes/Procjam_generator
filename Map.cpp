#include "Map.h"

int normalRoomWidth = 100;

Map::Map(){
    rooms.clear();
    usedPositions = std::vector<sf::Vector2f>();
}

Map::Map(std::vector<Room*> init_rooms){
    rooms = init_rooms;
    usedPositions = std::vector<sf::Vector2f>();
    for(int i = 0; i < rooms.size(); i++){
        int xpos = rooms[i] -> getPos().x;
        int ypos = rooms[i] -> getPos().y;
        int x_roomwidth_pos = xpos / normalRoomWidth;
        int y_roomwidth_pos = ypos / normalRoomWidth;
        usedPositions.push_back(sf::Vector2f(x_roomwidth_pos, y_roomwidth_pos));
    }
}

std::vector<Room*> Map::getRooms() const{
    return rooms;
}

bool Map::addRoom(Room* new_room){
    int xpos = new_room -> getPos().x;
    int ypos = new_room -> getPos().y;
    int x_roomwidth_pos = xpos / normalRoomWidth;
    int y_roomwidth_pos = ypos / normalRoomWidth;

    bool collision = false;
    for(int i = 0; i < rooms.size(); i++){
        if(usedPositions[i].x == x_roomwidth_pos && usedPositions[i].y == y_roomwidth_pos){
            collision = true;
            printf("Collision found: old room pos: (%f, %f) new room pos (%d, %d)\n", usedPositions[i].x, usedPositions[i].y, x_roomwidth_pos,  y_roomwidth_pos);
        }
    }
    // If there is no collision
    if(!collision){
        usedPositions.push_back(sf::Vector2f(x_roomwidth_pos, y_roomwidth_pos));
        rooms.push_back(new_room);
        return true;
    }
    return false;
}

int Map::drawToWindow(sf::RenderWindow *window) const{
    for(int i = 0; i < rooms.size(); i++){
        window -> draw(*(rooms[i] -> getShape()));
    }
    // TODO: Make these pretty rectangles with width.
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[i] -> getNeighborCount(); j++){
            sf::Vertex  linex[] = {
                sf::Vertex(sf::Vector2f(rooms[i]->getPos().x, rooms[i]->getPos().y)),
                sf::Vertex(sf::Vector2f(rooms[i]->getPos().x, rooms[i] -> getNeighbors()[j] -> getPos().y))
            };
            sf::Vertex  liney[] = {
                sf::Vertex(sf::Vector2f(rooms[i]->getPos().x, rooms[i] -> getNeighbors()[j] -> getPos().y)),
                sf::Vertex(sf::Vector2f(rooms[i] -> getNeighbors()[j] -> getPos().x, rooms[i] -> getNeighbors()[j] -> getPos().y))
            };
            window->draw(linex, 2, sf::Lines);
            window->draw(liney, 2, sf::Lines);
        }
    };
    return 1;
}
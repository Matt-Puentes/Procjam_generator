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
    // sf::FloatRect new_globalBounds = new_room -> getShape() -> getGlobalBounds();
    // Room* collision = 0;
    // for(int i = 0; i < rooms.size(); i++){
    //     sf::FloatRect globalBounds = rooms[i] -> getShape() -> getGlobalBounds();
    //     if(globalBounds.intersects(new_globalBounds)){
    //         collision = rooms[i];
    //         break;
    //     }
    // }
    
    // if(collision){
    //     printf("Collision!\n");
    //     if(new_room -> parent != NULL){
    //         printf("Collision!!\n");
    //         for(int i = 0; i < new_room -> parent -> neighbors.size(); i++){
    //             printf("ok....\n");
    //             printf("ok.... %lu\n", new_room -> parent -> neighbors.size());
    //             printf("ok.... %d\n", new_room -> parent -> neighbors[i]);
    //         }
    //     }
    // } else {
    //     rooms.push_back(new_room);
    // }
    // printf("bye\n");
    rooms.push_back(new_room);
    return true;
}

int Map::drawToWindow(sf::RenderWindow *window) const{
    // TODO: Make these pretty rectangles with width.
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[i] -> getNeighbors().size(); j++){
            if(rooms[i] -> getNeighbors()[j] != NULL){
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
        }
    }
    for(int i = 0; i < rooms.size(); i++){
        window -> draw(*(rooms[i] -> getShape()));
    }

    return 1;
}
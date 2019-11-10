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

std::vector<int> Map::getBounds() const{
    std::vector<int> return_vector;
    int largest_x = 0;
    int smallest_x = 1000;
    int largest_y = 0;
    int smallest_y = 1000;

    for(int i = 0; i < rooms.size(); i++){
        int high_x = rooms[i] -> getShape() -> getGlobalBounds().left + rooms[i] -> getShape() -> getGlobalBounds().width;
        int high_y = rooms[i] -> getShape() -> getGlobalBounds().top + rooms[i] -> getShape() -> getGlobalBounds().height;
        int low_x = rooms[i] -> getShape() -> getGlobalBounds().left;
        int low_y = rooms[i] -> getShape() -> getGlobalBounds().top;

        if(largest_y < high_y)
            largest_y = high_y;
        if(largest_x < high_x)
            largest_x = high_x;
        if(smallest_y > low_y)
            smallest_y = low_y;
        if(smallest_x > low_x)
            smallest_x = low_x;
    }
    return_vector.push_back(smallest_x - 100);
    return_vector.push_back(largest_x + 100);
    return_vector.push_back(smallest_y - 100);
    return_vector.push_back(largest_y + 100);
    // printf("%d, %d, %d, %d", smallest_x, largest_x, smallest_y, largest_y)
    return return_vector;
}

float Map::drawToWindow(sf::RenderTarget *window, int smallest_x, int smallest_y) const{
    // TODO: Make these pretty rectangles with width.
    printf("Gonna draw the map!\n");
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[i] -> getNeighbors().size(); j++){
            if(rooms[i] -> getNeighbors()[j] != NULL){
                sf::Vertex  linex[] = {
                    sf::Vertex(sf::Vector2f(rooms[i]->getPos().x - smallest_x, rooms[i]->getPos().y - smallest_y)),
                    sf::Vertex(sf::Vector2f(rooms[i]->getPos().x - smallest_x, rooms[i] -> getNeighbors()[j] -> getPos().y - smallest_y))
                };
                sf::Vertex  liney[] = {
                    sf::Vertex(sf::Vector2f(rooms[i]->getPos().x - smallest_x, rooms[i] -> getNeighbors()[j] -> getPos().y - smallest_y)),
                    sf::Vertex(sf::Vector2f(rooms[i] -> getNeighbors()[j] -> getPos().x - smallest_x, rooms[i] -> getNeighbors()[j] -> getPos().y - smallest_y))
                };
                window->draw(linex, 2, sf::Lines);
                window->draw(liney, 2, sf::Lines);
            }
        }
    }
    for(int i = 0; i < rooms.size(); i++){
        rooms[i] -> setPos(sf::Vector2f(rooms[i] -> getPos().x - smallest_x, rooms[i] -> getPos().y - smallest_y));
        window -> draw(*(rooms[i] -> getShape()));
    }

    return 1;
}
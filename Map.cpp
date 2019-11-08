#include "Map.h"

Map::Map(){
    rooms.clear();
}

Map::Map(std::vector<Room*> init_rooms){
    rooms = init_rooms;
}

std::vector<Room*> Map::getRooms() const{
    return rooms;
}

int Map::drawToWindow(sf::RenderWindow *window) const{
    for(int i = 0; i < rooms.size(); i++){
        window -> draw(*(rooms[i] -> getShape()));
    }
    // TODO: Make these pretty rectangles with width.
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[i] -> getNeighbors().size(); j++){
            // printf("%lu, %d\n", rooms[i] -> getNeighbors().size(), j);
            // sf::Vertex line[] = {
            //     sf::Vertex(sf::Vector2f(rooms[i] -> getPos())),
            //     sf::Vertex(sf::Vector2f(rooms[i] -> getNeighbors().at(j) -> getPos()))
            // };
            // window -> draw(line, 2, sf::Lines);

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
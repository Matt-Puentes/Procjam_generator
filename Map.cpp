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
    printf("gross\n");
    for(int i = 0; i < rooms.size(); i++){
        printf("Flag %d, %lu\n", i, rooms.size());
        window -> draw(*(rooms[i] -> getShape()));
        printf("%d\n", i);
    }
    // TODO: Make these pretty rectangles with width.
    for(int i = 0; i < ((int) rooms.size()) - 1; i++){
        printf("%d\n", i);
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(rooms[i] -> getPos())),
            sf::Vertex(sf::Vector2f(rooms[i + 1] -> getPos()))
        };
        printf("aaa\n");
        window -> draw(line, 2, sf::Lines);
		sf::Vertex  line2[] = {
			sf::Vertex(sf::Vector2f(rooms[i]->getPos().x, rooms[i + 1]->getPos().y)),
			sf::Vertex(sf::Vector2f(rooms[i + 1] -> getPos()))
		};
		window->draw(line2, 2, sf::Lines);
    };
    printf("Done Drawing Map\n");
    return 1;
}
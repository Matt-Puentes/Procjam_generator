#include <vector>
#include <SFML/Graphics.hpp>

class Room { 
    private:
        std::vector<Room*> neighbors;
        std::vector<int> position;
        sf::Shape *shape;
    public:
        Room(sf::Shape *room_shape);
        Room(sf::Shape *room_shape, std::vector<int> init_pos);
        ~Room();
        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
};
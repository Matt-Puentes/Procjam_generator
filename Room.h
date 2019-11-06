#include <vector>
#include <SFML/Graphics.hpp>

class Room { 
    private:
        std::vector<Room*> neighbors;
        sf::Shape *shape;        
    public:
        Room();
};
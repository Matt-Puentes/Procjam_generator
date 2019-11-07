#include <vector>
#include <SFML/Graphics.hpp>

class Room { 
    private:
        std::vector<Room*> neighbors;
        sf::Vector2f position;
        sf::Shape *shape;
    public:
        enum RoomType {
            ROOM_BIG,
            ROOM_SMALL,
            ROOM_CIRCLE,
            ROOM_TRIANGLE,
            ROOM_LONG,
            ROOM_WIDE
        };
        // Room(sf::Shape *room_shape, sf::Vector2f init_pos = sf::Vector2f(0, 0));
        Room(Room::RoomType room_type, sf::Vector2f init_pos = sf::Vector2f(0, 0));
        ~Room();
        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
        sf::Vector2f getPos() const;
        int neighbor_num;
};
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/Graphics.hpp>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

#include "Ellipse.h"

class Room { 
    private:
        std::vector<Room*> neighbors;
        sf::Vector2f position;
        sf::Shape *shape;

		void makeRoomBig(sf::Vector2f init_pos, int min_size, int max_size, bool rect = true);
		void makeRoomSmall(sf::Vector2f init_pos, int min_size, int max_size, bool rect = true);
		void makeRoomCircle(sf::Vector2f init_pos, int min_size, int max_size);
		void makeRoomTriangle(sf::Vector2f init_pos, int min_size, int max_size);
		void makeRoomLong(sf::Vector2f init_pos, int width_max, int width_min, int height_max, int height_min);

    public:
        enum RoomType {
            ROOM_BIG,
            ROOM_SMALL,
            ROOM_CIRCLE,
            ROOM_TRIANGLE,
            ROOM_LONG,
            ROOM_WIDE
        };
        Room(sf::Shape *room_shape, sf::Vector2f init_pos = sf::Vector2f(0, 0));
        Room(Room::RoomType room_type, sf::Vector2f init_pos = sf::Vector2f(0, 0), bool rect = true);
        ~Room();
        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
        sf::Vector2f getPos() const;
        int neighbor_num;
};
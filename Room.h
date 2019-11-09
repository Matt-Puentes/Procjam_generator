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

		void makeRoomBig(sf::Vector2f init_pos, int min_size, int max_size, bool rect = false);
		void makeRoomSmall(sf::Vector2f init_pos, int min_size, int max_size, bool rect = false);
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
            ROOM_WIDE,
            ROOM_UNDEFINED
        };
        enum RoomDirection {
            UP_FROM_PARENT,
            DOWN_FROM_PARENT,
            LEFT_FROM_PARENT,
            RIGHT_FROM_PARENT,
            ROOT
        };
        Room(sf::Shape *room_shape, sf::Vector2f init_pos = sf::Vector2f(0, 0));
        Room(Room::RoomType room_type, sf::Vector2f init_pos = sf::Vector2f(0, 0));
        Room(Room::RoomType room_type, RoomDirection dir_from_parent, Room* parent = NULL);
        ~Room();
        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
        int getNeighborCount() const;
        sf::Vector2f getPos() const;
        void setPos(sf::Vector2f new_pos);
        bool addNeighbor(Room* room, RoomDirection dir);
        std::vector<Room::RoomDirection> getFreeDirections();
        int neighbor_num;
		sf::Color getRandomColor();
};
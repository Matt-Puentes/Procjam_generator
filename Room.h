#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

class Room { 
    private:
        std::vector<Room*> neighbors;
        sf::Vector2f position;
        sf::Shape *shape;

		void makeRoomBig(sf::Vector2f init_pos);
		void makeRoomSmall(sf::Vector2f init_pos);
		void makeRoomCircle(sf::Vector2f init_pos);
		void makeRoomTriangle(sf::Vector2f init_pos);
		void makeRoomLong(sf::Vector2f init_pos);
		void makeRoomWide(sf::Vector2f init_pos);
		void makeRoomGrand(sf::Vector2f init_pos);

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
        Room(Room::RoomType room_type, sf::Vector2f init_pos = sf::Vector2f(0, 0));
        ~Room();
        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
        sf::Vector2f getPos() const;
        void addNeighbor(Room* room);
        int neighbor_num;
};
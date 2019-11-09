#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

class Room { 
    private:
        std::vector<Room*> neighbors;
        // Room* room_up;
        // Room* room_down;
        // Room* room_left;
        // Room* room_right;
        
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
        Room(Room::RoomType room_type, Room* parent, RoomDirection dir_from_parent);
        ~Room();
        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
        int getNeighborCount() const;
        sf::Vector2f getPos() const;
        void setPos(sf::Vector2f new_pos);
        bool addNeighbor(Room* room, RoomDirection dir);
        int neighbor_num;
};
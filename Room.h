#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "Ellipse.h"

class Room { 
    public:
        int roomID;
        enum RoomType {
            ROOM_BIG,
            ROOM_SMALL,
            ROOM_CIRCLE,
            ROOM_TRIANGLE,
            ROOM_RECTANGLE,
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
        Room(Room::RoomType new_room_type, RoomDirection dir_from_parent, Room* parent = NULL);
        ~Room();

        std::vector<Room*> neighbors;
        RoomDirection dir;
        Room *parent;
        int neighbor_num;
		RoomType room_type;

        sf::Shape *getShape() const;
        std::vector<Room*> getNeighbors() const;
        void setNeighbor(Room::RoomDirection dir, Room* room);
        int getNeighborCount() const;
        sf::Vector2f getPos() const;
        void setPos(sf::Vector2f new_pos);
        bool addNeighbor(Room* room, RoomDirection dir);
        std::vector<Room::RoomDirection> getFreeDirections();
		sf::Color getRandomColor();
        static sf::ConvexShape *makeConvexShape(int max_points, int min_points, int min_size, int max_size);

    private:
        sf::Vector2f position;
        sf::Shape *shape;

		void makeRoomBig(int min_size, int max_size);
		void makeRoomSmall(int min_size, int max_size);
		void makeRoomCircle(int min_size, int max_size);
		void makeRoomTriangle(int min_size, int max_size);
		void makeRoomRectangle(int width_max, int width_min, int height_max, int height_min);

		// Markov Chain
		int markov_chain[7][7] =
		{
			{5, 35, 45, 55, 75, 80, 100}, // ROOM_BIG
			{25, 35, 40, 45, 60, 85, 100}, // ROOM_SMALL
			{10, 25, 30, 45, 65, 80, 100}, // ROOM_CIRCLE
			{10, 20, 25, 30, 55, 75, 100}, // ROOM_TRIANGLE
			{25, 45, 55, 65, 70, 95, 100}, // ROOM_LONG
			{5, 35, 45, 55, 75, 80, 100}, // ROOM_RECTANGLE
			{25, 45, 55, 65, 70, 95, 100}, // ROOM_WIDE
		};
};

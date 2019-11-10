#include "Room.h"
class RoomGenerator {
    // Size constants
    int ROOM_BIG_MAX_SIZE = 0;
    int ROOM_BIG_MIN_SIZE = 0;
    int ROOM_SMALL_MAX_SIZE = 0;
    int ROOM_SMALL_MIN_SIZE = 0;
    int ROOM_CIRCLE_MAX_SIZE = 0;
    int ROOM_CIRCLE_MIN_SIZE = 0;
    int ROOM_TRIANGLE_MAX_SIZE = 0;
    int ROOM_TRIANGLE_MIN_SIZE = 0;
    int ROOM_LONG_MAX_SIZE = 0;
    int ROOM_LONG_MIN_SIZE = 0;
    int ROOM_SHORT_MAX_SIZE = 0;
    int ROOM_SHORT_MIN_SIZE = 0;

    // Neighbor number constants
    int ROOM_BIG_MAX_NEIGHBORS = 0;
    int ROOM_BIG_MIN_NEIGHBORS = 0;
    int ROOM_SMALL_MAX_NEIGHBORS = 0;
    int ROOM_SMALL_MIN_NEIGHBORS = 0;
    int ROOM_CIRCLE_MAX_NEIGHBORS = 0;
    int ROOM_CIRCLE_MIN_NEIGHBORS = 0;
    int ROOM_TRIANGLE_MAX_NEIGHBORS = 0;
    int ROOM_TRIANGLE_MIN_NEIGHBORS = 0;
    int ROOM_LONG_MAX_NEIGHBORS = 0;
    int ROOM_LONG_MIN_NEIGHBORS = 0;
    int ROOM_SHORT_MAX_NEIGHBORS = 0;
    int ROOM_SHORT_MIN_NEIGHBORS = 0;

    // Convex Shape constants
    int CONVEX_SHAPE_MAX_POINTS = 0;
    int CONVEX_SHAPE_MIN_POINTS = 0;

    public:
        sf::ConvexShape *makeConvexShape(int max_points, int min_points, int min_size, int max_size);
        sf::ConvexShape *makeEllipseShape(int max_points, int min_points, int min_size, int max_size);
        sf::ConvexShape *makeRectShape(int max_points, int min_points, int min_size, int max_size);
};

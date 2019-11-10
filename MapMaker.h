#include "Map.h"

class MapMaker {
    public:
        MapMaker();
        ~MapMaker();
        Map *map;
        Map* getMap(int screen_pixel_width, int screen_pixel_height);
    private:
        int mapsMade;
};

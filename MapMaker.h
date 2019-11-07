#include "Map.h"

class MapMaker {
    public:
        MapMaker();
        Map* getMap(int screen_pixel_width, int screen_pixel_height);
    private:
        int mapsMade;
};

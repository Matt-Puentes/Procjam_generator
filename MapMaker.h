#include "Map.h"

class MapMaker {
    public:
        MapMaker();
        virtual Map* getMap();
    private:
        int mapsMade;
};

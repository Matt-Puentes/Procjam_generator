#include "Map.h"

class MapExplorer{
    private:
        Map *map;
        Room *current_room;
        std::vector<Room*> path_to_last_inexhausted_room;
        std::vector<Room*> explored_rooms; 
        int steps_taken;
        int steps_backtracking;
        int steps_wandering;
    public:
        MapExplorer(Map *new_map);
        int exploreNode();
        Room *getCurrentRoom() const;
        bool done_exploring;
};
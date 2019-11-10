#include "MapExplorer.h"

MapExplorer::MapExplorer(Map *new_map){
    map = new_map;
    steps_taken = 0;
    steps_backtracking = 0;
    steps_wandering = 0;
    current_room = map -> getRootRoom();
    // explored_rooms.push_back(current_room);
    done_exploring = false;
}

int MapExplorer::exploreNode(){
    if(current_room == NULL){
        printf("Error: Explorer is currently in a null room.");
        return -1;
    }

    std::vector<Room *> neighbors = current_room -> getNeighbors();
    std::vector<Room *> unexplored_neighbors;

    for(int i = 0; i < neighbors.size(); i++){
        bool found = false;
        for(int j = 0; j < explored_rooms.size(); j++){
            if(neighbors[i] == explored_rooms[j])
                found = true;
        }
        if(!found)
            unexplored_neighbors.push_back(neighbors[i]);
    }

    if(unexplored_neighbors.size() > 0){
        // printf("Exploring new room\n");
        path_to_last_inexhausted_room.push_back(current_room);
        current_room = unexplored_neighbors[rand() % (unexplored_neighbors.size())];
        explored_rooms.push_back(current_room);
        steps_taken++;
    } else {
        if(path_to_last_inexhausted_room.size() > 0){
            // printf("Backtracking\n");
            current_room = path_to_last_inexhausted_room[path_to_last_inexhausted_room.size() - 1];
            path_to_last_inexhausted_room.pop_back();
            steps_taken++;
            steps_backtracking++;
        } else {
            // printf("I dont know where to go - randomly exploring\n");
            current_room = neighbors[rand() % (neighbors.size())];
            steps_taken++;
            steps_wandering++;
        }
    }

    if(explored_rooms.size() == map -> getRooms().size()){
        done_exploring = true;
        printf("It took me %d steps to explore this dungeon of size %lu!\n", steps_taken, map -> getRooms().size());
        printf("%.2f%% of my steps were spent backtracking.\n", ((double)steps_backtracking/(double)steps_taken));
    }

    if(steps_wandering > (map -> getRooms().size() * 5)){
        done_exploring = true;
        printf("I've been wandering for %d steps to explore this dungeon of size %lu...\n", steps_taken, map -> getRooms().size());
        printf("There are probably unreachable rooms in this dungeon.\n");
    }

    current_room -> explored = true;

    return 1;
}

Room *MapExplorer::getCurrentRoom() const{
    return current_room;
}

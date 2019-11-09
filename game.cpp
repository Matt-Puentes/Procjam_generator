#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MapMaker.h"

int main()
{
	srand(time(0));
    int window_width = 1920;
    int window_height = 1080;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML window");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("fonts/df-font.ttf"))
        return EXIT_FAILURE;

// 	std::vector<Room*> test_procgen_room;
//  	test_procgen_room.push_back(new Room(Room::ROOM_LONG, sf::Vector2f(400, 500)));
//  	test_procgen_room.push_back(new Room(Room::ROOM_BIG, sf::Vector2f(400, 200)));
//  	test_procgen_room.push_back(new Room(Room::ROOM_SMALL, sf::Vector2f(200, 200)));
//  	test_procgen_room.push_back(new Room(Room::ROOM_BIG, sf::Vector2f(600, 200)));

//  	Map *map = new Map(test_procgen_room);

    MapMaker mapmaker = MapMaker();
//     Map *map = mapmaker.getMap(window_width, window_height);
    // Start the game loop
    while (window.isOpen()){
        Map *map = mapmaker.getMap(window_width, window_height);
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw Map
        map -> drawToWindow(&window);

        // Update the window
        window.display();

        sf::sleep(sf::seconds(1));
    }
    return EXIT_SUCCESS;
}
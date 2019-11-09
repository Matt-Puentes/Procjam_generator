#include <SFML/Graphics.hpp>
#include "Map.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("fonts/df-font.ttf"))
        return EXIT_FAILURE;

	std::vector<Room*> test_procgen_room;
	test_procgen_room.push_back(new Room(Room::ROOM_LONG, sf::Vector2f(400, 500)));
	test_procgen_room.push_back(new Room(Room::ROOM_BIG, sf::Vector2f(400, 200), false));
	test_procgen_room.push_back(new Room(Room::ROOM_SMALL, sf::Vector2f(200, 200), false));
	test_procgen_room.push_back(new Room(Room::ROOM_WIDE, sf::Vector2f(600, 200), true));

	Map map = Map(test_procgen_room);

    // Start the game loop
    while (window.isOpen())
    {
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
        map.drawToWindow(&window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
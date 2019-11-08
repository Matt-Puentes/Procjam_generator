#include <SFML/Graphics.hpp>
#include "Map.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("fonts/df-font.ttf"))
        return EXIT_FAILURE;

	std::vector<Room*> test_procgen_room;
	test_procgen_room.push_back(new Room(Room::ROOM_SMALL, sf::Vector2f(150, 450)));
	test_procgen_room.push_back(new Room(Room::ROOM_BIG, sf::Vector2f(400, 300)));

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

        std::vector<Room*> rooms;
		rooms.push_back(new Room(Room::ROOM_BIG, sf::Vector2f(400, 450)));
		rooms.push_back(new Room(Room::ROOM_SMALL, sf::Vector2f(150, 450)));
		rooms.push_back(new Room(Room::ROOM_CIRCLE, sf::Vector2f(150, 300)));
		rooms.push_back(new Room(Room::ROOM_TRIANGLE, sf::Vector2f(150, 150)));
		rooms.push_back(new Room(Room::ROOM_WIDE, sf::Vector2f(400, 100)));
		rooms.push_back(new Room(Room::ROOM_LONG, sf::Vector2f(700, 300)));
		
		

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw Map
        map.drawToWindow(&window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
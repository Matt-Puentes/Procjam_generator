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
		rooms.push_back(new Room(new sf::CircleShape(50), sf::Vector2f(100, 100)));
		rooms.push_back(new Room(new sf::CircleShape(50), sf::Vector2f(400, 100)));
		Map map = Map(rooms);

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw Map
        map.drawToWindow(&window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
#include <SFML/Graphics.hpp>
#include "Map.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("That's real fuckin neato.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("fonts/df-font.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
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
        rooms.push_back(new Room(new sf::CircleShape(50), sf::Vector2f(50, 50)));
        rooms.push_back(new Room(new sf::RectangleShape(sf::Vector2f(50, 50)), sf::Vector2f(200, 200)));

        Map map = Map(rooms);

        // Clear screen
        window.clear();
        // Draw the sprite
        window.clear(sf::Color::Black);
        // Draw Map
        map.drawToWindow(&window);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MapMaker.h"
#include <algorithm>    // std::min

int main()
{
	srand(time(0));
    int window_width = 1920;
    int window_height = 1080;
    // int window_width = 500;
    // int window_height = 500;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML window");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("fonts/df-font.ttf"))
        return EXIT_FAILURE;

    MapMaker mapmaker = MapMaker();
    sf::RenderTexture buffer;
    buffer.create(window_width, window_height);

    // Start the game loop
    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Map *map = mapmaker.getMap(window_width, window_height);
        std::vector<int> map_bounds = map -> getBounds();
        int smallest_x = map_bounds[0];
        int smallest_y = map_bounds[2];
        printf("Boundaries: %d, %d, %d, %d\n", map_bounds[0], map_bounds[1], map_bounds[2], map_bounds[3]);
        int buffer_x = map_bounds[1] - map_bounds[0];
        int buffer_y = map_bounds[3] - map_bounds[2];
        printf("Buffer Sizes: %d, %d\n", buffer_x, buffer_y);
        buffer.create(buffer_x, buffer_y);
        buffer.clear(sf::Color::Black);


        map -> drawToWindow(&buffer, smallest_x, smallest_y);//, map_bounds[0], map_bounds[2]);

        buffer.display();
        const sf::Texture& texture = buffer.getTexture();
        sf::Sprite sprite(texture);
        window.clear(sf::Color::Blue);
        float scale_x = (float) window_width / (float) sprite.getLocalBounds().width;
        float scale_y = (float) window_height / (float) sprite.getLocalBounds().height;
        float scale = scale_x < scale_y ? scale_x : scale_y;
        sprite.setScale(scale, scale);
        sprite.setPosition((window_width/2) - sprite.getLocalBounds().width*scale/2, (window_height/2)  - sprite.getLocalBounds().height*scale/2);\
        window.draw(sprite);
        window.display();

        sf::sleep(sf::seconds(1));
    }
    return EXIT_SUCCESS;
}
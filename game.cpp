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

    MapMaker mapmaker = MapMaker();
    sf::RenderTexture buffer;
    buffer.create(window_width, window_height);

    bool render = true;

    // Start the game loop
    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                    printf("R pressed\n");
                    render = true;
                }
            }
        }

        if(render){
            // Generate the map
            Map *map = mapmaker.getMap(window_width, window_height);
            std::vector<int> map_bounds = map -> getBounds();

            // Calculate the size of the buffer
            int buffer_x = map_bounds[1] - map_bounds[0];
            int buffer_y = map_bounds[3] - map_bounds[2];

            //Create the buffer
            buffer.create(buffer_x, buffer_y);
            buffer.clear(sf::Color::Black);

            // Draw the map to the buffer
            map -> drawToWindow(&buffer, map_bounds[0], map_bounds[2]);
            buffer.display();
            
            // Turn the buffer into a sprite
            const sf::Texture& texture = buffer.getTexture();
            sf::Sprite sprite(texture);

            // Scale the sprite to fit the window size 
            float scale_x = (float) window_width / (float) sprite.getLocalBounds().width;
            float scale_y = (float) window_height / (float) sprite.getLocalBounds().height;
            float scale = scale_x < scale_y ? scale_x : scale_y;
            sprite.setScale(scale, scale);
            sprite.setPosition((window_width/2) - sprite.getLocalBounds().width*scale/2, (window_height/2)  - sprite.getLocalBounds().height*scale/2);\

            // Draw buffer to the window
            window.clear(sf::Color::Blue);
            window.draw(sprite);
            window.display();
        }
        render = false;
    }
    return EXIT_SUCCESS;
}
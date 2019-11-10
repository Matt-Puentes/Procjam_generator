#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MapMaker.h"
#include <ctime>
#include "MapExplorer.h"
#include <unistd.h>
int main()
{
	srand(time(0));
    // 1920x1080 is too big for my laptop screen, so I'm using these values
    int window_width = 960;// 1920;
    int window_height = 720;// 1080;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML window", sf::Style::Default, settings);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("fonts/df-font.ttf"))
        return EXIT_FAILURE;

    MapMaker mapmaker = MapMaker();
    sf::RenderTexture buffer;
    buffer.create(window_width, window_height);

    bool regenerate = true;
    bool explore = false;

    Map *map = mapmaker.getMap(window_width, window_height);
    sf::Shape *background_shape = Room::makeConvexShape(4, 3, 100, 150);

    MapExplorer *explorer = new MapExplorer(map);

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
                    regenerate = true;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                    explore = true;

                    // Create a new map explorer
                    delete explorer;
                    explorer = new MapExplorer(map);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    std::string filename = "./screenshots/screenshot_";
                    std::time_t result = std::time(nullptr);
                    filename += std::to_string(result);
                    filename += ".png";

                    printf("Saving image to %s\n", filename.c_str());
                    sf::Texture screenshot = sf::Texture();
                    screenshot.create(window_width, window_height);
                    screenshot.update(window);
                    sf::Image screenshot_image = screenshot.copyToImage();
                    if (!screenshot_image.saveToFile(filename))
                        printf("Error saving!\n");
                }
            }
        }
        
        if(regenerate){
            regenerate = false;
            explore = false;

            // Make a new map
            delete map;
            map = mapmaker.getMap(window_width, window_height);

            // Make a new shape
            delete background_shape;
            background_shape = Room::makeConvexShape(4, 3, 100, 150);

            explore = true;

            // Create a new map explorer
            delete explorer;
            explorer = new MapExplorer(map);
        }
        if(explore){
            // explore = false;
            explorer -> exploreNode();
        }

        if(explore || regenerate){
            std::vector<int> map_bounds = map -> getBounds();

            // Calculate the size of the buffer
            int buffer_x = map_bounds[1] - map_bounds[0];
            int buffer_y = map_bounds[3] - map_bounds[2];

            //Create the buffer
            buffer.create(buffer_x, buffer_y);
            // buffer.clear(sf::Color(111,111,111));
            buffer.clear(sf::Color::Transparent);

            // Draw the map to the buffer
            map -> drawToWindow(&buffer, map_bounds[0], map_bounds[2], explorer -> getCurrentRoom() -> roomID);
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

            // Clear window
            window.clear(sf::Color(111,111,111));

            // Draw Tiled backgroundx
            int num_x = window_width / background_shape -> getLocalBounds().width;
            int num_y = window_height / background_shape -> getLocalBounds().height;
            int offset_x = (window_width % (int) background_shape -> getLocalBounds().width) / 2;
            int offset_y = (window_height % (int) background_shape -> getLocalBounds().height) / 2;
            for(int i = 0; i < num_x; i++){
                for(int j = 0; j < num_y; j++){
                    background_shape -> setPosition(i * background_shape -> getLocalBounds().width + offset_x, j * background_shape -> getLocalBounds().height + offset_y);
                    background_shape -> setFillColor(sf::Color(120, 120, 120));
                    window.draw(*background_shape);
                }
            }

            // Draw buffer to the window
            window.draw(sprite);

            // Finalize and display the window        
            window.display();
    
            if(explorer -> done_exploring)
                explore = false;
        }
        usleep(100000);
    }
    return EXIT_SUCCESS;
}
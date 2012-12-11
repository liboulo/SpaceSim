#include "ConnectionHandler.h"
//#include "Connection.h"


#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


//First, include/compile the meta-simulation
#include "Region.h"

//Second, include and compile the game itself.
#include "Atom.h"

//Finally, include and compile the network handling.
#include "Network.h"

std::vector <Region> regions;
Network network;
unsigned long server_tick = 0;
bool server_running = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(560, 294), "SpaceSim Client");
    sf::Font font( sf::Font::getDefaultFont() );

    char output[24][80];

    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            output[i][j] = (int)'0' + i%10;
        }
    }

    sf::Text current_output (output[1], font, 12);

    server_running = true;
    Region world ("world");
    regions.push_back(world);

    ZLevel* level = new ZLevel(10,10);
    level->Populate();

    world.SetLevel(level);


    while (server_running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                server_running = false;
            }
        }

        window.clear();
        for(int i = 0; i < 24; i++)
        {
            current_output.setString(output[i]);
            current_output.setPosition(0,(float) (i*14));
            window.draw(current_output);
        }
        window.display();
        server_tick++;

        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include "Atom.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SpaceSim Client");

    sf::Font font( sf::Font::getDefaultFont() );
    sf::Text current_output ("Hello World, Connecting to 98.165.131.120", font, 14);
//    sf::Text current_command ("\t>", font, 14);
//    current_command.setPosition(0, 14*2);

    sf::UdpSocket socket;
    socket.bind(2556);
    socket.setBlocking(false);
    sf::IpAddress ServerAddress = "192.168.1.101";
    int i = 0;


    while (window.isOpen())
    {
        sf::Packet Packet;

        Packet << "Hello, server!" << i;
        socket.send(Packet, ServerAddress, 2556);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
        window.draw(current_output);
//       window.draw(current_command);
        window.display();
        i++;
        sf::sleep(sf::milliseconds(1000));
    }

    return 0;
}

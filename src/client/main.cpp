
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>


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
    sf::IpAddress ServerAddress = sf::IpAddress::getPublicAddress();
    sf::Packet Packet;

    Packet << "Hello, server!";
    socket.send(Packet, ServerAddress, 2556);

    while (window.isOpen())
    {
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
        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}

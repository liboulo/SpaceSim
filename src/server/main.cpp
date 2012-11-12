#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SpaceSim Server");
    sf::IpAddress ServerAddress = sf::IpAddress::getPublicAddress();

    sf::Font font( sf::Font::getDefaultFont() );
    sf::Text current_output ("Hello World, Server is booted, and open on " + ServerAddress.toString() + "\nPress \"Esc\" to close the program.\n", font, 14);
//    sf::Text current_command ("\t>", font, 14);
//    current_command.setPosition(0, 14*2);

    sf::UdpSocket socket;
    socket.bind(2556);
    socket.setBlocking(false);
    sf::IpAddress ClientAddress;
    sf::Packet Packet;
    unsigned short port;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }
        while (socket.receive(Packet, ClientAddress, port) == sf::Socket::Done)
        {
            std::string s;
            Packet >> s;
            current_output.setString(current_output.getString() + "Received packet containing \"" + s + "\" from " + ClientAddress.toString());
        }

        window.clear();
        window.draw(current_output);
//       window.draw(current_command);
        window.display();
        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}

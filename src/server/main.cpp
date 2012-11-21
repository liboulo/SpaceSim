#include <SFML/Network.hpp>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstddef> // size_t is a typedef on an unsigned int
#include "Connection.h"
#include <vector>

std::vector <Connection> connections;
sf::IpAddress server_address;
sf::UdpSocket socket;
bool server_running;
std::string current_command;

int main()
{
    server_address = sf::IpAddress::getPublicAddress();

    socket.bind(2556);
    socket.setBlocking(false);
    server_running = true;

    std::cout << "SpaceSim Server started, public IP address: " << server_address << std::endl;
    std::cout << "Awaiting commands and/or connections." << std::endl << std::endl;
    current_command = " >";
    std::cout << current_command;

    sf::Packet packet;
    sf::IpAddress client_address;
    unsigned short remote_port;

    while (server_running)
    {
  //      char c = getchar();
  //      if(c && c > 31)
  //      {
  //          current_command += c;
  //          std::cout << "\r" << current_command;
  //      }
        while (socket.receive(packet, client_address, remote_port) == sf::Socket::Done)
        {
            std::string s;
            int number;
            packet >> s;
            packet >> number;
            std::cout << "\r\b\t" << "Message from " << client_address.toString() << ": " << s << " " << number;
        }

  //      window.clear();
 //       window.draw(current_output);
//       window.draw(current_command);
 //       window.display();
        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}

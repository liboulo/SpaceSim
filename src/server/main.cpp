#include "ConnectionHandler.h"
//#include "Connection.h"

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

std::vector <ConnectionHandler> connections;
//Connection* connection;
sf::IpAddress server_address;
unsigned long server_tick = 0;

int main()
{
    server_address = sf::IpAddress::getPublicAddress();
    bool server_running = true;
    std::string current_command;

//    connection = new Connection(2556);

    std::cout << "SpaceSim Server started, public IP address: " << server_address << std::endl;
    std::cout << "Awaiting commands and/or connections." << std::endl << std::endl;
    current_command = " >";
    std::cout << current_command;

    while (server_running)
    {
  //      char c = getchar();
  //      if(c && c > 31)
  //      {
  //          current_command += c;
  //          std::cout << "\r" << current_command;
  //      }
   //     connection->ParsePackets();

  //      window.clear();
 //       window.draw(current_output);
//       window.draw(current_command);
 //       window.display();
        server_tick++;

        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}

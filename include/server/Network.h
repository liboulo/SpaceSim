#ifndef NETWORK_H
#define NETWORK_H

#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <unordered_map>

#include "ConnectionHandler.h"

class Network
{
    public:
        /** Default constructor */
        Network();
        /** Default destructor */
        virtual ~Network();

        bool Tick(); //Processes any and all updates to the clients.
    protected:
    private:
        enum InformationType
        {
            ConnectionRequest,
            ClientCommand,
            Disconnection
        };
        //Technical variables, directly related to the connection.
        sf::UdpSocket socket; //The connection itself.
        sf::IpAddress ip_address; //Holds the IP address of the packet currently being processed.
        sf::Packet packet; //Current packet.
        unsigned short port; //Connected port from client.
        char buffer[];

        //Variables holding information on stored connections.
        std::string public_address; //Determined on startup.
        std::vector <ConnectionHandler> connections; //Holds all connections.
        std::map <std::string, ConnectionHandler*> users; //Links usernames to connections.
        std::map <sf::IpAddress, std::vector< ConnectionHandler* > > addresses; //Links IP address to clients.  Holds a vector in case of multiple-clients from one IP.

        //Variables containing recent attempted connections.
        std::map <sf::IpAddress, unsigned short> recent_connections; //Holds IP address data and a short int for how many hunredths of a second since data was received.
};
#endif // NETWORK_H

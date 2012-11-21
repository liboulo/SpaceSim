#ifndef CONNECTION_H
#define CONNECTION_H
#include <SFML/Network.hpp>
#include <string>

class Connection
{
    public:
        /** Default constructor */
        Connection( std::string& user, sf::IpAddress& connected_address, unsigned short& local_identifier );
        /** Default destructor */
        virtual ~Connection();
        bool ParsePacket(sf::Packet& Packet);
    protected:
    private:
        std::string display_name; //Needs to be unique on the server.
        std::string user_name; //display_name with any spacing, and punctuation removed, switched to lowercase.
        sf::IpAddress ip_address; //The last known IP address that the client connected from, used for sending data back to the client.
        unsigned short identifier; //Used to allow multiple users behind one router/etc. to connect without stupid issues.
        unsigned long last_confirmed_update; //Last tick the client confirmed receiving.  Send everything from here to present.
        unsigned long idle_time; //How long since command from them?
        unsigned long no_response_time; //How many ticks has it been since the last received packet?
};

#endif // CONNECTION_H

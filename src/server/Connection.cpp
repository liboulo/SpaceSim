#include "Connection.h"

std::string trim_username(std::string user_name)
{
    /*char input [] = user_name;
    std::string output;

    for(int i = 0; i < user_name.length(); i++)
    {
        if(user_name[i] > "a")
    }*/
    return user_name;
}

Connection::Connection( std::string& user, sf::IpAddress& connected_address, unsigned short& local_identifier )
{
    display_name = user;
    user_name = trim_username(user);
    ip_address = sf::IpAddress (connected_address.toInteger());
    identifier = local_identifier;

}

Connection::~Connection()
{

}

bool Connection::ParsePacket(sf::Packet& Packet)
{

}

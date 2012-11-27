#include "ConnectionHandler.h"

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

ConnectionHandler::ConnectionHandler( std::string& user, sf::IpAddress& connected_address, unsigned short& local_identifier )
{
    display_name = user;
    user_name = trim_username(user);
    ip_address = sf::IpAddress (connected_address.toInteger());
    identifier = local_identifier;

}

ConnectionHandler::~ConnectionHandler()
{

}

bool ConnectionHandler::ParsePacket(sf::Packet& Packet)
{
    return true;
}

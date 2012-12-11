#include "Network.h"

Network::Network()
{
    socket.bind(2556);
    socket.setBlocking(false);
}

Network::~Network()
{
    //dtor
}

bool Network::Tick()
{
    InformationType information;
    unsigned int buffer_size;
    while(socket.receive(packet, ip_address, port) == sf::Socket::Done)
    {
        if(addresses.find(ip_address) != addresses.end())
        {
            while(!packet.endOfPacket())
            {
//                packet >> information >> buffer_size;
            }
        }
        else if(information == ConnectionRequest)
        {

        }

    }
    return true;
}

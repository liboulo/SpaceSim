#include "Icon.h"

Icon::Icon()
{
    //ctor
}

Icon::~Icon()
{
    //dtor
}

sf::Texture* Icon::GetTexture(std::string icon_state, Direction dir)
{
    try
    {
        return icon_states[icon_state].GetTexture(dir);
    }
    catch(std::exception &e)
    {
        return NULL;
    }
}

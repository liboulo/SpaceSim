#include "Tile.h"

Tile::Tile(Atom* location) : Atom(location)
{
    //ctor
}

Tile::Tile(unsigned long x, unsigned long y, unsigned long z, unsigned short region) : Atom(x,y,z,region)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->region = region;
}

Tile::~Tile()
{
    //dtor
}

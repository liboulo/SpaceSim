#include "Tile.h"

Tile::Tile(Atom* location) : Atom(location)
{
    //ctor
}

Tile::Tile(unsigned long x, unsigned long y, unsigned long z) : Atom(x,y,z)
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

#include "ZLevel.h"

ZLevel::ZLevel(unsigned long _x, unsigned long _y)
{
    this->x = _x;
    this->y = _y;
    //ctor
}

ZLevel::~ZLevel()
{
    //dtor
}

bool ZLevel::Populate()
{
    if(level_map.size() != x)
    {
        level_map.resize(x);
    }
    for(unsigned long i = 1; i < x; i++)
    {
        if(level_map[i].size() != y)
        {
            level_map[i].resize(y);
        }
        for(unsigned long j = 1; j < y; j++)
        {
            level_map[i][j] = new Tile(x,y,z,region);
        }
    }
    return true;
}

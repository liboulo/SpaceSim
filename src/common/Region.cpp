#include "Region.h"

Region::Region(std::string name)
{
    this->name = name;
}

Region::~Region()
{
    //dtor
}

ZLevel* Region::GetLevel(int z)
{
    try
    {
        return levels.at(z);
    }
    catch (std::out_of_range& e)
    {
        return NULL;
    }
}

void Region::SetLevel(ZLevel* level, int z)
{
    try
    {
        levels.at(z) = level;
    }
    catch (std::out_of_range& e)
    {
        levels.push_back(level);
    }
}

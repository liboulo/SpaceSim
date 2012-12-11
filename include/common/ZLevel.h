#ifndef ZLEVEL_H
#define ZLEVEL_H

#include "Tile.h"

#include <vector>

class ZLevel
{
    public:
        /** Default constructor */
        ZLevel(unsigned long x, unsigned long y);
        /** Default destructor */
        virtual ~ZLevel();
        bool Populate();
    protected:
    private:
        std::vector< std::vector <Tile*> > level_map;
        unsigned long x;
        unsigned long y;
        unsigned long z;
        unsigned short region;
};

#endif // ZLEVEL_H

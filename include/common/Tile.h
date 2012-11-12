#ifndef TILE_H
#define TILE_H

#include <Atom.h>


class Tile : public Atom
{
    public:
        /** Default constructor */
        Tile();
        /** Default destructor */
        virtual ~Tile();
        short x;
        short y;
        short z;
    protected:
    private:
};

#endif // TILE_H

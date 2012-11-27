#ifndef TILE_H
#define TILE_H

#include <Atom.h>


class Tile : public Atom
{
    public:
        Tile(Atom* location);
        Tile(unsigned long x, unsigned long y, unsigned long z);
        /** Default destructor */
        virtual ~Tile();
    protected:
    private:
};

#endif // TILE_H

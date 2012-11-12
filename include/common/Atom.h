#ifndef ATOM_H
#define ATOM_H

#include <vector>

class Atom
{
    public:
        /** Default constructor */
        Atom();
        /** Default destructor */
        virtual ~Atom();
        std::vector <Atom*> contents;
    protected:
    private:
};

#endif // ATOM_H

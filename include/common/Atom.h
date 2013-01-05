#ifndef ATOM_H
#define ATOM_H

#include <vector>
#include <unordered_map>
#include <string>

#include "utilities.h"

#ifdef VERSION_CLIENT

#endif

class Atom
{
    public:
        /** Default constructor */
        Atom(Atom* location);
        Atom(unsigned long _x, unsigned long _y, unsigned long _z, unsigned short _region);
        /** Default destructor */
        virtual ~Atom();

        std::vector <Atom*> contents;
        std::string GetIcon() {return icon;}
        std::string GetIconState() {return icon_state;}
        std::string GetIconAndState() {return icon + "|" + icon_state;}
        void SetIcon(std::string new_icon);
        void SetIconState(std::string new_icon_state);
        void SetIconAndState(std::string new_icon, std::string new_icon_state);

        bool Move(int x, int y, int z);
        bool Move(Atom &target);
        bool Move(Direction dir);

#ifdef VERSION_CLIENT

#endif
    protected:
        std::string icon_state; //Icon state of the atom
        std::string icon; //Path to the icon file.

        Atom* loc;

        unsigned long x;
        unsigned long y;
        unsigned long z;
        unsigned short region;


#ifdef VERSION_CLIENT

#endif
    private:
};

#endif // ATOM_H

#ifndef ATOM_H
#define ATOM_H

#include <vector>
#include <unordered_map>
#include <string>

#ifdef VERSION_CLIENT
#include "Sprite.h"
#endif


class Atom
{
    public:
        /** Default constructor */
        Atom(Atom* location);
        Atom(unsigned long x, unsigned long y, unsigned long z);
        /** Default destructor */
        virtual ~Atom();

        std::vector <Atom*> contents;
        std::string GetIcon() {return icon;}
        std::string GetIconState() {return icon_state;}
        std::string GetIconAndState() {return icon + "|" + icon_state;}
        void SetIcon(std::string new_icon);
        void SetIconState(std::string new_icon_state);
        void SetIconAndState(std::string new_icon, std::string new_icon_state);

#ifdef VERSION_CLIENT
        sf::Texture* GetTexture() {return sprite->GetTexture();}
        Sprite* GetSprite() {return sprite;}
        void SetSprite(Sprite* new_sprite) {sprite = new_sprite;}
#endif
    protected:
    private:
        std::string icon_state; //Icon state of the atom
        std::string icon; //Path to the icon file.

        Atom* loc;
        unsigned long x;
        unsigned long y;
        unsigned long z;


#ifdef VERSION_CLIENT
        Sprite* sprite; //Handled client side only, maps the icon state string to the pointer of a texture.
#endif
};

#endif // ATOM_H

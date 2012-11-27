#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>



class Sprite
{
    public:
        /** Default constructor */
        Sprite();
        /** Default destructor */
        virtual ~Sprite();
        sf::Texture* GetTexture();
    protected:
    private:

};

#endif // SPRITE_H

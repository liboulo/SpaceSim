#ifndef SPRITE_H
#define SPRITE_H
/*
The Sprite class handles textures, both static and "movies" composed of several.
The AnimatedSprite and StaticSprite class inherit from it, so that a Sprite class variable can hold either and get the proper texture to display from either.

Used by Icons to represent icon states.

Functions:
GetTexture()
    Takes - Direction
    Returns - sf::Texture pointer of the current frame in the specified Direction
DeltaTime(time)
    Takes - unsigned short value representing the time since the last frame
    Returns - Nothing
SetTime(time)
    Takes - unsigned short value representing the absolute amount of time into the movie.
    Returns - Nothing
*/
#include <SFML/Graphics.hpp>
#include <utilities.h>
#include <vector>
#include <stdexcept>

class Sprite
{
    public:
        Sprite() {}
        virtual ~Sprite() {}
        sf::Texture* GetTexture(Direction dir) {return NULL;}
        void DeltaTime(unsigned short time) {}
        void SetTime(unsigned short time) {}
        bool CheckDirection(Direction dir);
        friend class DMILoader;

    protected:
        std::vector <Direction> dirs;
};

class StaticSprite: public Sprite
{
    public:
        StaticSprite() {}
        virtual ~StaticSprite() {}
        sf::Texture* GetTexture(Direction dir);
        bool AddDirection(sf::Texture* new_texture, Direction dir);

    protected:
        std::map <Direction, sf::Texture*> texture; //Simply the texture that this sprite is storing
};

class AnimatedSprite: public Sprite
{
    public:
        AnimatedSprite() {}
        virtual ~AnimatedSprite() {}
        void AddFrame(StaticSprite* new_frame, unsigned short time);
        sf::Texture* GetTexture(Direction dir);
        void DeltaTime(unsigned short time);
        void SetTime(unsigned short time);

    protected:
        unsigned short total_time; //How long the movie is.
        unsigned short current_time; //What point in the movie this is.
        unsigned short frame; //What the current frame is.
        std::vector < StaticSprite* > frames; //Holds the textures of the frames as a static sprite.
        std::vector < unsigned short > timings; //Holds the start time for each frame.
};
#endif // SPRITE_H

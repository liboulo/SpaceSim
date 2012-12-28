#ifndef ICON_H
#define ICON_H
/*
The Icon class wraps multiple Sprites (Images and Movies) into a single object, arranged by string.
*/
#include "Sprite.h"
#include <string>
#include <unordered_map>

class Icon
{
    public:
        Icon();
        virtual ~Icon();
        sf::Texture* GetTexture(std::string icon_state, Direction dir);
        friend class DMILoader;

    protected:
        std::unordered_map <std::string, Sprite> icon_states; //
};

#endif // ICON_H

#include "Sprite.h"

bool Sprite::CheckDirection(Direction dir)
{
    return std::find(dirs.begin(), dirs.end(), dir)!=dirs.end();
}

sf::Texture* StaticSprite::GetTexture(Direction dir)
{
    try
    {
        return texture[dir];
    }
    catch(std::exception& e)
    {
        return NULL;
    }
}

bool StaticSprite::AddDirection(sf::Texture* new_texture, Direction dir)
{
    if(texture[dir] != NULL)
    {
        return false;
    }
    texture[dir] = new_texture;
    dirs.push_back(dir);
    return true;
}

sf::Texture* AnimatedSprite::GetTexture(Direction dir)
{
    return frames[frame]->GetTexture(dir);
}

void AnimatedSprite::AddFrame(StaticSprite* image, unsigned short time)
{
    for(unsigned int i = 0; i < dirs.size(); i++)
    {
        if( !image->CheckDirection( dirs[i] ) )
        {
            dirs.erase(dirs.begin()+i);
            i--;
        }
    }
    frames.push_back(image);
    timings.push_back(total_time);
    total_time += time;
}

void AnimatedSprite::DeltaTime(unsigned short time)
{
    current_time = (current_time + time) % total_time;
    for(unsigned int i = 1; i < timings.size(); i++)
    {
        if(timings[i] >= current_time)
        {
            break;
        }
        frame = i;
    }
}

void AnimatedSprite::SetTime(unsigned short time)
{
    current_time = time;
    for(unsigned int i = 1; i < timings.size(); i++)
    {
        if(timings[i] >= current_time)
        {
            break;
        }
        frame = i;
    }
}

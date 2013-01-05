#ifndef REGION_H
#define REGION_H

#include "ZLevel.h"

#include <vector>
#include <string>
#include <stdexcept>

class Region
{
    public:
        /** Default constructor */
        Region(std::string _name);
        Region(std::string name, std::string map_file);
        /** Default destructor */
        virtual ~Region();

        ZLevel* GetLevel(int z);
        void SetLevel(ZLevel* level, int z = -1);

    protected:
    private:
        std::string name;
        std::vector<ZLevel*> levels;
        unsigned short region;
};

class PlanetaryBase: public Region
{

};

#endif // REGION_H

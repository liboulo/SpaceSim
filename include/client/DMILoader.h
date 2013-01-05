#ifndef DMILOADER_H
#define DMILOADER_H

#include <fstream>
#include "Icon.h"


class DMILoader
{
    public:
        DMILoader();
        virtual ~DMILoader();
        Icon* LoadFile(std::string file_path);
    protected:
    private:
        std::unordered_map <std::string, Icon> icons;
};

#endif // DMILOADER_H

#include "DMILoader.h"

DMILoader::DMILoader()
{
    //ctor
}

DMILoader::~DMILoader()
{
    //dtor
}

Icon* DMILoader::LoadFile(std::string file_path)
{
    std::ifstream data_stream;
    data_stream.open(file_path, std::ifstream::in);


    data_stream.close();
    return NULL;
}

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
    if(icons.find(file_path) != icons.end())
    {
        return &icons[file_path];
    }
    std::ifstream data_stream (file_path.c_str(), std::ifstream::in);
    std::filebuf *filebuffer = data_stream.rdbuf();
    long size = filebuffer->pubseekoff (0, std::ios::end, std::ios::in);
    char buffer[size];
    filebuffer->sgetn(buffer, size);


    data_stream.close();
    return NULL;
}

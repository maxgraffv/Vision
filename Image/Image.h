#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include "Matrix.h"

class Image : public Matrix
{
    private:
        const char* path;
        uint8_t* buffer;
        friend class QtImage;


    public:
        Image(int width, int height, const char* path);
        int load(const char* path);
        int reload();


};



#endif
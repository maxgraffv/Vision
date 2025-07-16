#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include "Matrix.h"

class Image : public Matrix<uint8_t>
{
    private:
        const char* path;
        // uint8_t* buffer;

        friend class QtImage;


    public:
        Image(int width, int height, const char* path);
        int load(const char* path);
        int reload();


};



#endif
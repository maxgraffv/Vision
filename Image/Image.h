#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include "Matrix.h"

class Image : public Matrix<uint8_t>
{
    private:
        const char* path;

        friend class QtImage;


    public:
        Image(int width, int height, const char* path);
        virtual ~Image();
        int load(const char* path);
        int reload();


};



#endif
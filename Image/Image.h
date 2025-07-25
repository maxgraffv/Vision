#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include "Matrix.h"
#include "Pixel.h"

class Image : public Matrix<float>
{
    private:
        const char* path;

        friend class QtImage;


    public:
        Image(int width, int height, const char* path);
        virtual ~Image();
        int load(const char* path);
        virtual void refresh() = 0;
        void applyKernel(Matrix<float>& kernel);
        Pixel getPixel(int i);
        Pixel getPixel(int x, int y);
        



};



#endif
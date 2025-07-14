#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>

class Pixel
{
    private:
        uint8_t _red, _green, _blue;

        friend class Image;


    public:
        Pixel();
        Pixel(uint8_t r, uint8_t g, uint8_t b);

        uint8_t red();
        uint8_t green();
        uint8_t blue();

        /*
            !!! OVERLOAD Operators
        */

};

#endif
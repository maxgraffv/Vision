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
       Pixel& operator*(double x)
       {
            _red = (uint8_t)((double)(_red) * x);
            _green = (uint8_t)((double)(_green) * x);
            _blue = (uint8_t)((double)(_blue) * x);

            if(_red > 255) _red = 255;
            if(_green > 255) _green = 255;
            if(_blue > 255) _blue = 255;
       }

};

#endif
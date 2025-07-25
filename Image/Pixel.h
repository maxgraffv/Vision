#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>
#include <iostream>

class Pixel
{
    private:
        double _red, _green, _blue;

        friend class Image;

        void valueCheck(double* pix);

    public:
        Pixel();
        Pixel(double r, double g, double b);

        double red();
        double green();
        double blue();

        Pixel operator*(double x);
        Pixel& operator+=(const Pixel& other);
};

#endif
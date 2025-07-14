#include "Pixel.h"

Pixel::Pixel()
{
    Pixel(0, 0, 0);
}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
{
    _red = r;
    _green = g;
    _blue = b;
}

uint8_t Pixel::red()
{
    return _red;
}

uint8_t Pixel::green()
{
    return _green;
}

uint8_t Pixel::blue()
{
    return _blue;
}
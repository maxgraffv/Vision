#include "Pixel.h"

Pixel::Pixel()
{
    Pixel(0, 0, 0);
}

Pixel::Pixel(double r, double g, double b)
{
    _red = r;
    _green = g;
    _blue = b;
}

double Pixel::red()
{
    return _red;
}

double Pixel::green()
{
    return _green;
}

double Pixel::blue()
{
    return _blue;
}

void Pixel::valueCheck(double* pix)
{
    if(*pix > 255)
        *pix = 255;
    if(*pix < 0)
        *pix = 0;
}

Pixel& Pixel::operator+=(const Pixel& other)
{

    double rd = (double)(this->red());
    double gd = (double)(this->green());
    double bd = (double)(this->blue());

    rd += (double)(other._red);
    gd += (double)(other._green);
    bd += (double)(other._blue);

    this->_red = rd;
    this->_green = gd;
    this->_blue = bd;

    return *this;
}

Pixel Pixel::operator*(double x)
{
    double rd = (double)(this->red());
    double gd = (double)(this->green());
    double bd = (double)(this->blue());

    rd *= x;
    gd *= x;
    bd *= x;

    this->_red = rd;
    this->_green = gd;
    this->_blue = bd;

    return Pixel(rd, gd, bd);
}
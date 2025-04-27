#include "Matrix.h"

#include <stdio.h>
#include <iostream>

Matrix::Matrix()
{
    this->width = 0;
    this->height = 0;
    this->data = std::vector<float>();
}


Matrix::Matrix(int w, int h)
{
    this->width = w;
    this->height = h;
    this->data = std::vector<float>(width*height, 0.0);
}


int Matrix::getHeight()
{
    return this->height;
}


int Matrix::getWidth()
{
    return this->width;
}


void Matrix::setHeight(int h)
{
    this->height = h;
}


void Matrix::setWidth(int w)
{
    this->width = w;
}


float* Matrix::get_p( int i )
{
    if(i < 0 || i >= data.size())
        return nullptr;
    else
        return &data[i];
}


float* Matrix::get_p(int x, int y)
{
    return get_p( this->width * y + x );
}


int Matrix::set(int i, float v)
{
    if(i < 0 || i >= data.size())
        return 1;
    else
    {
        data[i] = v;
        return 0;
    }

}


int Matrix::set(int x, int y, float t)
{
    return set( this->width * y + x, t );
}


void Matrix::print()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            std::cout << *this->get_p(j, i);

        std::cout << std::endl;
    }
}


Matrix* Matrix::createIdentityMatrix(int size)
{
    Matrix* m = new Matrix(size, size);
    for(int y = 0; y < m->getHeight(); y++)
        for(int x = 0; x < m->getWidth(); x++)
            if( x == y )
                m->set(x,y, 1.0);
    
    return m;
}


Matrix* Matrix::getMinor(int x, int y, int w, int h)
{
    int max_x = this->getWidth() - 1;
    int max_y = this->getHeight() - 1;
    int max_w = this->getWidth() - x;
    int max_h = this->getHeight() - y;

    Matrix* minor = new Matrix(w,h);

    int minor_x = 0;
    int minor_y = 0;

    for(int i = y; i < (y+h); i++)
    {
        for(int j = x; j < (x+w); j++)
        {
            float v = *this->get_p(i, j);
            minor->set(minor_x, minor_y, v );

            minor_x++;
        }
        minor_x = 0;
        minor_y++;
    }

    return minor;
}



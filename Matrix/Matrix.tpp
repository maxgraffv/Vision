#include "Matrix.h"

#include <stdio.h>
#include <iostream>

template<typename T> 
Matrix<T>::Matrix()
{
    this->width = 0;
    this->height = 0;
    this->data = std::vector<float>();
}


template<typename T> 
Matrix<T>::Matrix(int w, int h) : width(w), height(h), _buffer(std::vector<T>(w*h*3))
{
    
}

template<typename T> 
Matrix<T>::~Matrix()
{

}

template<typename T> 
int Matrix<T>::getHeight()
{
    return this->height;
}


template<typename T> 
int Matrix<T>::getWidth()
{
    return this->width;
}


template<typename T> 
void Matrix<T>::setHeight(int h)
{
    this->height = h;
}


template<typename T> 
void Matrix<T>::setWidth(int w)
{
    this->width = w;
}

template<typename T> 
std::vector<T>& Matrix<T>::buffer()
{
    return _buffer;
}

template<typename T> 
void Matrix<T>::print()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            std::cout << *this->get_p(j, i);

        std::cout << std::endl;
    }
}


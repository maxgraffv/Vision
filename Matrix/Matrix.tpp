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
            std::cout << this->_buffer[(i*width) + j];

        std::cout << std::endl;
    }
}


template<typename T> 
Matrix<T> Matrix<T>::mat(T* element, int w, int h)
{
    Matrix<T> mat(w, h);

    int totalLen = w * h;
    int i = 0;
    auto iter = mat._buffer.begin();

    mat._buffer.clear();
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            mat._buffer.push_back(element[i]);
            i++;
        }
    }
    return mat;
}

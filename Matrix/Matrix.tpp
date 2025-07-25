#include "Matrix.h"

#include <stdio.h>
#include <iostream>

template<typename T> 
Matrix<T>::Matrix()
{
    this->width = 0;
    this->height = 0;
    this->_buffer = std::vector<T>();
}


template<typename T> 
Matrix<T>::Matrix(int w, int h) : width(w), height(h), _buffer(std::vector<T>(w*h))
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


template<typename T> 
Matrix<T> Matrix<T>::operator*(Matrix<T>& other)
{
    int A_h = this->height;
    int A_w = this->width;
    int B_h = other.height;
    int B_w = other.width;

    int newSize = A_h * B_w;
    T C[B_w][A_h];


    if( A_w != B_h)
    {
        printf("Unable for matmul. Wrong size\n");
    }
    else
    {
        for (int i = 0; i < A_h; ++i)
            for (int k = 0; k < A_w; ++k)
                for (int j = 0; j < B_w; ++j)
                    C[i][j] += this->_buffer[(this->width * i) +k] * other._buffer[(other.width*k) +j];

    }

    Matrix<T> ret;
    ret = Matrix<T>::mat(&C[0][0], B_w, A_h);
    return ret;
}

template<typename T> 
Matrix<T>& Matrix<T>::operator*(double v)
{
    for(int i = 0; i < this->buffer().size(); i++)
    {
        this->buffer()[i] *= v;
    }

    return *this;
}

template<typename T> 
void Matrix<T>::applyKernel(Matrix<T>& kernel)
{

}
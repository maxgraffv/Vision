#ifndef MATRIX_H
#define MATRIX_H

#include <vector>



template <typename T>
class Matrix
{
    private:
        std::vector<T> _buffer;
        int width;
        int height;

    public:
        Matrix();
        Matrix(int w, int h);
        virtual ~Matrix();


        int getHeight();
        int getWidth();
        void setHeight(int h);
        void setWidth(int w);

        std::vector<T>& buffer();
        static Matrix<T> mat(T* element, int w, int h);

        void print();
        Matrix<T> operator*(Matrix<T>& other);
        Matrix<T>& operator*(double v);
        void applyKernel(Matrix<T>& kernel);
        

};

#include "Matrix.tpp"

#endif
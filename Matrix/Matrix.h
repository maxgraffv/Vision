#ifndef MATRIX_H
#define MATRIX_H

#include <vector>



class Matrix
{
    private:
        std::vector<float> data;
        int width;
        int height;

    public:
        Matrix();
        Matrix(int w, int h);


        int getHeight();
        int getWidth();
        void setHeight(int h);
        void setWidth(int w);


        float* get_p(int i);
        float* get_p(int x, int y);

        int set(int i,float v);
        int set(int x, int y,float v);


        Matrix* getMinor(int x, int y, int w, int h);
        int replaceWith(int x, int y, Matrix* m);


        int addAt(int x, int y, Matrix* m);
        int mulAt(int x, int y, Matrix* m);


        void print();


        static Matrix* createIdentityMatrix(int size);

        static Matrix* multiply(Matrix* m1, Matrix* m2);
        static Matrix* add(Matrix* m1, Matrix* m2);




};


#endif
#ifndef DATA_COMPUTE_H
#define DATA_COMPUTE_H

#include "Image.h"
#include "Matrix.h"
#include "QtImage.h"

class DataCompute
{
   private:
    float *A, *B, *C;
   
    public:
        DataCompute();
        ~DataCompute();
        void compute(float* A, float* B, float* C);
        void printC();

        void applyKernel(QtImage& img, Matrix<float>& kernel);



};





#endif

#ifndef DATA_COMPUTE_H
#define DATA_COMPUTE_H


class DataCompute
{
   private:
    float *A, *B, *C;
   
    public:
        DataCompute();
        ~DataCompute();
        void compute(float* A, float* B, float* C);
        void printC();



};





#endif

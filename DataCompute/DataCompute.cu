#include "DataCompute.h"
#include <iostream>
#include <cuda_runtime.h>

__global__ void xMul(const float* A, const float* B, float* out)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if(idx < 1)
    {
        out[idx] = A[idx] * B[idx];
        printf("GPU: A = %f, B = %f, out = %f\n", A[idx], B[idx], out[idx]);
    }
}


DataCompute::DataCompute()
{
    (this->A) = (float*)malloc(sizeof(float));
    *(this->A) = 5.f;

    (this->B) = (float*)malloc(sizeof(float));
    *(this->B) = 7.5;

    (this->C) = (float*)malloc(sizeof(float));
    *(this->C) = 0.0;
}

DataCompute::~DataCompute()
{
    free(this->A);
    free(this->B);
    free(this->C);
}


void DataCompute::compute(float* A, float* B, float* C)
{
    printf("check\n");
    float *A_in = nullptr, *B_in = nullptr, *C_out = nullptr;
    cudaMalloc(&A_in, sizeof(float));
    cudaMalloc(&B_in, sizeof(float));
    cudaMalloc(&C_out, sizeof(float));
    printf("check\n");

    cudaMemcpy(A_in, A, sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(B_in, B, sizeof(float), cudaMemcpyHostToDevice);

    printf("check\n");
    int threads = 256;
    int blocks = 1;
    xMul<<<blocks, threads>>>(A_in, B_in, C_out);
    cudaDeviceSynchronize();

    cudaError_t err = cudaDeviceSynchronize();
    if (err != cudaSuccess)
        std::cerr << "Kernel error: " << cudaGetErrorString(err) << std::endl;

    err = cudaMemcpy(C, C_out, sizeof(float), cudaMemcpyDeviceToHost);
    if (err != cudaSuccess)
        std::cerr << "Memcpy error: " << cudaGetErrorString(err) << std::endl;

    printf("check\n");
    cudaMemcpy(C, C_out, sizeof(float), cudaMemcpyDeviceToHost);
    
    printf("check C: %f\n", *C);
    cudaFree(A_in);
    cudaFree(B_in);
    cudaFree(C_out);
    printf("check C: %f\n", *C);
}

void DataCompute::printC()
{
    printf("checking A: %f\n", *A);
    printf("checking B: %f\n", *B);
    printf("checking C: %f\n", *C);
    this->compute(this->A, this->B, this->C);
    std::string str = "NO GO";

    if ((*(this->C) == (7.5 * 5)))
        str = "GO";

    std::cout << "C is " << str << " for value of " << *(this->C) << std::endl;
}
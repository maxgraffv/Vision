#include "DataCompute.h"
#include <iostream>
#include <cuda_runtime.h>

__global__ void xMul(const float* A, const float* B, float* out)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if(idx < 1)
    {
        out[idx] = A[idx] * B[idx];
        // printf("GPU: A = %f, B = %f, out = %f\n", A[idx], B[idx], out[idx]);
    }
}

__global__ void conv2d(const float* img, const float* ker, float* out, int w, int h, int kw, int kh)
{
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    if (x >= w || y >= h)
        return;

    if(x == 0 && y == 0)
    for(int i = 0; i < 9; i++)
        printf("K= %f\n",img[i]);

    int kCenterX = kw / 2;
    int kCenterY = kh / 2;

    for (int c = 0; c < 3; ++c) { // kanały: 0=R,1=G,2=B

        float sum = 0.0f;

        for (int ky = 0; ky < kh; ++ky) {
            for (int kx = 0; kx < kw; ++kx) {
                int ix = x + kx - kCenterX;
                int iy = y + ky - kCenterY;

                float val = 0.0f;
                if (ix >= 0 && ix < w && iy >= 0 && iy < h) {
                    int pixelIndex = (iy * w + ix) * 3;
                    val = img[pixelIndex + c];
                }

                float k = ker[ky * kw + kx];
                sum += val * k;
            }
        }

        out[(y * w + x) * 3 + c] = sum;
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
    float *A_in = nullptr, *B_in = nullptr, *C_out = nullptr;
    cudaMalloc(&A_in, sizeof(float));
    cudaMalloc(&B_in, sizeof(float));
    cudaMalloc(&C_out, sizeof(float));

    cudaMemcpy(A_in, A, sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(B_in, B, sizeof(float), cudaMemcpyHostToDevice);

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

    cudaMemcpy(C, C_out, sizeof(float), cudaMemcpyDeviceToHost);
    
    cudaFree(A_in);
    cudaFree(B_in);
    cudaFree(C_out);
}

void DataCompute::printC()
{
    this->compute(this->A, this->B, this->C);
    std::string str = "NO GO";

    if ((*(this->C) == (7.5 * 5)))
        str = "GO";

    std::cout << "CUDA GPU is " << str << std::endl;
}

void DataCompute::applyKernel(QtImage& img, Matrix<float>& kernel)
{
    int w = img.getWidth();
    int h = img.getHeight();
    int kw = kernel.getWidth();
    int kh = kernel.getHeight();

    dim3 block(16, 16);
    dim3 grid((w + block.x - 1) / block.x, (h + block.y - 1) / block.y);

    float output[img.buffer().size()];
    std::fill(output, output + img.buffer().size(), 0.0f);

    float *devKer = nullptr, *devImg = nullptr, *devOut = nullptr;

    std::cout << kernel.buffer().size() << std::endl;
    
    cudaMalloc(&devImg, sizeof(float)*img.buffer().size());
    cudaMalloc(&devKer, sizeof(float)*kernel.buffer().size());
    cudaMalloc(&devOut, sizeof(float)*img.buffer().size());

    cudaMemcpy(devImg, img.buffer().data(), sizeof(float)* img.buffer().size(), cudaMemcpyHostToDevice);
    cudaMemcpy(devKer, kernel.buffer().data(), sizeof(float)*kernel.buffer().size(), cudaMemcpyHostToDevice);

    conv2d<<<grid, block>>>(devImg, devKer, devOut, w, h, kw, kh);

    cudaError_t err = cudaDeviceSynchronize();
    if(err != cudaSuccess)
        std::cerr << "CUDA error: " << cudaGetErrorString(err) << std::endl;


    err = cudaMemcpy(output, devOut, sizeof(float)*img.buffer().size(), cudaMemcpyDeviceToHost);
    if (err != cudaSuccess)
        std::cerr << "Memcpy error: " << cudaGetErrorString(err) << std::endl;

    cudaFree(devImg);
    cudaFree(devKer);
    cudaFree(devOut);

    img.buffer() = std::vector<float>(output, output+(w*h*3));
}
#include "ImageProcessor.h"

ImageProcessor::ImageProcessor()
{

}

void ImageProcessor::test(QtImage* img)
{
    float* r = 0;
    float* g = 0;
    float* b = 0;

    for(int i = 0; i < img->buffer().size(); i++)
    {
        r = &img->buffer()[i++];
        // g = &img->buffer()[i++];
        b = &img->buffer()[i];

        *r = 0;
        // *g = 255;
        *b = 0;

        // img->buffer()[i] = 0;
    }
    printf("went\n");
    img->refresh();
}



Matrix<float> ImageProcessor::gausianBlurMatrix()
{
    Matrix<float> gaussMat(5,5);

    float arr2d[5][5] = {
        {1,4,6,4,1},
        {4,16,24,16,4},
        {6,24,36,24,6},
        {4,16,24,16,4},
        {1,4,6,4,1}
    };

    gaussMat = Matrix<float>::mat(&arr2d[0][0], 5, 5);
    double div = 1.f/256.f;
    gaussMat = gaussMat*(div);

    return gaussMat;
}


Matrix<float> ImageProcessor::sobelMatrix(float m, bool horizontal)
{
    Matrix<float> sobelMat(3,3);

    float* arr_p = nullptr;

    float h[3][3] = {
        {-1*m, 0, 1},
        {-2*m, 0, 2},
        {-1*m, 0, 1}
    };

    float v[3][3] = {
        {-1*m, -2*m, -1*m},
        {0, 0, 0},
        {1, 2, 1}
    };

    if(horizontal)
        arr_p = &h[0][0];
    else
        arr_p = &v[0][0];

    sobelMat = Matrix<float>::mat(arr_p, 3, 3);
    sobelMat = sobelMat;

    return sobelMat;
}
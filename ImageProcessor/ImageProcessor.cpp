#include "ImageProcessor.h"

ImageProcessor::ImageProcessor()
{

}

void ImageProcessor::test(QtImage* img)
{
    uint8_t* r = 0;
    uint8_t* g = 0;
    uint8_t* b = 0;

    for(int i = 0; i < img->buffer().size(); i++)
    {
        r = &img->buffer()[i++];
        g = &img->buffer()[i++];
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

    return gaussMat;
}


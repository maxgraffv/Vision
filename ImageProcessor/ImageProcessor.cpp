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


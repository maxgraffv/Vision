#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include "QtImage.h"
#include "Matrix.h"

class ImageProcessor
{
    private:




    public:
        ImageProcessor();
        void test(QtImage* img);

        Matrix<float> gausianBlurMatrix();
        Matrix<float> sobelMatrix(float m=1.0, bool horizontal=true);



};





#endif
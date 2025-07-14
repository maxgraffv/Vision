#include "QtImage.h"

#include <QImage>
#include <QLabel>

QtImage::QtImage(int width, int height, const char* path) : Image(width, height, path)
{
    _width = width;
    _height = height;

    // std::vector<uint8_t> vec(width*height*3);

    // for(int i = 0; i < vec.size(); i++)
    // {
    //     vec[i] = 0xbb;
    // }

    _qImage = new QImage(buffer, _width, _height, QImage::Format_RGB888);
    this->setPixmap(QPixmap::fromImage(*_qImage));
}


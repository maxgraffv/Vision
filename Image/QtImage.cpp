#include "QtImage.h"

#include <QImage>
#include <QLabel>

QtImage::QtImage(int width, int height, const char* path) : Image(width, height, path)
{
    _width = width;
    _height = height;

    _qImage = new QImage(this->Matrix::buffer().data(), _width, _height, QImage::Format_RGB888);
    this->setPixmap(QPixmap::fromImage(*_qImage));
}

void QtImage::refresh()
{
    _qImage = new QImage(this->Matrix::buffer().data(), _width, _height, QImage::Format_RGB888);
    this->setPixmap(QPixmap::fromImage(*_qImage));
}


#include "QtImage.h"

#include <QImage>
#include <QLabel>
#include <algorithm>

QtImage::QtImage(int width, int height, const char* path) 
    : Image(width, height, path), display_buf(std::vector<uint8_t>(this->buffer().size()))
{
    _width = width;
    _height = height;

    
    refresh();
}

void QtImage::refresh()
{
    std::transform(this->buffer().begin(), this->buffer().end(), this->display_buf.begin(), [](double val) {
        if(val > 255.0)
            val = 255.0;
        if(val < 0.0)
            val = 0.0;

        return static_cast<uint8_t>( std::round(val) );
    } );

    

    _qImage = new QImage(this->display_buf.data(), _width, _height, QImage::Format_RGB888);
    this->setPixmap(QPixmap::fromImage(*_qImage));
}


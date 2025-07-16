#ifndef QT_IMAGE_H
#define QT_IMAGE_H

#include "Image.h"
#include <QWidget>
#include <QLabel>


class QtImage : public Image, public QLabel
{

    private:
        QImage* _qImage;
        int _width, _height;

        friend class AppWindow;

    public:
        QtImage(int width, int height, const char* path);

        void refresh() override;


};



#endif
#include "AppWindow.h"

#include <QHBoxLayout>
#include <QImage>
#include <vector>
#include <QLabel>
#include <QPixmap>
#include "QtImage.h"


AppWindow::AppWindow(int width, int height, QWidget* parent) : QWidget(parent), _width(width), _height(height)
{
    _button = new QPushButton("Click");
    _label = new QLabel("Hello Label");

    _imageLeft = new QImage();

    /*
        LAYOUT
    */
    auto* layout = new QHBoxLayout();
    setLayout(layout);
    setMinimumSize(width, height);

    /*
        IMAGE
    */
    QtImage* img = new QtImage(860, 554, "../0.rgb");
    layout->addWidget(img, 0, Qt::AlignCenter);

    QtImage* img2 = new QtImage(860, 554, "../0.rgb");
    layout->addWidget(img2, 0, Qt::AlignCenter);

  }
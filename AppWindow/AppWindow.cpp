#include "AppWindow.h"

#include <QHBoxLayout>
#include <QImage>
#include <vector>
#include <QLabel>
#include <QPixmap>
#include "QtImage.h"
#include "ImageProcessor.h"
#include "DataCompute.h"


AppWindow::AppWindow(int width, int height, QWidget* parent) : QWidget(parent), _width(width), _height(height)
{
    /*
        LAYOUT
    */
    auto* layout = new QHBoxLayout();
    setLayout(layout);
    setMinimumSize(width, height);

    /*
        IMAGE
    */
    QtImage* img = new QtImage(860, 554, "../image.rgb");
    layout->addWidget(img, 0, Qt::AlignCenter);

    QtImage* img2 = new QtImage(860, 554, "../image.rgb");
    layout->addWidget(img2, 0, Qt::AlignCenter);

    DataCompute *dc = new DataCompute();
    dc->printC();

    ImageProcessor* proc = new ImageProcessor();





}

AppWindow::~AppWindow()
{

}
  
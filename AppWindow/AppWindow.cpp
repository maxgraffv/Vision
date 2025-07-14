#include "AppWindow.h"

#include <QHBoxLayout>
#include <QImage>
#include <vector>
#include <QLabel>
#include <QPixmap>


AppWindow::AppWindow(QWidget* parent) : QWidget(parent)
{
    _button = new QPushButton("Click");
    _label = new QLabel("Hello Label");

    _imageLeft = new QImage();

    /*
        LAYOUT
            HBox
            VBox
            Grid
            Form
    */
    auto* layout = new QHBoxLayout();
    setLayout(layout);
    setMinimumSize(1000, 600);

    QWidget* p = new QWidget();
    p->setFixedSize(100, 100);
    p->setStyleSheet("background-color: #ff0000;");
    layout->addWidget(p);


    QWidget* p2 = new QWidget();
    p2->setFixedSize(100, 100);
    p2->setStyleSheet("background-color: #0000ff;");
    layout->addWidget(p2);



    /*
        IMAGE
    */
    int width = 640;
    int height = 480;
    int len = width*height;

    std::vector<uint8_t> data_v(len * 3);
    for(int i = 0; i < len*3; i+=3)
    {
        data_v[i] = 0x00; //Red
        data_v[i+1] = 0xff; //Green
        data_v[i+2] = 0x00; //Blue
    }

    QImage* img = new QImage(data_v.data(), width, height, QImage::Format_RGB888);
    QLabel* imgLabel = new QLabel();
    imgLabel->setPixmap(QPixmap::fromImage(*img));

    layout->addWidget(imgLabel);

    /*
        Label
    */
    // layout->addWidget(_label);

    // connect(_button, &QPushButton::clicked, this, [=](){
    //     _label->setText("Ugh pushed");
    // });

}
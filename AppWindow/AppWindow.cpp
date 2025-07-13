#include "AppWindow.h"

#include <QVBoxLayout>


AppWindow::AppWindow(QWidget* parent) : QWidget(parent)
{
    _button = new QPushButton("Click", this);
    _label = new QLabel("Hello Label", this);

    auto* layout = new QVBoxLayout();
    layout->addWidget(_label);
    setLayout(layout);

    connect(_button, &QPushButton::clicked, this, [=](){
        _label->setText("Ugh pushed");
    });

}
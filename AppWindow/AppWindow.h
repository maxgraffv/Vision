#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QImage>



class AppWindow : public QWidget
{
    Q_OBJECT

    private:
        QPushButton* _button;
        QLabel* _label;
        QImage* _imageLeft;
        QImage* _imageRight;


    public:
        AppWindow(QWidget *parent = nullptr);
    
};





#endif
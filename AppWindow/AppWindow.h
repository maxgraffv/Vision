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
        int _width, _height;    


    public:
        AppWindow(int width, int height, QWidget* parent = nullptr);
        ~AppWindow();
    
};






#endif
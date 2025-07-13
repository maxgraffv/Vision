#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>



class AppWindow : public QWidget
{
    Q_OBJECT

    private:
        QPushButton* _button;
        QLabel* _label;


    public:
        AppWindow(QWidget *parent = nullptr);
    
};





#endif
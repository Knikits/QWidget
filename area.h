#ifndef AREA_H
#define AREA_H
#include "figura.h"

class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = 0); // конструктор
    ~Area(); // деструктор
    MyLine *myline; // переменная типа MyLine (линия)
    MyRect *myrect; // переменная типа MyRect (прямоугольник)
protected:
    //обработчики событий
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};
#endif // AREA_H

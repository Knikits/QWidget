#ifndef FIGURA_H
#define FIGURA_H
#include <QtGui>
#include <QWidget>

class Figura // класс фигур
{
protected:
    // x, y - координаты центра фигуры
    // halflen - радиус фигуры
    // dx, dy - скорость фигуры
    int x,y,halflen,dx,dy,r;
    virtual void draw(QPainter *Painter)=0; // функция для прорисовки фигуры
public:
    Figura(int X,int Y,int Halflen):
    x(X),y(Y),halflen(Halflen){} // определение переменных
    void move(float Alpha,QPainter *Painter); // движение фигуры и поворот
};

class MyLine:public Figura // класс MyLine наследник класса Figura
{
protected:
    void draw(QPainter *Painter); // отрисовка
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};

class MyRect:public Figura // класс MyRect наследник класса Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};


#endif // FIGURA_H

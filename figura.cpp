#include <math.h>
#include "figura.h"

void Figura::move(float Alpha,QPainter *Painter) // функция движения
{
    dx=halflen*cos(Alpha); // скорость по x равна радиусу на косинус угла поворота
    dy=halflen*sin(Alpha); // скорость по y равна радиусу на косинус угла поворота
    draw(Painter); // отрисовка обекта
}

void MyLine::draw(QPainter *Painter) //  отрисовка отрезка
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy); // один отрезок
}

void MyRect::draw(QPainter *Painter) // отрисовка квадрата
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy); // четыре стороны
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}

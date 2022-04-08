#include "area.h"

Area::Area(QWidget *parent):QWidget(parent) // конструктор класса area
{
    setFixedSize(QSize(300,200)); // размеры
    myline=new MyLine(80,100,25);
    myrect=new MyRect(220,100,60);
    alpha=0;
}

void Area::showEvent(QShowEvent *) // появление события
{
    myTimer=startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent *) // событие открисовки
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    myline->move(alpha,&painter);
    myrect->move(alpha*(2),&painter);
}

void Area::timerEvent(QTimerEvent *event) // событие таймера
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.1;
        update(); // обновить внешний вид
    }
    else
    QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *) // собитие уничтожения таймера
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area() // деструктор
{
    delete myline;
    delete myrect;
}

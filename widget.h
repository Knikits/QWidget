#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>       // компоненты
#include <QPushButton>

#include "area.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Window : public QWidget // класс Window является наследником класса QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn; // кнопка завершить
public:
    Window(); // конструктор
};
#endif // WIDGET_H

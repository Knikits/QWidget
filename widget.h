#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QFrame>
#include <QLabel>     // компоненты
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "area.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Window : public QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};
#endif // WIDGET_H

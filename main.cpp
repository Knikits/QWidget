#include "widget.h"
#include <QApplication>

// Пример 2.7 «Возведение числа в квадрат»

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

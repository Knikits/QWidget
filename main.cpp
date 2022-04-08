#include "widget.h"
#include <QApplication>

// Пример 2.9 «Создание движущихся изображений»

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}

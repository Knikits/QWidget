#include "widget.h"
#include "ui_widget.h"

Window::Window() // конструтор окна
{
    this->setWindowTitle("Обработка событий"); // название окна
    area = new Area( this ); // создание области
    btn = new QPushButton("Завершить",this ); // кнопка завершить
    QVBoxLayout *layout = new QVBoxLayout(this); // создание вертикального макета
    layout->addWidget(area); // добавляем в макет область
    layout->addWidget(btn); // и кнопку выхода
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); // сигнал при нажатии кнопки выхода вызывает слот (выход)
};


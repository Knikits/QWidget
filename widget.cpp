#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) // конструктор
    : QWidget(parent)
{
     this->setWindowTitle("Счетчик"); // Название окна
     label1 = new QLabel("Cчет по 1",this); // название текстового поля
     label2 = new QLabel("Cчет по 5",this); // название текстового поля
     edit1 = new Counter("0",this); // выставляем в поле вывода 0
     edit2 = new Counter("0",this); // выставляем в поле вывода 0
     calcbutton=new QPushButton("+1",this); // добавляем кнопку +1
     exitbutton=new QPushButton("Выход",this); // добавляем кнопку Выход
     QHBoxLayout *layout1 = new QHBoxLayout(); // создаем горизонтальный макет
     layout1->addWidget(label1); // заполняем его текстовыми полями (название)
     layout1->addWidget(label2); // заполняем его текстовыми полями (название)
     QHBoxLayout *layout2 = new QHBoxLayout(); // создаем второй горизонтальный макет
     layout2->addWidget(edit1); // поле вывода
     layout2->addWidget(edit2);// поле вывода
     QHBoxLayout *layout3 = new QHBoxLayout(); // создаем третий горизонтальный макет
     layout3->addWidget(calcbutton); // кнопка +1
     layout3->addWidget(exitbutton); // кнопка Выход
     QVBoxLayout *layout4 = new QVBoxLayout(this); // // создаем вертикальный макет, в который добаляем все горизонтальные макеты
     layout4->addLayout(layout1);
     layout4->addLayout(layout2);
     layout4->addLayout(layout3);
     // связь сигнала нажатия кнопки и слота закрытия окна
     connect(calcbutton,SIGNAL(clicked(bool)), edit1,SLOT(add_one())); // сигнал нажатия кнопки +1 вызывает функцию добавления единицы
     connect(edit1,SIGNAL(tick_signal()), edit2,SLOT(add_one())); // связываем тик одного сигнала из класса counter и добавление единицы
     connect(exitbutton,SIGNAL(clicked(bool)), this,SLOT(close())); // сигнал нажатия кнопки Выход вызывает выход из окна
}



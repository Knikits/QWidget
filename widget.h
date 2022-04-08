#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QLabel>     // компоненты
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Counter; }
QT_END_NAMESPACE

class Counter : public QLineEdit // класс счетчика является наследником класса QLineEdit
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
    Counter(const QString & contents, QWidget *parent=0): QLineEdit(contents,parent){} // конструтор
signals:
    void tick_signal(); // функция тика типа void (сигнал для вызова)
public slots:
    void add_one() // функция увеличения на единицу
    {
        QString str = text(); // берём всё, что есть в поле ввода/вывода
        int r = str.toInt(); // преобразовываем в int
        if (r!=0 && r%5 ==0) emit tick_signal(); // проверка условия, если не равно нулю и делится нацело на пять, то вызываем сигнал
        r++; // увеличиваем на единицу
        str.setNum(r); // преобразовываем r в QString
        setText(str); // устанавливам r в текстовое поле
     }
};

class Widget: public QWidget // класс окна является наследником класса QWidget
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QLabel *label1, *label2; // два текстовоых (зоголовчных) поля
    Counter *edit1, *edit2; // поля вывода
    QPushButton *calcbutton; // кнопка +1
    QPushButton *exitbutton; // кнопка выхода
public:
    Widget(QWidget *parent = 0); // конструтор
};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
        {
            return Acceptable; // метод всегда принимает вводимую строку
        }
};

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *calcButton; // кнопка Вычислить
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
public:
    Widget(QWidget *parent = nullptr); // конструтор
    ~Widget(); // деструктор
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

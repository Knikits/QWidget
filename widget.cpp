#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Возведение в квадрат"); // название окна
    frame = new QFrame(this); //
    frame->setFrameShadow(QFrame::Raised); //
    frame->setFrameShape(QFrame::Panel); //
    inputLabel = new QLabel("Введите число:", this); // создаём текстовое поле
    inputEdit = new QLineEdit("", this); // создаём поле ввода
    StrValidator *v=new StrValidator(inputEdit); // проверка правильности ввода
    inputEdit->setValidator(v); // отправляем на правильность ввода
    outputLabel = new QLabel("Результат:", this); // создаём текстовое поле
    outputEdit = new QLineEdit("",this); // создаём поле вывода
    calcButton = new QPushButton ("Выполнить", this); // создаём кнопку
    nextButton = new QPushButton("Следующий", this); // создаём кнопку
    exitButton = new QPushButton("Выйти", this); // создаём кнопку
    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // создание вертикального макета, в который добавляем различные поля
    vLayout1->addWidget(inputLabel); // текст
    vLayout1->addWidget(inputEdit); // поле ввода
    vLayout1->addWidget(outputLabel);// текст
    vLayout1->addWidget(outputEdit); // поле вывода
    vLayout1->addStretch(); // убирает пространоство между полями
    QVBoxLayout *vLayout2 = new QVBoxLayout(); // создание вертикального макета, в который добавляем кнопки
    vLayout2->addWidget(calcButton); // кнопка для вычисления
    vLayout2->addWidget(nextButton); // кнопка для очистки левого поля
    vLayout2->addWidget(exitButton); // кнопка для выхода
    vLayout2->addStretch(); // убирает пространоство между кнопками
    QHBoxLayout *hLayout = new QHBoxLayout(this); // создание горизонтального макета
    hLayout->addWidget(frame); //
    hLayout->addLayout(vLayout2); //
    begin(); // метод начальной настройки интерфейса
    connect(calcButton,SIGNAL(clicked(bool)), this,SLOT(calc())); //
    connect(exitButton,SIGNAL(clicked(bool)), this,SLOT(close())); //
    connect(nextButton,SIGNAL(clicked(bool)), this,SLOT(begin())); //
    connect(inputEdit,SIGNAL(returnPressed()), this,SLOT(calc())); // сигнал нажатия клавиши Enter

}
void Widget::begin() // метод начальной настройки интерфейса
{
    inputEdit->clear(); // очистка поля
    nextButton->setEnabled(false); // кнопка Следующее становится выключеной
    nextButton->setDefault(false); //
    inputEdit->setEnabled(true); // поле ввода становится доступным
    outputLabel->setVisible(false); // текст Результат пропадает
    outputEdit->setVisible(false); // поле вывода пропадает
    outputEdit->setEnabled(false); // поле вывода становится недоступным
    inputEdit->setFocus(); // указатель ставится в поле ввода
}

void Widget::calc() // метод реализации вычислений
{
    bool Ok=true; // переменная типа bool присваивается true
    float r,a; // создаются переменные
    QString str=inputEdit->text(); //
    a=str.toDouble(&Ok); //
    if (Ok) { //
        r=a*a; // операция возведения в квадрат
        str.setNum(r); //
        outputEdit->setText(str); //
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true); // поле остаётся видимым
        outputEdit->setVisible(true); // поле остаётся видимым
        nextButton->setDefault(true); // кнопка становится доступной
        nextButton->setEnabled(true); //
        nextButton->setFocus(); // указатель ставится на кнопку Следующее
    }
    else
        if (!str.isEmpty()) { // если строка пуста
            QMessageBox msgBox(QMessageBox::Information,("Возведение в квадрат."),("Введено неверное значение."),QMessageBox::Ok);
            msgBox.exec(); // выводим сообщение
    }
}

Widget::~Widget() // реализация деструктора
{
    delete ui;
}

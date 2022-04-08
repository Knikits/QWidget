#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) // реализация конструктора
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); // компилируем дизайн, который создан в ui
    setWindowTitle("Возведение в квадрат"); // название окна
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised); // создаём фреймы  и настраиваем
    frame->setFrameShape(QFrame::Panel);
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
    hLayout->addWidget(frame); // добавляем фрейм
    hLayout->addLayout(vLayout2); // добавляем вертикальное поле2
    begin(); // метод начальной настройки интерфейса
    connect(calcButton,SIGNAL(clicked(bool)), this,SLOT(calc())); // сигнал нажатия кнопки Вычислить
    connect(exitButton,SIGNAL(clicked(bool)), this,SLOT(close())); // сигнал нажатия кнопки Выход
    connect(nextButton,SIGNAL(clicked(bool)), this,SLOT(begin())); // сигнал нажатия кнопки Следующее
    connect(inputEdit,SIGNAL(returnPressed()), this,SLOT(calc())); // сигнал нажатия клавиши Enter

}
void Widget::begin() // метод начальной настройки интерфейса
{
    inputEdit->clear(); // очистка поля
    nextButton->setEnabled(false); // кнопка Следующее становится выключеной
    nextButton->setDefault(false); // кнопка Следующее не по умолчанию
    inputEdit->setEnabled(true); // поле ввода становится доступным
    outputLabel->setVisible(false); // текст Результат пропадает
    outputEdit->setVisible(false); // поле вывода пропадает
    outputEdit->setEnabled(false); // поле вывода становится недоступным
    inputEdit->setFocus(); // указатель ставится в поле ввода
}

void Widget::calc() // метод реализации вычислений
{
    bool Ok = true; // переменная типа bool присваивается true
    float r,a; // создаются переменные
    QString str=inputEdit->text(); // берёт все, что было написано в поле ввода
    a = str.toDouble(&Ok); // преобразовываем str в тип float, проверка преобразования в переменной ok
    if (Ok) { // если ok true, то
        r=a*a; // операция возведения в квадрат
        str.setNum(r); // преобразование r в QString и сразу записываем в переменную Str
        outputEdit->setText(str); // в поле вывода записываем str
        inputEdit->setEnabled(false); // поле ввода становится недоступным
        outputLabel->setVisible(true); // поле остаётся видимым
        outputEdit->setVisible(true); // поле остаётся видимым
        nextButton->setDefault(true); // кнопка становится по умолчанию
        nextButton->setEnabled(true); // и становится доступной
        nextButton->setFocus(); // указатель ставится на кнопку Следующее
    }
    else // если ввод некорректный
        if (!str.isEmpty()) { // если строка пуста
            // окно с предупреждением
            QMessageBox msgBox(QMessageBox::Information,("Возведение в квадрат."),("Введено неверное значение."),QMessageBox::Ok);
            msgBox.exec(); // выводим сообщение
    }
}

Widget::~Widget() // реализация деструктора
{
    delete ui;
}

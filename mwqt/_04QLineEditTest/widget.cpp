#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//----------------回显模式-------------------------
//正常
void Widget::on_pushButton_2_clicked()
{
    ui->hxEdit->setEchoMode(QLineEdit::Normal);
    ui->hxEdit->setPlaceholderText("Normal");
}


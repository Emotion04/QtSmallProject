#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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

void Widget::on_pushButton_clicked()
{
    QString s=ui->pushButton->text();
    if(s=="启动"){
        ui->pushButton->setText("停止");
        ui->pushButton->setFont(QFont("黑体",16));
        ui->pushButton->setIcon(QIcon(":/stop.ico"));
        ui->pushButton->setIconSize(QSize(46,46));
    }
    else{
        ui->pushButton->setText("启动");
        ui->pushButton->setFont(QFont("黑体",16));
        ui->pushButton->setIcon(QIcon(":/start.ico"));
        ui->pushButton->setIconSize(QSize(32,32));
    }
}

void Widget::on_pushButton_2_clicked()
{
    QString s=ui->pushButton_2->text();
    if(s=="连接"){
        ui->pushButton_2->setText("断开连接");
        ui->pushButton_3->setEnabled(true);
    }
    else{
        ui->pushButton_2->setText("连接");
        ui->pushButton_3->setEnabled(false);
    }
}

void Widget::on_pushButton_5_clicked()
{
    qDebug()<<"clicked";
}


void Widget::on_pushButton_5_pressed()
{
    qDebug()<<"pressed";
}


void Widget::on_pushButton_5_released()
{
    qDebug()<<"released";
}





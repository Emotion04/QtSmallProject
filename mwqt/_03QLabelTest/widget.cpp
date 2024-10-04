#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTime>
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
    QMessageBox::information(this,"标签演示",ui->label->text());
}



void Widget::on_pushButton_2_clicked()
{
    ui->label->setText(QTime::currentTime().toString());
}


void Widget::on_pushButton_3_clicked()
{
    ui->label_2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}


void Widget::on_pushButton_4_clicked()
{
    ui->label_2->setAlignment(Qt::AlignCenter);
}


void Widget::on_pushButton_5_clicked()
{
    ui->label_2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}


void Widget::on_pushButton_6_clicked()
{
    ui->label_3->setWordWrap(false);
}


void Widget::on_pushButton_7_clicked()
{
    ui->label_3->setWordWrap(true);
}

int idx=0;
void Widget::on_pushButton_8_clicked()
{
    QPixmap px;
    if(idx==0){
        px.load(QString(":/caomei.ico"));
        idx++;
    }
    else if(idx==1){
        px.load(QString(":/xiangjiao.ico"));
        idx++;
    }
    else{
        px.load(QString(":/xigua.ico"));
        idx=0;
    }

    //设置图片
    ui->label_4->setPixmap(px);
    //静止缩放
    ui->label_4->setScaledContents(false);
    //图片居中显示
    ui->label_4->setAlignment(Qt::AlignCenter);
}


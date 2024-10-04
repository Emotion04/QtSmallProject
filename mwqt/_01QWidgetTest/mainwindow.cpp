#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"--------------------------";
    QRect rect=this->geometry();
    qDebug()<<"左上角："<<rect.topLeft();
    qDebug()<<"右上角："<<rect.topRight();
    qDebug()<<"左下角："<<rect.bottomLeft();
    qDebug()<<"右下角: "<<rect.bottomRight();
    qDebug()<<"宽度："<<rect.width();
    qDebug()<<"高度："<<rect.height();
}


void MainWindow::on_pushButton_2_clicked()
{
    QSize size(400,400);
    this->resize(size);
}


void MainWindow::on_pushButton_3_clicked()
{
    QSize size(500,500);
    this->setFixedSize(size);
}




void MainWindow::on_pushButton_4_clicked()
{
    QSize size(300,300);
    this->setMinimumSize(size);
}


void MainWindow::on_pushButton_5_clicked()
{
    QSize size(600,600);
    this->setMaximumSize(size);
}


void MainWindow::on_pushButton_6_clicked()
{
    this->setWindowTitle("修改窗口标题");
}


void MainWindow::on_pushButton_7_clicked()
{
    /*QPixmap img;
    img.load(":/logo.ico");
    this->setWindowIcon(QIcon(img));*/
    this->setWindowIcon(QIcon(":/logo.ico"));
}


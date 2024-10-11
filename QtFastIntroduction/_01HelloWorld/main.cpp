#include <QApplication>
#include "dialog.h"
#include <QLabel>

int main(int argc,char* argv[])
{
    QApplication a(argc,argv);
    Dialog w;
    /*QLabel label(&w);
    w.resize(400,400);

    label.setText("HelloWorld!!!");*/
    w.show();

    return a.exec();

}

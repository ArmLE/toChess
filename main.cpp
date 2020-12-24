#include "mainwindow.h"

#include <QApplication>
#include "Matriz.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Matriz<QPoint> matrix{8,8};
    //matrix[0][1]=20;

    return a.exec();
}

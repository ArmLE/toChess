#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->TableroWidget->se


    /*
    ui->CapBlackWidget

    ui->CapWhiteWidget*/

}

MainWindow::~MainWindow()
{
    delete ui;
}


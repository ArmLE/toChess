#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tablero)
{
    //setRect(0,0,100,100);
    ui->setupUi(this);

    //ui->Tablero

    /*

*/
}

Tablero::~Tablero()
{
    delete ui;
}

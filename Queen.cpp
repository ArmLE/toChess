#include "Queen.h"
/*
Queen::Queen(QWidget* parent): Piece{parent}
{
    pieceIcon.load("G:/EPIS/2020_B/TO/TEST/toChess/c_bn.svg");  //50,60
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));

}*/
Queen::Queen(Color c, QWidget* parent): Piece(c , parent)
{
    pieceIcon.load(color==Color::WHITE? ":/c_wq.svg":":/c_bq.svg");
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));
    //50,60
}

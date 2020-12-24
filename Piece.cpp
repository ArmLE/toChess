#include "Piece.h"
/*
Piece::Piece(QWidget *parent): QLabel(parent), color{Color::WHITE}
{

    pieceIcon.load("G:/EPIS/2020_B/TO/TEST/toChess/c_bn.svg");
    this->setPixmap(pieceIcon.scaled(QSize(50,60),Qt::KeepAspectRatio));

}*/
Piece::Piece(Color c, QWidget *parent): QLabel(parent), color{c}
{

}

/*void Piece::setPoint(const unsigned& x,const unsigned& y){
    point.rx()=x;
    point.ry()=y;
}*/

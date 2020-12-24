#include "Knight.h"

Knight::Knight(Color c, QWidget* parent): Piece(c , parent)
{
    pieceIcon.load(color==Color::WHITE? ":/c_wn.svg":":/c_bn.svg");
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));
    //50,60
}

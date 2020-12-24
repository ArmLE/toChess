#include "King.h"

King::King(Color c, QWidget* parent): Piece(c , parent)
{
    pieceIcon.load(color==Color::WHITE? ":/c_wk.svg":":/c_bk.svg");
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));
    //50,60
}

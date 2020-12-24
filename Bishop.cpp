#include "Bishop.h"

Bishop::Bishop(Color c, QWidget* parent): Piece(c , parent)
{
    pieceIcon.load(color==Color::WHITE? ":/c_wb.svg":":/c_bb.svg");
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));
    //50,60
}

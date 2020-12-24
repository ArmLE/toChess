#include "Rook.h"

Rook::Rook(Color c, QWidget* parent): Piece(c , parent)
{
    pieceIcon.load(color==Color::WHITE? ":/c_wr.svg":":/c_br.svg");
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));
    //50,60
}

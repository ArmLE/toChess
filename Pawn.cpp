#include "Pawn.h"

Pawn::Pawn(Color c, QWidget* parent): Piece(c , parent)
{
    pieceIcon.load(color==Color::WHITE? ":/c_wp.svg":":/c_bp.svg");  //50,60
    this->setPixmap(pieceIcon.scaled(QSize(66,66),Qt::KeepAspectRatio));

}

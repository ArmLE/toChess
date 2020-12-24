#ifndef KING_H
#define KING_H

#include "Piece.h"
class King:public Piece
{
public:
    King()=delete;
    explicit King(Color c= Color::WHITE,QWidget* parent = nullptr);
    void movePiece() override{};
};

#endif // KING_H

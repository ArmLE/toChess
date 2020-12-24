#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
class Rook :public Piece
{
public:
    Rook()=delete;
    explicit Rook(Color c= Color::WHITE,QWidget* parent = nullptr);
    void movePiece() override{};
};

#endif // ROOK_H

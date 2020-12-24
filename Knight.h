#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
class Knight : public Piece
{
public:
    Knight()=delete;
    explicit Knight(Color c= Color::WHITE,QWidget* parent = nullptr);
    void movePiece() override{};

};

#endif // KNIGHT_H

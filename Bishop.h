#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
class Bishop:public Piece
{
public:
    Bishop()=delete ;
    explicit Bishop(Color c= Color::WHITE,QWidget* parent = nullptr);
    void movePiece() override{};
};

#endif // BISHOP_H

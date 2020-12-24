#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn()=delete;
    explicit Pawn(Color c=Color::WHITE, QWidget* parent=nullptr);
    void movePiece() override{};
};

#endif // PAWN_H

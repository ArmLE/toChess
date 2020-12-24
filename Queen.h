#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
class Queen : public Piece
{
public:
    Queen()=delete;
    //explicit Queen(QWidget* parent = nullptr);
    explicit Queen(Color c= Color::WHITE,QWidget* parent = nullptr);
    void movePiece() override{};
};

#endif // QUEEN_H

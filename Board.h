#ifndef BOARD_H
#define BOARD_H
//QT
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QtWidgets>

#include <QListWidget>
//STL
#include <memory>
#include <iostream>
//Local
#include "Piece.h"
#include "Queen.h"
#include "Matriz.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Board *ui;
    QPixmap boardIcon;

    std::shared_ptr<Piece> currentPiece;
    //Matriz<float> matrixf{4,4};
    //Matriz<QPoint> matrix{8,8};
   // Matriz<Piece*> matrixa{8,8};
    //Matriz<std::unique_ptr<Piece>> matrixP{8,8};

    Matriz<std::shared_ptr<Piece>> boxes{8,8};


    std::unique_ptr<Piece> piece;//Piece pieceOne;
    /*
    std::unique_ptr<Piece> car = std::make_unique<Queen>();
    std::shared_ptr<Piece> sh;*/

    std::vector<std::shared_ptr<Piece>> white; //QList <Piece *> white;
    std::vector<std::shared_ptr<Piece>> black;

    void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

    //void startDrag(Qt::DropActions supportedActions) override;
    void setUpWhite();
    void setUpBlack();
    //void drawPieces();
    void setUpMatrix();


};

#endif // BOARD_H

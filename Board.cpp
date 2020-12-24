#include "Board.h"
#include "Piece.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) : QWidget(parent), ui(new Ui::Board) {
    ui->setupUi(this);
    setAcceptDrops(TRUE);
    boardIcon.load(":/img/board3.png");

    setUpWhite();
    setUpBlack();
    setUpMatrix();
}

Board::~Board()
{
    delete ui;
}
void Board::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),boardIcon);

    //QPainterPath
}

void Board::mousePressEvent(QMouseEvent *event){
    std::cout<<"mousePressEvent"<<std::endl;
    auto child=childAt(event->pos());
    std::cout<<event->x()<<std::endl;

    std::cout<<event->y()<<std::endl;

    /*matrix[0][0]=event->pos();
    std::cout<<matrix[0][0].x()<<std::endl;
    std::cout<<matrix[0][0].y()<<std::endl;
    */

    if(child==nullptr){
        std::cout<<"null"<<std::endl;
        return;
    }
    std::cout<<"child image"<<std::endl;

    currentPiece=boxes[std::div(event->y(),66).quot-1][std::div(event->x(),66).quot-1];

    QByteArray posicion;
    QDataStream dataStream(&posicion,QIODevice::WriteOnly);

    dataStream<<QPoint(event->pos()-child->pos());

    QMimeData *mineData = new QMimeData();
    mineData->setData("application/x-dnditemdata",posicion);

    QDrag* drag= new QDrag(this);
    drag->setMimeData(mineData);
    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

}
void Board::dragMoveEvent(QDragMoveEvent *event){
    if(event->mimeData()->hasFormat("application/x-dnditemdata")){
        if(event->source()==this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}
void Board::dragEnterEvent(QDragEnterEvent *event){
    if(event->mimeData()->hasFormat("application/x-dnditemdata")){
        if(event->source()==this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}
void Board::dropEvent(QDropEvent *event){
    std::cout<<"drop-"<<std::endl;
    if(event->mimeData()->hasFormat("application/x-dnditemdata")){
        QByteArray posicion = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&posicion,QIODevice::ReadOnly);

        QPoint offset;
        dataStream>>offset;

        //piece->move(event->pos()-offset);
        std::cout<<(event->pos().y())<<std::endl;
        std::cout<<(event->pos().x())<<std::endl;
        int a=std::div(event->pos().y(),66).quot-1;

        int b=std::div(event->pos().x(),66).quot-1;
        boxes[a][b]=currentPiece;
        QPoint toMove{66+b*66,66+a*66};
        currentPiece->move(toMove);

        if(event->source()==this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}

void Board::setUpWhite(){

    white.emplace_back(std::make_unique<Rook>(Color::WHITE,this));
    white.emplace_back(std::make_unique<Knight>(Color::WHITE,this));
    white.emplace_back(std::make_unique<Bishop>(Color::WHITE,this));
    white.emplace_back(std::make_unique<Queen>(Color::WHITE,this));
    white.emplace_back(std::make_unique<King>(Color::WHITE,this));
    white.emplace_back(std::make_unique<Bishop>(Color::WHITE,this));
    white.emplace_back(std::make_unique<Knight>(Color::WHITE,this));
    white.emplace_back(std::make_unique<Rook>(Color::WHITE,this));
    for (int i = 0; i < 8; i++) {
        white.emplace_back(std::make_unique<Pawn>(Color::WHITE,this));
    }


}
void Board::setUpBlack(){
    for (int i = 0; i < 8; i++) {
        black.emplace_back(std::make_unique<Pawn>(Color::BLACK,this));
    }
    black.emplace_back(std::make_unique<Rook>(Color::BLACK,this));
    black.emplace_back(std::make_unique<Knight>(Color::BLACK,this));
    black.emplace_back(std::make_unique<Bishop>(Color::BLACK,this));
    black.emplace_back(std::make_unique<Queen>(Color::BLACK,this));
    black.emplace_back(std::make_unique<King>(Color::BLACK,this));
    black.emplace_back(std::make_unique<Bishop>(Color::BLACK,this));
    black.emplace_back(std::make_unique<Knight>(Color::BLACK,this));
    black.emplace_back(std::make_unique<Rook>(Color::BLACK,this));
}
/*
void Board::drawPieces(){
    for(int i=0; i<16; i++){
        white[i]->move(200+30*i,45+10*i);
        white[i]->show();
    }
}*/

void Board::setUpMatrix(){
    for(int i = 0, k = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++)
            {
                if(i < 2) {
                    white[k]->move(66+66*j,66+66*i);
                    white[k]->show();
                    std::cout<<"Inside i="<<i<<"j="<<j<<std::endl;
                    /*
                    matrixf[i][j] =20;//white[i];
                    matrixP[i][j] = std::make_unique<Pawn>(Color::BLACK,this);
                    */
                    boxes[i][j] = white[k];

                    k++;
                    if(k==16){k=0;}
                }
                if(i > 5) {
                    black[k]->move(66+66*j,66+66*i);
                    black[k]->show();
                    boxes[i][j] = black[k];
                    std::cout<<"Inside i="<<i<<"j="<<j<<std::endl;
                    k++;
                }

            }
        }
}
//std::for_each(white.begin(),white.end(),std::make_unique<Queen>(this));

/* for(auto it=white.begin();it != white.end();++it){
    *it=std::make_unique<Queen>(this);

    it->get()->move(66,66);
     it->get()->show();
    //std::rand()%100;
    //f(*it);
    //std::cout<<*it<<std::endl;
}
for(int i=0;i<4;i++){
    white.push_back(std::make_unique<Queen>(this));
}
for(int i=0;i<4;i++){
    white[i]->move(200+30*i,45+10*i);
    white[i]->show();
}
*/
/*
for( auto& p:white){
    //p=std::make_unique<Queen>(this);

    p->move(66,66);
    p->show();
}
piece=std::make_unique<Queen>(this);
piece->move(200,200);
piece->move(66,66);

Board of 660px min and max /10=66
piece->show();
*/

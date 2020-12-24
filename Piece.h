#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPoint>
#include <QPixmap>

namespace Ui { class Piece;}

enum class Color{ WHITE=0, BLACK=1 };
class Piece : public QLabel
{
    Q_OBJECT

public:
    Piece()=delete;
    //explicit Piece(QWidget* parent = nullptr);
    explicit Piece(Color c = Color::WHITE, QWidget* parent = nullptr);
    virtual ~Piece(){};
    virtual void movePiece()=0;

   // void setPoint(const unsigned& x,const unsigned& y);
    bool isPlaced{true};

    //friend Piece& operator = (){ return this};
    Color color;
private:
    Ui::Piece* ui;
protected:
    QPixmap pieceIcon;
    //QPoint  point{};

};


#endif // PIECE_H

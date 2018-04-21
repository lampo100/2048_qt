#ifndef TILE_H
#define TILE_H
#include "roundedrectangle.h"
#include <QtGlobal>
#include <QColor>

class Tile
{
public:
    Tile(){}
    Tile(const Tile &other);
    Tile &operator=(const Tile &other);

    //Tile(RoundedRectangle *rect, qint32 score);
    void attachRect(RoundedRectangle *rect);
    void setScore(qint32 score);
    void setInGame(bool inGame);
    bool isInGame();
    void setCoords(int row, int col);
    qint32 getScore();
    int row, col;


private:
    bool inGame = false;
    qint32 score;

    RoundedRectangle *rect;
};

#endif // TILE_H

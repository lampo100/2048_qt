#ifndef TILE_H
#define TILE_H
#include "roundedrectangle.h"
#include <QtGlobal>
#include <QColor>

class Tile
{
public:
    Tile(){}
    Tile(int row, int col);
    Tile(const Tile &other);
    Tile &operator=(const Tile &other);

    void attachRect(RoundedRectangle *rect);
    void setScore(qint32 score);
    void setInGame(bool inGame);
    bool isInGame();
    void setCoords(int row, int col);
    qint32 getScore();
    void hide();
    int row, col;
    RoundedRectangle *rect;


private:
    bool inGame = false;
    qint32 score;

};

#endif // TILE_H

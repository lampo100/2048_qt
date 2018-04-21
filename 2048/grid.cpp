#include "grid.h"

Grid::Grid()
{
    for(int i = 0; i < 4; ++i){
        QList<Tile *> *row = new QList<Tile *>();
        row->append(new Tile());
        row->append(new Tile());
        row->append(new Tile());
        row->append(new Tile());
        this->grid.append(row);
    }
}

Tile* Grid::spawnTile()
{
    qsrand(QTime::currentTime().msec());
    qint32 row = qrand() % 4;
    qint32 col = qrand() % 4;
    while(grid.at(row)->at(col)->isInGame()){
        row = qrand() % 4;
        col = qrand() % 4;
    }
    int score;
    if(qrand() % 2 == 0)
        score = 2;
    else
        score = 4;
    this->grid.at(row)->at(col)->setScore(score);
    this->grid.at(row)->at(col)->setCoords(row, col);
    this->grid.at(row)->at(col)->setInGame(true);
    this->tilesInGameCount++;

    return this->grid.at(row)->at(col);
}

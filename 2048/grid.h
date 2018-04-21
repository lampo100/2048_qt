#ifndef GRID_H
#define GRID_H

#include <tile.h>
#include <QTime>

class Grid
{
public:
    Grid();
    Tile * spawnTile();

private:
    QList<QList<Tile *> *> grid;
    int tilesInGameCount = 0;
};

#endif // GRID_H

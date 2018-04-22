#ifndef GRID_H
#define GRID_H

#include <tile.h>
#include <QTime>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

class Grid
{
public:
    Grid();
    Tile * spawnTile();
    QSequentialAnimationGroup *up();
    QSequentialAnimationGroup *down();
    QSequentialAnimationGroup *left();
    QSequentialAnimationGroup *right();


private:
    QPropertyAnimation *combineTiles(Tile *, Tile *, char);
    QPropertyAnimation *moveTile(Tile *, Tile *);

    QList<QList<Tile *> *> grid;
    int tilesInGameCount = 0;
};

#endif // GRID_H

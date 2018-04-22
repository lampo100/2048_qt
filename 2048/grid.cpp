#include "grid.h"
#include "mainwindow.h"

Grid::Grid()
{
    for(int i = 0; i < 4; ++i){
        QList<Tile *> *row = new QList<Tile *>();
        row->append(new Tile(i, 0));
        row->append(new Tile(i, 1));
        row->append(new Tile(i, 2));
        row->append(new Tile(i, 3));
        this->grid.append(row);
    }
}

Tile* Grid::spawnTile()
{
    if(this->tilesInGameCount == 16){
        return nullptr;
    }
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
    score = 4;
    this->grid.at(row)->at(col)->setScore(score);
    this->grid.at(row)->at(col)->setCoords(row, col);
    this->grid.at(row)->at(col)->setInGame(true);
    this->tilesInGameCount++;

    return this->grid.at(row)->at(col);
}

QSequentialAnimationGroup* Grid::up()
{
    QPropertyAnimation *lastAnimation;
    QSequentialAnimationGroup *animations = new QSequentialAnimationGroup();
    QParallelAnimationGroup *firstStage = new QParallelAnimationGroup();

    // First stage
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < 4; ++i){
            if(grid.at(i)->at(k)->isInGame()){
                auto currentTile = grid.at(i)->at(k);
                for(int j = 0; j < i; ++j)
                    if(!grid.at(j)->at(k)->isInGame()){
                        lastAnimation = moveTile(grid.at(j)->at(k), currentTile);
                        firstStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(firstStage);

    QParallelAnimationGroup *secondStage = new QParallelAnimationGroup();
    // Second stage
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < 3; ++i){
            if(grid.at(i)->at(k)->isInGame()){
                auto currentTile = grid.at(i)->at(k);
                if(grid.at(i+1)->at(k)->isInGame() &&
                   grid.at(i+1)->at(k)->getScore() == currentTile->getScore()){
                        lastAnimation = combineTiles(currentTile, grid.at(i+1)->at(k), 'u');
                        secondStage->addAnimation(lastAnimation);
                }
            }
        }
    }
    animations->addAnimation(secondStage);

    QParallelAnimationGroup *thirdStage = new QParallelAnimationGroup();
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < 4; ++i){
            if(grid.at(i)->at(k)->isInGame()){
                auto currentTile = grid.at(i)->at(k);
                for(int j = 0; j < i; ++j)
                    if(!grid.at(j)->at(k)->isInGame()){
                        lastAnimation = moveTile(grid.at(j)->at(k), currentTile);
                        thirdStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(thirdStage);
    return animations;
}

QSequentialAnimationGroup* Grid::down()
{
    QPropertyAnimation *lastAnimation;
    QSequentialAnimationGroup *animations = new QSequentialAnimationGroup();
    QParallelAnimationGroup *firstStage = new QParallelAnimationGroup();
    for(int k = 0; k < 4; ++k){
        for(int i = 3; i >= 0; --i){
            if(grid.at(i)->at(k)->isInGame()){
                auto currentTile = grid.at(i)->at(k);
                for(int j = 3; j > i; --j)
                    if(!grid.at(j)->at(k)->isInGame()){
                        lastAnimation = moveTile(grid.at(j)->at(k), currentTile);
                        firstStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(firstStage);
    QParallelAnimationGroup *secondStage = new QParallelAnimationGroup();
    // Second stage
    for(int k = 0; k < 4; ++k){
        for(int i = 3; i > 0; --i){
            if(grid.at(i)->at(k)->isInGame()){
                auto currentTile = grid.at(i)->at(k);
                if(grid.at(i-1)->at(k)->isInGame() &&
                   grid.at(i-1)->at(k)->getScore() == currentTile->getScore()){
                        lastAnimation = combineTiles(currentTile, grid.at(i-1)->at(k), 'd');
                        secondStage->addAnimation(lastAnimation);
                }
            }
        }
    }
    animations->addAnimation(secondStage);
    QParallelAnimationGroup *thirdStage = new QParallelAnimationGroup();
    for(int k = 0; k < 4; ++k){
        for(int i = 3; i >= 0; --i){
            if(grid.at(i)->at(k)->isInGame()){
                auto currentTile = grid.at(i)->at(k);
                for(int j = 3; j > i; --j)
                    if(!grid.at(j)->at(k)->isInGame()){
                        lastAnimation = moveTile(grid.at(j)->at(k), currentTile);
                        thirdStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(thirdStage);
    return animations;
}

QSequentialAnimationGroup* Grid::left()
{
    QPropertyAnimation *lastAnimation;
    QSequentialAnimationGroup *animations = new QSequentialAnimationGroup();
    QParallelAnimationGroup *firstStage = new QParallelAnimationGroup();
    // First stage
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < 4; ++i){
            if(grid.at(k)->at(i)->isInGame()){
                auto currentTile = grid.at(k)->at(i);
                for(int j = 0; j < i; ++j)
                    if(!grid.at(k)->at(j)->isInGame()){
                        lastAnimation = moveTile(grid.at(k)->at(j), currentTile);
                        firstStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(firstStage);
    QParallelAnimationGroup *secondStage = new QParallelAnimationGroup();
    // Second stage
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < 3; ++i){
            if(grid.at(k)->at(i)->isInGame()){
                auto currentTile = grid.at(k)->at(i);
                if(grid.at(k)->at(i+1)->isInGame() &&
                   grid.at(k)->at(i+1)->getScore() == currentTile->getScore()){
                        lastAnimation = combineTiles(currentTile, grid.at(k)->at(i+1), 'l');
                        secondStage->addAnimation(lastAnimation);
                }
            }
        }
    }
    animations->addAnimation(secondStage);
    // Third stage
    QParallelAnimationGroup *thirdStage = new QParallelAnimationGroup();
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < 4; ++i){
            if(grid.at(k)->at(i)->isInGame()){
                auto currentTile = grid.at(k)->at(i);
                for(int j = 0; j < i; ++j)
                    if(!grid.at(k)->at(j)->isInGame()){
                        lastAnimation = moveTile(grid.at(k)->at(j), currentTile);
                        thirdStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(thirdStage);
    return animations;
}

QSequentialAnimationGroup* Grid::right()
{
    QPropertyAnimation *lastAnimation;
    QSequentialAnimationGroup *animations = new QSequentialAnimationGroup();
    QParallelAnimationGroup *firstStage = new QParallelAnimationGroup();
    for(int k = 0; k < 4; ++k){
        for(int i = 3; i >= 0; --i){
            if(grid.at(k)->at(i)->isInGame()){
                auto currentTile = grid.at(k)->at(i);
                for(int j = 3; j > i; --j)
                    if(!grid.at(k)->at(j)->isInGame()){
                        lastAnimation = moveTile(grid.at(k)->at(j), currentTile);
                        firstStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(firstStage);
    QParallelAnimationGroup *secondStage = new QParallelAnimationGroup();
    // Second stage
    for(int k = 0; k < 4; ++k){
        for(int i = 3; i > 0; --i){
            if(grid.at(k)->at(i)->isInGame()){
                auto currentTile = grid.at(k)->at(i);
                if(grid.at(k)->at(i-1)->isInGame() &&
                   grid.at(k)->at(i-1)->getScore() == currentTile->getScore()){
                        lastAnimation = combineTiles(currentTile, grid.at(k)->at(i-1), 'r');
                        secondStage->addAnimation(lastAnimation);
                }
            }
        }
    }
    animations->addAnimation(secondStage);
    // Third stage
    QParallelAnimationGroup *thirdStage = new QParallelAnimationGroup();
    for(int k = 0; k < 4; ++k){
        for(int i = 3; i >= 0; --i){
            if(grid.at(k)->at(i)->isInGame()){
                auto currentTile = grid.at(k)->at(i);
                for(int j = 3; j > i; --j)
                    if(!grid.at(k)->at(j)->isInGame()){
                        lastAnimation = moveTile(grid.at(k)->at(j), currentTile);
                        thirdStage->addAnimation(lastAnimation);
                        break;
                    }
            }
        }
    }
    animations->addAnimation(thirdStage);
    return animations;
}

QPropertyAnimation* Grid::combineTiles(Tile *dest, Tile *source, char side)
{
    qreal startX, startY, newX, newY;
    if(side == 'l'){
        startX = (30 + 15*(dest->col+2) + 66.25*(dest->col+1));
        startY = (15*(dest->row +1) + 66.25*dest->row);
        newX = (30 + 15*(dest->col+1) + 66.25*dest->col);
        newY = startY;
    }else if(side == 'r'){
        startX = (30 + 15*(dest->col) + 66.25*(dest->col-1));
        startY = (15*(dest->row +1) + 66.25*dest->row);
        newX = (30 + 15*(dest->col+1) + 66.25*dest->col);
        newY = startY;
    }else if(side == 'u'){
        startX = (30 + 15*(dest->col+1) + 66.25*(dest->col));
        startY = (15*(dest->row + 2) + 66.25*(dest->row+1));
        newX = startX;
        newY = (15*(dest->row +1) + 66.25*dest->row);
    }else if(side == 'd'){
        startX = (30 + 15*(dest->col+1) + 66.25*(dest->col));
        startY = (15*(dest->row) + 66.25*(dest->row-1));
        newX = startX;
        newY = (15*(dest->row +1) + 66.25*dest->row);
    }


    QPropertyAnimation *animation = new QPropertyAnimation(source->rect, "pos");
    QObject::connect(animation, SIGNAL(finished()), dest->rect, SLOT(hideRect()));
    QObject::connect(animation, SIGNAL(finished()), source->rect, SLOT(doubleScore()));

    animation->setDuration(100);
    animation->setStartValue(QPointF(startX, startY));
    animation->setEndValue(QPointF(newX, newY));

    dest->rect = source->rect;
    dest->setScore(source->getScore()*2);
    source->setInGame(false);
    source->rect = nullptr;
    this->tilesInGameCount--;
    return animation;
}

QPropertyAnimation* Grid::moveTile(Tile *dest, Tile *source)
{
    dest->setScore(source->getScore());
    dest->rect = source->rect;
    //if(!dest->rect->isVisible())
    //    dest->rect->show();
    qreal newX = (30 + 15*(dest->col+1) + 66.25*dest->col);
    qreal newY = (15*(dest->row+1) + 66.25*dest->row);
    QPropertyAnimation *animation = new QPropertyAnimation(dest->rect, "pos");

    animation->setDuration(100);
    animation->setStartValue(dest->rect->pos());
    animation->setEndValue(QPointF(newX, newY));

    dest->setInGame(true);
    dest->setScore(source->getScore());
    source->rect = nullptr;
    source->setInGame(false);
    return animation;
}

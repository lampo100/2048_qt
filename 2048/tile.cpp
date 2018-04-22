#include "tile.h"

Tile::Tile(int row, int col)
{
    this->row = row;
    this->col = col;
}

Tile::Tile(const Tile &other)
{
    this->score = other.score;
    this->rect = other.rect;
    this->col = other.col;
    this->row = other.row;
}

Tile &Tile::operator=(const Tile &other)
{
    this->score = other.score;
    this->rect = other.rect;
    this->col = other.col;
    this->row = other.row;
    return *this;
}

void Tile::attachRect(RoundedRectangle *rect)
{
    this->rect = rect;
}

void Tile::setScore(qint32 score)
{
    this->score = score;
}

void Tile::setInGame(bool inGame)
{
    this->inGame = inGame;
}

bool Tile::isInGame()
{
    return this->inGame;
}

void Tile::setCoords(int row, int col)
{
    this->row = row;
    this->col = col;
}

qint32 Tile::getScore()
{
    return this->score;
}

void Tile::hide()
{
    this->setInGame(false);
    this->rect->hide();
}

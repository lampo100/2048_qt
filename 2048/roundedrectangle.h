#ifndef ROUNDEDRECTANGLE_H
#define ROUNDEDRECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QPen>
#include <QColor>
#include <QPainter>

class RoundedRectangle: public QGraphicsRectItem
{
public:
    RoundedRectangle(qreal x, qreal y, qreal width, qreal height, qreal rounding);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    void changeScore(qint64 score);

private:
    qreal rounding;
    QGraphicsSimpleTextItem *score;

};

#endif // ROUNDEDRECTANGLE_H

#ifndef ROUNDEDRECTANGLE_H
#define ROUNDEDRECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QPen>
#include <QColor>
#include <QPainter>
#include <QObject>

class RoundedRectangle:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)

public:
    RoundedRectangle(qreal x, qreal y, qreal width, qreal height, qreal rounding);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    void changeScore(qint64 score);


public slots:
    void hideRect();
    void doubleScore();

private:
    qreal rounding;
    QGraphicsSimpleTextItem *score;

};

#endif // ROUNDEDRECTANGLE_H

#include "roundedrectangle.h"

RoundedRectangle::RoundedRectangle(qreal x, qreal y, qreal width, qreal height, qreal rounding): QGraphicsRectItem(0, 0, width, height)
{
    this->rounding = rounding;
    this->setPos(x, y);
    this->score = new QGraphicsSimpleTextItem(QString(""), this);
}
void RoundedRectangle::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    QPainterPath path;
    QRectF a  = this->rect();
    path.addRoundedRect(this->rect(), this->rounding, this->rounding);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawPath(path);
}

void RoundedRectangle::changeScore(qint64 score)
{
    this->score->setText(QString::number(score));
    this->score->setFont(QFont("Times", 26));
    QColor brushColor;
    QColor penColor;
    if(score == 2){
        brushColor = QColor(238, 228, 218);
        penColor = QColor(120, 112, 101);
        this->score->setPos(this->rect().width()/2 - 10, this->rect().height()/2 - 20);
    }else if(score == 4){
        penColor = QColor(120, 112, 101);
        brushColor = QColor(236, 224, 202);
        this->score->setPos(this->rect().width()/2 - 10, this->rect().height()/2 - 20);
    }else if(score == 8){
        penColor = QColor(255, 255, 255);
        brushColor = QColor(255, 251, 126);
    }else if(score == 16){
        penColor = QColor(255, 255, 255);
        brushColor = QColor(245, 149, 101);
    }else if(score == 32){
        penColor = QColor(255, 255, 255);
        brushColor = QColor(245, 124, 95);
    }else if(score == 64){
        penColor = QColor(255, 255, 255);
        brushColor = QColor(246, 93, 59);
    }else if(score == 128){
        penColor = QColor(255, 255, 255);
        brushColor = QColor(237, 206, 113);
    }else if(score == 256){

    }else if(score == 512){

    }else if(score == 1024){

    }else if(score == 2048){

    }
    this->score->setPen(QPen(penColor));
    this->setBrush(QBrush(brushColor));
    this->setPen(QPen(brushColor));
}

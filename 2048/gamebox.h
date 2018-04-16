#ifndef GAMEBOX_H
#define GAMEBOX_H

#include <QWidget>
#include "qpainter.h"

class GameBox : public QWidget
{
    Q_OBJECT
public:
    explicit GameBox(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // GAMEBOX_H

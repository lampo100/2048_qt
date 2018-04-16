#include "gamebox.h"

GameBox::GameBox(QWidget *parent) : QWidget(parent)
{
}
void GameBox::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  QPen pen(Qt::black);
  pen.setWidth(4);
  painter.setPen(pen);
  QRect r = rect().adjusted(10, 10, -10, -10);
  painter.drawRoundedRect(r, 20, 10);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "roundedrectangle.h"
#include "grid.h"
#include "tile.h"
#include <QGraphicsSimpleTextItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void prepareViews();
    void prepareScenes();
    void paintBoard();

    void prepareLabels();
    void prepareLogo();
    void prepareScore();
    void prepareHighScore();
    void prepareGrid();

    RoundedRectangle *prepareNewRect(int, int, int);

    Ui::MainWindow *ui;
    QGraphicsScene *tilesScene;
    QGraphicsScene *labelsScene;

    QGraphicsSimpleTextItem *score;
    QGraphicsSimpleTextItem *highScore;

    Grid tilesGrid;

    // QWidget interface
protected:
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H

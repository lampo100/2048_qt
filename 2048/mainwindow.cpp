#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    prepareScenes();
    prepareViews();

    paintBoard();
    prepareLabels();

    prepareGrid();

    ui->tilesGraphicsView->show();
}

void MainWindow::prepareViews(){
    // Change background color and set no border
    ui->labelsGraphicsView->setStyleSheet("border: 0px; background-color: #fbf8ef");
    ui->tilesGraphicsView->setStyleSheet("border: 0px; background-color: #fbf8ef");

    ui->tilesGraphicsView->setSceneRect(0, 0, tilesScene->sceneRect().width(), tilesScene->sceneRect().height());
    ui->labelsGraphicsView->setSceneRect(0, 0, labelsScene->sceneRect().width(), labelsScene->sceneRect().height());
}

void MainWindow::prepareScenes(){
    tilesScene = new QGraphicsScene(this);
    tilesScene->setSceneRect(0, 0, 400, 360);

    labelsScene = new QGraphicsScene(this);
    labelsScene->setSceneRect(0, 0, 400, 120);

    ui->tilesGraphicsView->setScene(tilesScene);
    ui->labelsGraphicsView->setScene(labelsScene);
}

void MainWindow::paintBoard()
{
    QPen pen;
    pen.setWidth(0);
    pen.setColor(QColor(187, 173, 160));

    auto board = new RoundedRectangle(30, 0, 340, 340, 3);
    board->setPen(QPen(QColor(187, 173, 160)));
    board->setBrush(QBrush(QColor(187, 173, 160)));
    tilesScene->addItem(board);
}

void MainWindow::prepareLabels()
{
    prepareLogo();
    prepareScore();
    prepareHighScore();
}

void MainWindow::prepareLogo()
{
    auto logo = new RoundedRectangle(30, 15, 75, 75, 3);
    logo->setBrush(QBrush(QColor(236, 196, 0)));
    logo->setPen(QPen(QColor(236, 196, 0)));

    auto logoText = new QGraphicsSimpleTextItem("2048", logo);
    logoText->setBrush(QBrush(QColor(255, 255, 255)));
    QPen pen;
    pen.setColor(QColor(255, 255, 255));
    logoText->setPen(pen);
    logoText->setFont(QFont("Times", 20));
    logoText->setPos(logo->rect().width()/8, logo->rect().height()/4);

    labelsScene->addItem(logo);
    labelsScene->addItem(logoText);
}

void MainWindow::prepareScore()
{
    auto scoreRect = new RoundedRectangle(160, 15, 100, 55, 3);
    scoreRect->setBrush(QBrush(QColor(187, 173, 160)));
    scoreRect->setPen(QPen(QColor(187, 173, 160)));

    auto scoreText = new QGraphicsSimpleTextItem("Score", scoreRect);
    scoreText->setBrush(QBrush(QColor(237, 228, 213)));
    QPen pen;
    pen.setColor(QColor(237, 228, 213));
    scoreText->setPen(pen);
    scoreText->setFont(QFont("Times", 12));
    scoreText->setPos(scoreRect->rect().width()/4, scoreRect->rect().height()/9);

    auto score = new QGraphicsSimpleTextItem("0", scoreRect);
    this->score = score;
    score->setBrush(QBrush(QColor(255, 255, 255)));
    pen.setColor(QColor(255, 255, 255));
    score->setPen(pen);
    score->setFont(QFont("Times", 18));
    score->setPos(scoreRect->rect().width()/6, scoreRect->rect().height()*2/5);

    labelsScene->addItem(scoreRect);
    labelsScene->addItem(scoreText);
    labelsScene->addItem(score);

}

void MainWindow::prepareHighScore()
{
    auto scoreRect = new RoundedRectangle(270, 15, 100, 55, 3);
    scoreRect->setBrush(QBrush(QColor(187, 173, 160)));
    scoreRect->setPen(QPen(QColor(187, 173, 160)));

    auto scoreText = new QGraphicsSimpleTextItem("High Score", scoreRect);
    scoreText->setBrush(QBrush(QColor(237, 228, 213)));
    QPen pen;
    pen.setColor(QColor(237, 228, 213));
    scoreText->setPen(pen);
    scoreText->setFont(QFont("Times", 12));
    scoreText->setPos(scoreRect->rect().width()/9, scoreRect->rect().height()/9);

    auto score = new QGraphicsSimpleTextItem("0", scoreRect);
    this->score = score;
    score->setBrush(QBrush(QColor(255, 255, 255)));
    pen.setColor(QColor(255, 255, 255));
    score->setPen(pen);
    score->setFont(QFont("Times", 18));
    score->setPos(scoreRect->rect().width()/6, scoreRect->rect().height()*2/5);

    labelsScene->addItem(scoreRect);
    labelsScene->addItem(scoreText);
    labelsScene->addItem(score);
}

void MainWindow::prepareGrid()
{
    spawnNewTile();
    spawnNewTile();
}

void MainWindow::spawnNewTile()
{
    Tile * newTile = this->tilesGrid.spawnTile();
    if(newTile == nullptr)
        return;
    auto newRect = prepareNewRect(newTile->row, newTile->col, newTile->getScore());
    newTile->attachRect(newRect);
    this->tilesScene->addItem(newRect);

    QPropertyAnimation *anim = new QPropertyAnimation(newRect, "scale");
    newRect->setTransformOriginPoint(newRect->rect().width()/2, newRect->rect().height()/2);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setDuration(100);
    anim->start();
}

RoundedRectangle *MainWindow::prepareNewRect(int row, int col, int score)
{
    auto newRect = new RoundedRectangle((30 + 15*(col+1) + 66.25*col), (15*(row+1) + 66.25*row), 66.25, 66.25, 3);
    newRect->changeScore(score);
    return newRect;

}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    QSequentialAnimationGroup *animations;
    if(event->key() == Qt::Key_Left){
        animations = this->tilesGrid.left();
    }else if(event->key() == Qt::Key_Right){
        animations = this->tilesGrid.right();
    }else if(event->key() == Qt::Key_Up){
        animations = this->tilesGrid.up();
    }else if(event->key() == Qt::Key_Down){
        animations = this->tilesGrid.down();
    }else
        return;

    QObject::connect(animations, SIGNAL(finished()), this, SLOT(spawnNewTile()));
    animations->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}



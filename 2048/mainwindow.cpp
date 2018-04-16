#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameBox *gameBox = new GameBox;
    ui->centralWidget->layout()->addWidget(gameBox);
    gameBox->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

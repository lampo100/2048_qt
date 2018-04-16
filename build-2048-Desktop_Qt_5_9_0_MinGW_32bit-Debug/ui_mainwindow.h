/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *scoresLayout;
    QLabel *gameNameLabel;
    QLabel *gameScoreLabel;
    QLabel *highScoreLabel;
    QHBoxLayout *buttonsLayout;
    QPushButton *undoButton;
    QPushButton *restartButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(386, 606);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scoresLayout = new QHBoxLayout();
        scoresLayout->setSpacing(6);
        scoresLayout->setObjectName(QStringLiteral("scoresLayout"));
        gameNameLabel = new QLabel(centralWidget);
        gameNameLabel->setObjectName(QStringLiteral("gameNameLabel"));

        scoresLayout->addWidget(gameNameLabel);

        gameScoreLabel = new QLabel(centralWidget);
        gameScoreLabel->setObjectName(QStringLiteral("gameScoreLabel"));

        scoresLayout->addWidget(gameScoreLabel);

        highScoreLabel = new QLabel(centralWidget);
        highScoreLabel->setObjectName(QStringLiteral("highScoreLabel"));

        scoresLayout->addWidget(highScoreLabel);


        verticalLayout->addLayout(scoresLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(5);
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));

        buttonsLayout->addWidget(undoButton);

        restartButton = new QPushButton(centralWidget);
        restartButton->setObjectName(QStringLiteral("restartButton"));

        buttonsLayout->addWidget(restartButton);


        verticalLayout->addLayout(buttonsLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        gameNameLabel->setText(QApplication::translate("MainWindow", "2048", Q_NULLPTR));
        gameScoreLabel->setText(QApplication::translate("MainWindow", "Score", Q_NULLPTR));
        highScoreLabel->setText(QApplication::translate("MainWindow", "High Score", Q_NULLPTR));
        undoButton->setText(QApplication::translate("MainWindow", "undo", Q_NULLPTR));
        restartButton->setText(QApplication::translate("MainWindow", "restart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

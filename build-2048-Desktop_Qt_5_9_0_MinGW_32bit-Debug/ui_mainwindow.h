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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *labelsGraphicsView;
    QGraphicsView *tilesGraphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 480);
        MainWindow->setMinimumSize(QSize(400, 480));
        MainWindow->setMaximumSize(QSize(400, 480));
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(400, 480));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelsGraphicsView = new QGraphicsView(centralWidget);
        labelsGraphicsView->setObjectName(QStringLiteral("labelsGraphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelsGraphicsView->sizePolicy().hasHeightForWidth());
        labelsGraphicsView->setSizePolicy(sizePolicy);
        labelsGraphicsView->setMinimumSize(QSize(400, 120));
        labelsGraphicsView->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(labelsGraphicsView);

        tilesGraphicsView = new QGraphicsView(centralWidget);
        tilesGraphicsView->setObjectName(QStringLiteral("tilesGraphicsView"));
        tilesGraphicsView->setEnabled(true);
        tilesGraphicsView->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(tilesGraphicsView);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

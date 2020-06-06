/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionrange;
    QAction *actionhistorique;
    QAction *actionnewPOurTest;
    QAction *actiontesttesttest;
    QAction *actionDiagnostic;
    QAction *actionopenRange;
    QAction *actionrange_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuScanner;
    QMenu *menuaffihce;
    QMenu *menuplaying;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1073, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setFocusPolicy(Qt::TabFocus);
        actionrange = new QAction(MainWindow);
        actionrange->setObjectName(QString::fromUtf8("actionrange"));
        actionhistorique = new QAction(MainWindow);
        actionhistorique->setObjectName(QString::fromUtf8("actionhistorique"));
        actionnewPOurTest = new QAction(MainWindow);
        actionnewPOurTest->setObjectName(QString::fromUtf8("actionnewPOurTest"));
        actiontesttesttest = new QAction(MainWindow);
        actiontesttesttest->setObjectName(QString::fromUtf8("actiontesttesttest"));
        actionDiagnostic = new QAction(MainWindow);
        actionDiagnostic->setObjectName(QString::fromUtf8("actionDiagnostic"));
        actionopenRange = new QAction(MainWindow);
        actionopenRange->setObjectName(QString::fromUtf8("actionopenRange"));
        actionrange_2 = new QAction(MainWindow);
        actionrange_2->setObjectName(QString::fromUtf8("actionrange_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1073, 22));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuScanner = new QMenu(menuBar);
        menuScanner->setObjectName(QString::fromUtf8("menuScanner"));
        menuaffihce = new QMenu(menuBar);
        menuaffihce->setObjectName(QString::fromUtf8("menuaffihce"));
        menuplaying = new QMenu(menuBar);
        menuplaying->setObjectName(QString::fromUtf8("menuplaying"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuScanner->menuAction());
        menuBar->addAction(menuaffihce->menuAction());
        menuBar->addAction(menuplaying->menuAction());
        menufile->addAction(actionrange);
        menufile->addAction(actionhistorique);
        menufile->addAction(actionnewPOurTest);
        menufile->addAction(actiontesttesttest);
        menuScanner->addAction(actionDiagnostic);
        menuaffihce->addAction(actionopenRange);
        menuplaying->addAction(actionrange_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionrange->setText(QCoreApplication::translate("MainWindow", "range", nullptr));
        actionhistorique->setText(QCoreApplication::translate("MainWindow", "historique", nullptr));
        actionnewPOurTest->setText(QCoreApplication::translate("MainWindow", "newPOurTest", nullptr));
        actiontesttesttest->setText(QCoreApplication::translate("MainWindow", "testtesttest", nullptr));
        actionDiagnostic->setText(QCoreApplication::translate("MainWindow", "Diagnostic", nullptr));
        actionopenRange->setText(QCoreApplication::translate("MainWindow", "openRange", nullptr));
        actionrange_2->setText(QCoreApplication::translate("MainWindow", "range", nullptr));
        menufile->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
        menuScanner->setTitle(QCoreApplication::translate("MainWindow", "Scanner", nullptr));
        menuaffihce->setTitle(QCoreApplication::translate("MainWindow", "affihce", nullptr));
        menuplaying->setTitle(QCoreApplication::translate("MainWindow", "playing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'diagreadbet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGREADBET_H
#define UI_DIAGREADBET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diagReadBet
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *scanImage;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *stack1;
    QLabel *valueStack1;
    QLabel *v1;
    QLabel *valBetMp;
    QLabel *v2;
    QLabel *valBetCo;
    QLabel *v3;
    QLabel *valBetBt;
    QLabel *imBetSb;
    QLabel *valBetSb;
    QLabel *imBetBb;
    QLabel *valBetBb;
    QWidget *tabOpt;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btStartStrop;
    QPushButton *btTakeScreen;

    void setupUi(QWidget *diagReadBet)
    {
        if (diagReadBet->objectName().isEmpty())
            diagReadBet->setObjectName(QString::fromUtf8("diagReadBet"));
        diagReadBet->resize(527, 501);
        verticalLayout = new QVBoxLayout(diagReadBet);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scanImage = new QLabel(diagReadBet);
        scanImage->setObjectName(QString::fromUtf8("scanImage"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scanImage->sizePolicy().hasHeightForWidth());
        scanImage->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(scanImage);

        tabWidget = new QTabWidget(diagReadBet);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stack1 = new QLabel(tab);
        stack1->setObjectName(QString::fromUtf8("stack1"));

        gridLayout->addWidget(stack1, 0, 0, 1, 1);

        valueStack1 = new QLabel(tab);
        valueStack1->setObjectName(QString::fromUtf8("valueStack1"));

        gridLayout->addWidget(valueStack1, 0, 1, 1, 1);

        v1 = new QLabel(tab);
        v1->setObjectName(QString::fromUtf8("v1"));

        gridLayout->addWidget(v1, 1, 0, 1, 1);

        valBetMp = new QLabel(tab);
        valBetMp->setObjectName(QString::fromUtf8("valBetMp"));

        gridLayout->addWidget(valBetMp, 1, 1, 1, 1);

        v2 = new QLabel(tab);
        v2->setObjectName(QString::fromUtf8("v2"));

        gridLayout->addWidget(v2, 2, 0, 1, 1);

        valBetCo = new QLabel(tab);
        valBetCo->setObjectName(QString::fromUtf8("valBetCo"));

        gridLayout->addWidget(valBetCo, 2, 1, 1, 1);

        v3 = new QLabel(tab);
        v3->setObjectName(QString::fromUtf8("v3"));

        gridLayout->addWidget(v3, 3, 0, 1, 1);

        valBetBt = new QLabel(tab);
        valBetBt->setObjectName(QString::fromUtf8("valBetBt"));

        gridLayout->addWidget(valBetBt, 3, 1, 1, 1);

        imBetSb = new QLabel(tab);
        imBetSb->setObjectName(QString::fromUtf8("imBetSb"));

        gridLayout->addWidget(imBetSb, 4, 0, 1, 1);

        valBetSb = new QLabel(tab);
        valBetSb->setObjectName(QString::fromUtf8("valBetSb"));

        gridLayout->addWidget(valBetSb, 4, 1, 1, 1);

        imBetBb = new QLabel(tab);
        imBetBb->setObjectName(QString::fromUtf8("imBetBb"));

        gridLayout->addWidget(imBetBb, 5, 0, 1, 1);

        valBetBb = new QLabel(tab);
        valBetBb->setObjectName(QString::fromUtf8("valBetBb"));

        gridLayout->addWidget(valBetBb, 5, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tabOpt = new QWidget();
        tabOpt->setObjectName(QString::fromUtf8("tabOpt"));
        verticalLayout_2 = new QVBoxLayout(tabOpt);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(tabOpt);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        tabWidget->addTab(tabOpt, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btStartStrop = new QPushButton(diagReadBet);
        btStartStrop->setObjectName(QString::fromUtf8("btStartStrop"));

        horizontalLayout->addWidget(btStartStrop);

        btTakeScreen = new QPushButton(diagReadBet);
        btTakeScreen->setObjectName(QString::fromUtf8("btTakeScreen"));

        horizontalLayout->addWidget(btTakeScreen);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(diagReadBet);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(diagReadBet);
    } // setupUi

    void retranslateUi(QWidget *diagReadBet)
    {
        diagReadBet->setWindowTitle(QCoreApplication::translate("diagReadBet", "Diagnostic Image Reader", nullptr));
        scanImage->setText(QCoreApplication::translate("diagReadBet", "image Scann\303\251", nullptr));
        stack1->setText(QCoreApplication::translate("diagReadBet", "Im bet UTG", nullptr));
        valueStack1->setText(QCoreApplication::translate("diagReadBet", "Val bet UTG", nullptr));
        v1->setText(QCoreApplication::translate("diagReadBet", "Im bet MP", nullptr));
        valBetMp->setText(QCoreApplication::translate("diagReadBet", "Val bet MP", nullptr));
        v2->setText(QCoreApplication::translate("diagReadBet", "Im bet CO", nullptr));
        valBetCo->setText(QCoreApplication::translate("diagReadBet", "Val bet CO", nullptr));
        v3->setText(QCoreApplication::translate("diagReadBet", "Im bet BT", nullptr));
        valBetBt->setText(QCoreApplication::translate("diagReadBet", "Val bet BT", nullptr));
        imBetSb->setText(QCoreApplication::translate("diagReadBet", "Im bet SB", nullptr));
        valBetSb->setText(QCoreApplication::translate("diagReadBet", "Val bet SB", nullptr));
        imBetBb->setText(QCoreApplication::translate("diagReadBet", "Im bet BB", nullptr));
        valBetBb->setText(QCoreApplication::translate("diagReadBet", "Val bet BB", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("diagReadBet", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabOpt), QCoreApplication::translate("diagReadBet", "Tab 2", nullptr));
        btStartStrop->setText(QCoreApplication::translate("diagReadBet", "Start Scan", nullptr));
        btTakeScreen->setText(QCoreApplication::translate("diagReadBet", "Take screen (0)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class diagReadBet: public Ui_diagReadBet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGREADBET_H

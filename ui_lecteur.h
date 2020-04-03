/********************************************************************************
** Form generated from reading UI file 'lecteur.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTEUR_H
#define UI_LECTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lecteur
{
public:
    QLabel *H2_0;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *flop_1;
    QLabel *flop_2;
    QLabel *flop_3;
    QLabel *turn;
    QLabel *river;
    QLabel *label_pot;
    QLabel *pot;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *precedent;
    QPushButton *suivant;
    QLabel *nb_current_etat;
    QLabel *M1;
    QLabel *M2;
    QLabel *M3;
    QLabel *M4;
    QLabel *M5;
    QLabel *M6;
    QFrame *frame2;
    QVBoxLayout *verticalLayout;
    QLabel *J2;
    QLabel *T2;
    QLabel *display;
    QLabel *H2_1;
    QLabel *H3_0;
    QLabel *H3_1;
    QFrame *frame3;
    QVBoxLayout *verticalLayout_2;
    QLabel *J3;
    QLabel *T3;
    QLabel *H4_0;
    QLabel *H4_1;
    QFrame *frame4;
    QVBoxLayout *verticalLayout_3;
    QLabel *J4;
    QLabel *T4;
    QLabel *H5_0;
    QLabel *H5_1;
    QFrame *frame5;
    QVBoxLayout *verticalLayout_4;
    QLabel *J5;
    QLabel *T5;
    QLabel *H6_0;
    QLabel *H6_1;
    QFrame *frame6;
    QVBoxLayout *verticalLayout_5;
    QLabel *J6;
    QLabel *T6;
    QLabel *H1_0;
    QLabel *H1_1;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_6;
    QLabel *J1;
    QLabel *T1;
    QLabel *BT1;
    QLabel *BT2;
    QLabel *BT3;
    QLabel *BT4;
    QLabel *BT5;
    QLabel *BT6;

    void setupUi(QWidget *lecteur)
    {
        if (lecteur->objectName().isEmpty())
            lecteur->setObjectName(QString::fromUtf8("lecteur"));
        lecteur->resize(957, 709);
        lecteur->setAutoFillBackground(false);
        lecteur->setStyleSheet(QString::fromUtf8("QWidget#lecteur { background-image:url(:/48173892.png) }"));
        H2_0 = new QLabel(lecteur);
        H2_0->setObjectName(QString::fromUtf8("H2_0"));
        H2_0->setGeometry(QRect(30, 210, 51, 41));
        H2_0->setAutoFillBackground(false);
        H2_0->setStyleSheet(QString::fromUtf8("background: #f00000;\n"
"border-top: 2px solid white;\n"
"border-right: 2px solid white;\n"
"border-left: 2px solid white;\n"
"border-top-left-radius: 2px;\n"
"border-top-right-radius: 2px;"));
        H2_0->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(lecteur);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(320, 260, 291, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        flop_1 = new QLabel(horizontalLayoutWidget_2);
        flop_1->setObjectName(QString::fromUtf8("flop_1"));
        flop_1->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-radius: 2px;\n"
"background: #3036c7;"));
        flop_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(flop_1);

        flop_2 = new QLabel(horizontalLayoutWidget_2);
        flop_2->setObjectName(QString::fromUtf8("flop_2"));
        flop_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(flop_2);

        flop_3 = new QLabel(horizontalLayoutWidget_2);
        flop_3->setObjectName(QString::fromUtf8("flop_3"));
        flop_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(flop_3);

        turn = new QLabel(horizontalLayoutWidget_2);
        turn->setObjectName(QString::fromUtf8("turn"));
        turn->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(turn);

        river = new QLabel(horizontalLayoutWidget_2);
        river->setObjectName(QString::fromUtf8("river"));
        river->setStyleSheet(QString::fromUtf8(""));
        river->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(river);

        label_pot = new QLabel(lecteur);
        label_pot->setObjectName(QString::fromUtf8("label_pot"));
        label_pot->setGeometry(QRect(400, 180, 131, 31));
        label_pot->setAlignment(Qt::AlignCenter);
        pot = new QLabel(lecteur);
        pot->setObjectName(QString::fromUtf8("pot"));
        pot->setGeometry(QRect(390, 210, 131, 31));
        pot->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(lecteur);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 620, 301, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        precedent = new QPushButton(horizontalLayoutWidget);
        precedent->setObjectName(QString::fromUtf8("precedent"));

        horizontalLayout->addWidget(precedent);

        suivant = new QPushButton(horizontalLayoutWidget);
        suivant->setObjectName(QString::fromUtf8("suivant"));

        horizontalLayout->addWidget(suivant);

        nb_current_etat = new QLabel(horizontalLayoutWidget);
        nb_current_etat->setObjectName(QString::fromUtf8("nb_current_etat"));
        nb_current_etat->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nb_current_etat);

        M1 = new QLabel(lecteur);
        M1->setObjectName(QString::fromUtf8("M1"));
        M1->setGeometry(QRect(270, 410, 59, 21));
        M2 = new QLabel(lecteur);
        M2->setObjectName(QString::fromUtf8("M2"));
        M2->setGeometry(QRect(190, 250, 61, 31));
        M3 = new QLabel(lecteur);
        M3->setObjectName(QString::fromUtf8("M3"));
        M3->setGeometry(QRect(290, 150, 61, 41));
        M4 = new QLabel(lecteur);
        M4->setObjectName(QString::fromUtf8("M4"));
        M4->setGeometry(QRect(580, 150, 61, 31));
        M5 = new QLabel(lecteur);
        M5->setObjectName(QString::fromUtf8("M5"));
        M5->setGeometry(QRect(700, 290, 61, 51));
        M6 = new QLabel(lecteur);
        M6->setObjectName(QString::fromUtf8("M6"));
        M6->setGeometry(QRect(520, 420, 61, 31));
        frame2 = new QFrame(lecteur);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        frame2->setGeometry(QRect(20, 250, 131, 66));
        frame2->setAutoFillBackground(false);
        frame2->setStyleSheet(QString::fromUtf8("background: rgb(164, 179, 255)"));
        frame2->setFrameShape(QFrame::StyledPanel);
        frame2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        J2 = new QLabel(frame2);
        J2->setObjectName(QString::fromUtf8("J2"));
        J2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(J2);

        T2 = new QLabel(frame2);
        T2->setObjectName(QString::fromUtf8("T2"));
        T2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(T2);

        display = new QLabel(lecteur);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(300, 360, 341, 41));
        display->setFrameShadow(QFrame::Raised);
        display->setAlignment(Qt::AlignCenter);
        H2_1 = new QLabel(lecteur);
        H2_1->setObjectName(QString::fromUtf8("H2_1"));
        H2_1->setGeometry(QRect(90, 210, 51, 41));
        H2_1->setAutoFillBackground(false);
        H2_1->setStyleSheet(QString::fromUtf8("border-top: 2px outset white;\n"
"border-right: 2px outset white;\n"
"border-left: 2px outset white;\n"
"border-top-left-radius: 2px;\n"
"border-top-right-radius: 2px;\n"
"background: #1f1219"));
        H2_1->setAlignment(Qt::AlignCenter);
        H3_0 = new QLabel(lecteur);
        H3_0->setObjectName(QString::fromUtf8("H3_0"));
        H3_0->setGeometry(QRect(230, 40, 41, 41));
        H3_0->setAutoFillBackground(false);
        H3_0->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H3_0->setAlignment(Qt::AlignCenter);
        H3_1 = new QLabel(lecteur);
        H3_1->setObjectName(QString::fromUtf8("H3_1"));
        H3_1->setGeometry(QRect(280, 40, 41, 41));
        H3_1->setAutoFillBackground(false);
        H3_1->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H3_1->setAlignment(Qt::AlignCenter);
        frame3 = new QFrame(lecteur);
        frame3->setObjectName(QString::fromUtf8("frame3"));
        frame3->setGeometry(QRect(210, 80, 131, 66));
        frame3->setAutoFillBackground(true);
        frame3->setFrameShape(QFrame::StyledPanel);
        frame3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        J3 = new QLabel(frame3);
        J3->setObjectName(QString::fromUtf8("J3"));
        J3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(J3);

        T3 = new QLabel(frame3);
        T3->setObjectName(QString::fromUtf8("T3"));
        T3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(T3);

        H4_0 = new QLabel(lecteur);
        H4_0->setObjectName(QString::fromUtf8("H4_0"));
        H4_0->setGeometry(QRect(550, 30, 41, 41));
        H4_0->setAutoFillBackground(false);
        H4_0->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H4_0->setAlignment(Qt::AlignCenter);
        H4_1 = new QLabel(lecteur);
        H4_1->setObjectName(QString::fromUtf8("H4_1"));
        H4_1->setGeometry(QRect(600, 30, 41, 41));
        H4_1->setAutoFillBackground(false);
        H4_1->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H4_1->setAlignment(Qt::AlignCenter);
        frame4 = new QFrame(lecteur);
        frame4->setObjectName(QString::fromUtf8("frame4"));
        frame4->setGeometry(QRect(530, 70, 131, 66));
        frame4->setAutoFillBackground(true);
        frame4->setFrameShape(QFrame::StyledPanel);
        frame4->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        J4 = new QLabel(frame4);
        J4->setObjectName(QString::fromUtf8("J4"));
        J4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(J4);

        T4 = new QLabel(frame4);
        T4->setObjectName(QString::fromUtf8("T4"));
        T4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(T4);

        H5_0 = new QLabel(lecteur);
        H5_0->setObjectName(QString::fromUtf8("H5_0"));
        H5_0->setGeometry(QRect(770, 250, 41, 41));
        H5_0->setAutoFillBackground(false);
        H5_0->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H5_0->setAlignment(Qt::AlignCenter);
        H5_1 = new QLabel(lecteur);
        H5_1->setObjectName(QString::fromUtf8("H5_1"));
        H5_1->setGeometry(QRect(820, 250, 41, 41));
        H5_1->setAutoFillBackground(false);
        H5_1->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H5_1->setAlignment(Qt::AlignCenter);
        frame5 = new QFrame(lecteur);
        frame5->setObjectName(QString::fromUtf8("frame5"));
        frame5->setGeometry(QRect(750, 290, 131, 66));
        frame5->setAutoFillBackground(true);
        frame5->setFrameShape(QFrame::StyledPanel);
        frame5->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        J5 = new QLabel(frame5);
        J5->setObjectName(QString::fromUtf8("J5"));
        J5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(J5);

        T5 = new QLabel(frame5);
        T5->setObjectName(QString::fromUtf8("T5"));
        T5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(T5);

        H6_0 = new QLabel(lecteur);
        H6_0->setObjectName(QString::fromUtf8("H6_0"));
        H6_0->setGeometry(QRect(540, 500, 41, 41));
        H6_0->setAutoFillBackground(false);
        H6_0->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H6_0->setAlignment(Qt::AlignCenter);
        H6_1 = new QLabel(lecteur);
        H6_1->setObjectName(QString::fromUtf8("H6_1"));
        H6_1->setGeometry(QRect(590, 500, 41, 41));
        H6_1->setAutoFillBackground(false);
        H6_1->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H6_1->setAlignment(Qt::AlignCenter);
        frame6 = new QFrame(lecteur);
        frame6->setObjectName(QString::fromUtf8("frame6"));
        frame6->setGeometry(QRect(520, 540, 131, 66));
        frame6->setAutoFillBackground(true);
        frame6->setFrameShape(QFrame::StyledPanel);
        frame6->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        J6 = new QLabel(frame6);
        J6->setObjectName(QString::fromUtf8("J6"));
        J6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(J6);

        T6 = new QLabel(frame6);
        T6->setObjectName(QString::fromUtf8("T6"));
        T6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(T6);

        H1_0 = new QLabel(lecteur);
        H1_0->setObjectName(QString::fromUtf8("H1_0"));
        H1_0->setGeometry(QRect(250, 480, 41, 41));
        H1_0->setAutoFillBackground(false);
        H1_0->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H1_0->setAlignment(Qt::AlignCenter);
        H1_1 = new QLabel(lecteur);
        H1_1->setObjectName(QString::fromUtf8("H1_1"));
        H1_1->setGeometry(QRect(300, 480, 41, 41));
        H1_1->setAutoFillBackground(false);
        H1_1->setStyleSheet(QString::fromUtf8("background-image: url(:/dos carte rouge.jpeg);"));
        H1_1->setAlignment(Qt::AlignCenter);
        frame1 = new QFrame(lecteur);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setGeometry(QRect(230, 520, 131, 66));
        frame1->setAutoFillBackground(true);
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        J1 = new QLabel(frame1);
        J1->setObjectName(QString::fromUtf8("J1"));
        J1->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(J1);

        T1 = new QLabel(frame1);
        T1->setObjectName(QString::fromUtf8("T1"));
        T1->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(T1);

        BT1 = new QLabel(lecteur);
        BT1->setObjectName(QString::fromUtf8("BT1"));
        BT1->setGeometry(QRect(320, 425, 59, 31));
        BT1->setAlignment(Qt::AlignCenter);
        BT2 = new QLabel(lecteur);
        BT2->setObjectName(QString::fromUtf8("BT2"));
        BT2->setGeometry(QRect(160, 310, 59, 31));
        BT3 = new QLabel(lecteur);
        BT3->setObjectName(QString::fromUtf8("BT3"));
        BT3->setGeometry(QRect(200, 160, 59, 31));
        BT4 = new QLabel(lecteur);
        BT4->setObjectName(QString::fromUtf8("BT4"));
        BT4->setGeometry(QRect(630, 170, 59, 31));
        BT5 = new QLabel(lecteur);
        BT5->setObjectName(QString::fromUtf8("BT5"));
        BT5->setGeometry(QRect(680, 360, 59, 31));
        BT6 = new QLabel(lecteur);
        BT6->setObjectName(QString::fromUtf8("BT6"));
        BT6->setGeometry(QRect(570, 440, 59, 31));

        retranslateUi(lecteur);

        QMetaObject::connectSlotsByName(lecteur);
    } // setupUi

    void retranslateUi(QWidget *lecteur)
    {
        lecteur->setWindowTitle(QCoreApplication::translate("lecteur", "lecteur", nullptr));
        H2_0->setText(QString());
        flop_1->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">9</span></p></body></html>", nullptr));
        flop_2->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#3036c7;\">8</span><span style=\" font-family:'Noto Music,Noto Sans Symbols,Noto Sans Symbols2,Noto Sans,Noto Sans Display,Noto Sans Mono,Noto Sans Math,Cambria Math,Noto Serif,Noto Serif Disp,serif,Segoe UI Symbol,sans-serif'; font-size:20px; color:#fc001a;\">\342\231\243</span></p></body></html>", nullptr));
        flop_3->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#f00000;\">7</span></p></body></html>", nullptr));
        turn->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#1f1219;\">5</span></p></body></html>", nullptr));
        river->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#005e16;\">6</span></p></body></html>", nullptr));
        label_pot->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:20pt; color:#ffffff;\">POT TOTAL</span></p></body></html>", nullptr));
        pot->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:20pt; color:#ffffff;\">0\342\202\254</span></p></body></html>", nullptr));
        precedent->setText(QCoreApplication::translate("lecteur", "pr\303\251c\303\251dent", nullptr));
        suivant->setText(QCoreApplication::translate("lecteur", "suivant", nullptr));
        nb_current_etat->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" color:#ffffff;\">0 / 0</span></p></body></html>", nullptr));
        M1->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">X</span></p></body></html>", nullptr));
        M2->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">X</span></p></body></html>", nullptr));
        M3->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">X</span></p></body></html>", nullptr));
        M4->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">X</span></p></body></html>", nullptr));
        M5->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">X</span></p></body></html>", nullptr));
        M6->setText(QCoreApplication::translate("lecteur", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">X</span></p></body></html>", nullptr));
        J2->setText(QCoreApplication::translate("lecteur", "VIDE", nullptr));
        T2->setText(QCoreApplication::translate("lecteur", "0", nullptr));
        display->setText(QCoreApplication::translate("lecteur", "ACTION", nullptr));
        H2_1->setText(QString());
        H3_0->setText(QString());
        H3_1->setText(QString());
        J3->setText(QCoreApplication::translate("lecteur", "VIDE", nullptr));
        T3->setText(QCoreApplication::translate("lecteur", "0", nullptr));
        H4_0->setText(QString());
        H4_1->setText(QString());
        J4->setText(QCoreApplication::translate("lecteur", "VIDE", nullptr));
        T4->setText(QCoreApplication::translate("lecteur", "0", nullptr));
        H5_0->setText(QString());
        H5_1->setText(QString());
        J5->setText(QCoreApplication::translate("lecteur", "VIDE", nullptr));
        T5->setText(QCoreApplication::translate("lecteur", "0", nullptr));
        H6_0->setText(QString());
        H6_1->setText(QString());
        J6->setText(QCoreApplication::translate("lecteur", "VIDE", nullptr));
        T6->setText(QCoreApplication::translate("lecteur", "0", nullptr));
        H1_0->setText(QString());
        H1_1->setText(QString());
        J1->setText(QCoreApplication::translate("lecteur", "VIDE", nullptr));
        T1->setText(QCoreApplication::translate("lecteur", "0", nullptr));
        BT1->setText(QString());
        BT2->setText(QString());
        BT3->setText(QString());
        BT4->setText(QString());
        BT5->setText(QString());
        BT6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lecteur: public Ui_lecteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTEUR_H

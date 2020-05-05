#ifndef UTIL_H
#define UTIL_H

#define WHITE(x) ("<span style=\" color:#ffffff;\">" + x + "</span>")
#define PIQUE(x) ("<span style=\" font-size:24pt; font-weight:600; color:#1f1219\">" + x + "</span>")
#define COEUR(x) ("<span style=\" font-size:24pt; font-weight:600; color:#f00000\">" + x + "</span>")
#define CARREAU(x) ("<span style=\" font-size:24pt; font-weight:600; color:#3036c7\">" + x + "</span>")
#define TREFLE(x) ("<span style=\" font-size:24pt; font-weight:600; color:#005e16\">" + x + "</span>")
#define C_BT(x) ("<span style=\" font-size:24pt; color:#d9d13d;\">B</span>")
#define BIG_WHITE(x) ("<span style=\" font-size:24pt; color:white\">" + x + "</span>")
#define C_PIQUE ("#1f1219")
#define C_COEUR ("#f00000")
#define C_CARREAU ("#3036c7")
#define C_TREFLE ("#005e16")

#include <QString>
#include <QFile>
#include <QLabel>
#include <QDebug>
#include "card.h"
#include <QPoint>

QString         convert_unit(int i);
QString         convert(int i, int j);
QStringList     str_liste_hands(QString file, int debut = 0);
QString         toStrCard(int i, int j);
QPoint          strCardToCoordonate(QString str);

typedef struct s_card {
    QString str;
    int     rang;
    e_color couleur;
    QString str_rang;
    s_card()
    {
        str = "";
        str_rang = "";
        couleur = e_color::undefined;
        rang = 0;
    }
    s_card(QString s)
    {
        str = s;
        str_rang = QString(s.at(0));
        if (str.at(0).isNumber())
            rang = str.at(0).digitValue();
        else {
            switch(str.at(0).unicode())
            {
            case 'A':
                rang = 14;
                break;
            case 'K':
                rang = 13;
                break;
            case 'Q':
                rang = 12;
                break;
            case 'J':
                rang = 11;
                break;
            case 'T':
                rang = 10;
                break;
            }
        }
        switch(str.at(1).unicode())
        {
        case 'h':
            couleur = e_color::coeur;
            break;
        case 'd':
            couleur = e_color::carreau;
            break;
        case 's':
            couleur = e_color::pique;
            break;
        case 'c':
            couleur = e_color::trefle;
            break;
        }
    }
    QString    format()
    {
        switch(couleur)
        {
        case e_color::coeur:
            return COEUR(str_rang);
        case e_color::carreau:
            return CARREAU(str_rang);
        case e_color::pique:
            return PIQUE(str_rang);
        case e_color::trefle:
            return TREFLE(str_rang);
        default:
            return BIG_WHITE(str_rang);
        }
    }
    void    affiche_card(QLabel *l)
    {
        QString style_base ="border: 2px solid white; border-top-left-radius: 2px;text-align: center;";
        l->setText(format());
        l->setStyleSheet(style_base + "background:" + color() + ";");
        l->show();
    }
    void    affiche_card_coupe(QLabel *l)
    {
        QString style_base =    "border-top: 2px solid white;\
                                border-right: 2px solid white;\
                                border-left: 2px solid white;\
                                border-top-left-radius: 2px;\
                                border-top-right-radius: 2px;";
        l->setText(format());
        l->setStyleSheet(style_base + "background:" + color() + ";");
        l->show();
    }
    QString    color()
    {
        switch(couleur)
        {
        case e_color::coeur:
            return C_COEUR;
        case e_color::carreau:
            return C_CARREAU;
        case e_color::pique:
            return C_PIQUE;
        case e_color::trefle:
            return C_TREFLE;
        default:
            return BIG_WHITE(str_rang);
        }
    }

} card;

typedef struct s_hand{
    QString joueur;
    QString str_hand;
    QString str_type_hand;
    card    c[2];
    s_hand(){

    }
    s_hand(QString j, QString card)
    {
        joueur = j;
        QStringList lc = card.split(' ');
        c[0] = s_card(lc.at(0));
        c[1] = s_card(lc.at(1));
        str_hand = c[0].str + c[1].str;
        str_type_hand = type_hand();
    }
    s_hand(QString line)
    {
        int index_debut_name = line.indexOf("to ") + 3;
        joueur = line.mid(index_debut_name);
        joueur = joueur.mid(0, 3);
        qDebug() << "nom joueur " << joueur << endl;
        c[0] = s_card(line.mid(line.indexOf('[') + 1, 2));
        c[1] = s_card(line.mid(line.indexOf(']') - 2, 2));
        str_hand = c[0].str + c[1].str;
        str_type_hand = type_hand();
    }
    QString type_hand()
    {
        QString res;
        if (c[0].rang == c[1].rang)
            return (c[0].str_rang + c[1].str_rang);

        if (c[0].rang > c[1].rang)
            res = c[0].str_rang + c[1].str_rang;
        else
            res = c[1].str_rang + c[0].str_rang;
        if (c[0].couleur == c[1].couleur)
            res += "s";
        else
            res += "o";
        return (res);
    }
    QString getStrHand() {return str_hand;}
    QString getTypeHand() {return str_type_hand;}
} hand;

typedef enum position {
    BB = 0,
    SB,
    BT,
    CO,
    MP,
    UTG,
    UTG1,
    UTG2,
    UTG3,
    UTG4,
    UTG5,
    UTG6,
    NULLpos = -1,
} e_position;

QString    stringPos(e_position pos);

#endif // UTIL_H

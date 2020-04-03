#include "lecteur.h"
#include "ui_lecteur.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QString>
#include <QtWidgets>
#include "SQL.h"

using namespace std;

void    fake_hide(QLabel *l)
{
    l->setText("");
    l->setStyleSheet("");
}

lecteur::lecteur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lecteur)
{
    ui->setupUi(this);
    current_etat = 0;

    QPalette        p;
    etat   *etat0 = new etat;
    p = palette();
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/48173892.png")));
    setPalette(p);

    setWindowFlag(Qt::Window);
    etat0->pot = 0;
    etat0->bouton = 1;
    for(int i(0); i < 6; i++)
    {
        etat0->mise[i] = 0;
        etat0->tapis[i] = 0;
    }
    l_etat.push_back(etat0);
    ui->precedent->setShortcut(QKeySequence("LEFT"));
    ui->suivant->setShortcut(QKeySequence("RIGHT"));
    connect(ui->precedent, SIGNAL(clicked()), this, SLOT(etat_precedent()));
    connect(ui->suivant, SIGNAL(clicked()), this, SLOT(etat_suivant()));
}

void    lecteur::read_jeux(QString text)
{
    QStringList liste_ligne = text.split('\n');
    read_summary(liste_ligne, calcul_etat(liste_ligne, init_table(liste_ligne) + 1));
    ui->nb_current_etat->setText(QString::number(current_etat) + " / " + QString::number(nb_etat - 1));
    nb_etat = l_etat.size();
    read_etat(0);
    affiche_my_hand();
}

int    lecteur::init_table(QStringList l_ligne)
{
    int     i(2);
    QString line = l_ligne.at(1);
    QString name;
    QString tapis;
    QString id;
    QLabel  *label;
    etat    *etat0 = l_etat.first();
    etat0->action = "INIT";

    if (line.contains("button"))
    {
        etat0->bouton = line.mid(line.indexOf('#') + 1, 1).toInt();
    }
    line = l_ligne.at(2);
    while  (line.contains("Seat"))
    {
        name = line.mid(line.indexOf(':') + 2, line.indexOf('(') - line.indexOf(':') - 3);
        id =  l_ligne.at(i).at(l_ligne.at(i).indexOf(':') - 1);
        tapis = line.mid(line.indexOf("€") + 1, line.mid(line.indexOf("€")).indexOf(" ") - 1);
        id_joueur[name] = id;
        this->findChild<QLabel*>("J" + id)->setText(name);
        etat0->tapis[id.toInt() - 1] = tapis.toDouble();
        etat0->j[id.toInt() - 1] = true;
        i++;
        line = l_ligne.at(i);
    }
    while (!line.contains("***"))
    {
        if (line.contains("posts small blind"))
        {
            id = id_joueur[line.mid(0, line.indexOf(':'))];
            QString mise = line.mid(line.lastIndexOf(' ') + 2, line.indexOf('\n'));
            etat0->mise[id.toInt() - 1] = mise.toDouble();
            etat0->tapis[id.toInt() - 1] -= mise.toDouble();
            etat0->pot += mise.toDouble();
        }
        if (line.contains("posts big blind"))
        {
            id = id_joueur[line.mid(0, line.indexOf(':'))];
            QString mise = line.mid(line.lastIndexOf(' ') + 2, line.indexOf('\n')) ;
            etat0->mise[id.toInt() - 1] = mise.toDouble();
            etat0->tapis[id.toInt() - 1] -= mise.toDouble();
            etat0->pot += mise.toDouble();
        }
        i++;
        line = l_ligne.at(i);
    }
    line = l_ligne.at(i + 1);
    if (line.contains("Dealt"))
    {
        jeux.my_hand.joueur = line.mid(line.indexOf("to ") + 3, line.indexOf('[') - (line.indexOf("to ") + 4));
        id_hero = id_joueur[jeux.my_hand.joueur].toInt() - 1;
        jeux.my_hand.c[0] = s_card(line.mid(line.indexOf('[') + 1, 2));
        jeux.my_hand.c[1] = s_card(line.mid(line.indexOf(']') - 2, 2));
    }
    return (i + 1);
}

int lecteur::calcul_etat(QStringList l, int debut)
{
    int num_etat = 1;
    double  mise(0);
    etat *current;
    QString line;
    etat test;
    QString ttest;
    int num_j;

    while (debut < l.size())
    {
        line = l.at(debut++);
        mise = 0;
        num_j = id_joueur[line.mid(0, line.indexOf(':'))].toInt() - 1;
        if (line.contains(": fold"))
        {
            current = new s_etat(*l_etat.at(num_etat - 1));
            current->j[num_j] = false;
            mise = 0;
            num_etat++;
            current->joueur_actif = num_j;
        }
        else if (line.contains(": raises"))
        {
            current = new s_etat(*l_etat.at(num_etat - 1));
            mise = line.mid(line.lastIndexOf("€") + 1, line.mid(line.lastIndexOf("€") + 1).indexOf(' ')).toDouble() - l_etat.at(num_etat - 1)->mise[num_j];
            num_etat++;
            current->joueur_actif = num_j;
        }
        else if (line.contains(": call") || line.contains(": bets")){
            current = new s_etat(*l_etat.at(num_etat - 1));
            mise = line.mid(line.lastIndexOf("€") + 1).toDouble();
            num_etat++;
            current->joueur_actif = num_j;
        }
        else if (line.contains(": check")){
            current = new s_etat(*l_etat.at(num_etat - 1));
            mise = 0;
            num_etat++;
            current->joueur_actif = num_j;
        }
        else if (line.contains("FLOP"))
        {
            QStringList l_flop = line.mid(line.indexOf('[') + 1, line.indexOf(']') - line.indexOf('[') - 1).split(' ');
            current = new s_etat(*l_etat.at(num_etat - 1));
            for (int i(0); i < 3; i++)
                current->flop[i] = s_card(l_flop.at(i));
            num_etat++;
            current->joueur_actif = -1;
        }
        else if (line.contains("TURN"))
        {
            current = new s_etat(*l_etat.at(num_etat - 1));
            current->turn = s_card(line.mid(line.lastIndexOf('[') + 1, line.lastIndexOf(']') - line.lastIndexOf('[') - 1));
            num_etat++;
            current->joueur_actif = -1;

        }
        else if (line.contains("RIVER"))
        {
            current = new s_etat(*l_etat.at(num_etat - 1));
            current->river = s_card(line.mid(line.lastIndexOf('[') + 1, line.lastIndexOf(']') - line.lastIndexOf('[') - 1));
            num_etat++;
            current->joueur_actif = -1;

        }
        else if (line.contains("SUMMARY"))
        {
            nb_etat = l_etat.size();
            return debut;
        }
        else {
            continue;
        }
        current->action = line;
        if (num_j >= 0)
        {
            current->mise[num_j] += mise;
            current->tapis[num_j] -= mise;
            if (current->tapis[num_j] < 0.1)
                current->tapis[num_j] = 0;
            current->pot += mise;
        }
        else {
            for (int i(0); i < 6; i++)
                current->mise[i] = 0;
        }
        l_etat.push_back(current);
    }
    return (0);
}

void    lecteur::read_etat(int index_etat)
{
    etat *e = l_etat.at(index_etat);
    ui->display->setText(e->action);
    for (int i(0); i < 6; i++)
    {
        ui->pot->setText(QString::number(e->pot));
        this->findChild<QLabel*>("BT" + QString::number(e->bouton))->setText("B");
        if (e->mise[i] >= 0.009)
            this->findChild<QLabel*>("M" + QString::number(i + 1))->setText(QString::number(e->mise[i]));
        else
            this->findChild<QLabel*>("M" + QString::number(i + 1))->setText("");
        this->findChild<QLabel*>("T" + QString::number(i + 1))->setText(QString::number(e->tapis[i]) + "€");
        if (!e->j[i])
        {
            this->findChild<QFrame*>("frame" + QString::number(i + 1))->setEnabled(false);
            hide_hand(i);
        }
        else
        {
            this->findChild<QFrame*>("frame" + QString::number(i + 1))->setEnabled(true);
            show_back_hand(i);
        }
        if (e->flop[0].str != "")
        {
            e->flop[0].affiche_card(ui->flop_1);
            e->flop[1].affiche_card(ui->flop_2);
            e->flop[2].affiche_card(ui->flop_3);
        }
        else {
            fake_hide(ui->flop_1);
            fake_hide(ui->flop_2);
            fake_hide(ui->flop_3);
        }
        if (e->turn.str != "")
        {
            e->turn.affiche_card(ui->turn);
        }
        else {
            fake_hide(ui->turn);
        }
        if (e->river.str != "")
        {
            e->river.affiche_card(ui->river);
        }
        else
            fake_hide(ui->river);
    }
    if (index_etat == nb_etat - 1)
    {
        ui->label_pot->setText("<span style=\" font-size:20pt; color:#ffffff;\">RAKE</span>");
        affiche_hands();
    }
    else
        ui->label_pot->setText("<span style=\" font-size:20pt; color:#ffffff;\">POT TOTAL</span>");
    for (int i(0); i < 6; i++)
    {
        this->findChild<QFrame*>("frame" + QString::number(i + 1))->setAutoFillBackground(true);
        this->findChild<QFrame*>("frame" + QString::number(i + 1))->setStyleSheet("");
    }
    if (e->joueur_actif >= 0)
        this->findChild<QFrame*>("frame" + QString::number(e->joueur_actif + 1))->setStyleSheet("background: rgb(164, 179, 255)");

}

void lecteur::etat_suivant()
{
    if (++current_etat < nb_etat)
    {
        read_etat(current_etat);
        ui->nb_current_etat->setText(QString::number(current_etat) + " / " + QString::number(nb_etat - 1));
    }
    else {
        --current_etat;
    }

}

void    lecteur::read_summary(QStringList l, int debut)
{
    etat *etat_final = new s_etat(*l_etat.last());

    QString line = l.at(debut);
    if (line.contains("Total pot"))
    {
        jeux.pot_final = line.mid(line.indexOf(u8"€") + 1, line.indexOf("|") - line.indexOf(u8"€") - 2).toDouble();
        jeux.rake = line.mid(line.lastIndexOf(u8"€") + 1).toDouble();
        ++debut;
    }
    for (int i(0); i < 6; ++i)
     etat_final->mise[i] = 0;
    while (debut < l.size()) {
        line = l.at(debut++);
        if (line.contains("showed"))
        {
            QString joueur = line.mid(line.indexOf(":") + 2, line.mid(line.indexOf(":") + 2).indexOf(' '));
            if (jeux.my_hand.joueur != joueur)
                jeux.other_hand.push_back(new s_hand(joueur, line.mid(line.indexOf('[') + 1, line.indexOf(']') - line.indexOf('[') - 1)));
        }
        if (line.contains("collected") || line.contains("won"))
        {
            jeux.gagnan = line.mid(line.indexOf(":") + 2, line.mid(line.indexOf(":") + 2).indexOf(' '));
            jeux.gain = line.mid(line.indexOf('(') + 2, line.indexOf(')') - line.indexOf('(') - 2).toDouble();
            etat_final->pot = jeux.rake;
            etat_final->tapis[id_joueur[jeux.gagnan].toInt() - 1] += jeux.gain;
            etat_final->mise[id_joueur[jeux.gagnan].toInt() - 1] = jeux.gain;
            etat_final->action = jeux.gagnan + " WON " + QString::number(jeux.gain) + "€";
        }
    }
    l_etat.push_back(etat_final);
}

void lecteur::etat_precedent()
{
    if (--current_etat >= 0)
    {
        read_etat(current_etat);
        ui->nb_current_etat->setText(QString::number(current_etat) + " / " + QString::number(nb_etat- 1));
    }
    else {
        ++current_etat;
    }
}

void    lecteur::affiche_my_hand()
{
    affiche_hand(jeux.my_hand);
}

void    lecteur::affiche_hand(hand h)
{
    h.c[0].affiche_card_coupe(this->findChild<QLabel*>("H" + id_joueur[h.joueur] + "_0"));
    h.c[1].affiche_card_coupe(this->findChild<QLabel*>("H" + id_joueur[h.joueur] + "_1"));
}

void    lecteur::affiche_hands()
{
    for (int i(0); i < jeux.other_hand.size(); ++i)
        affiche_hand(*jeux.other_hand.at(i));
}

void    lecteur::hide_hand(int j)
{
    this->findChild<QWidget*>("H" + QString::number(j + 1) + "_0")->hide();
    this->findChild<QWidget*>("H" + QString::number(j + 1) + "_1")->hide();
}

void    lecteur::show_back_hand(int j)
{
    if (j != id_hero)
    {
        fake_hide(this->findChild<QLabel*>("H" + QString::number(j + 1) + "_0"));
        fake_hide(this->findChild<QLabel*>("H" + QString::number(j + 1) + "_1"));
        this->findChild<QWidget*>("H" + QString::number(j + 1) + "_0")->setStyleSheet("background-image: url(:/dos carte rouge.jpeg);");
        this->findChild<QWidget*>("H" + QString::number(j + 1) + "_1")->setStyleSheet("background-image: url(:/dos carte rouge.jpeg);");
        this->findChild<QWidget*>("H" + QString::number(j + 1) + "_0")->show();
        this->findChild<QWidget*>("H" + QString::number(j + 1) + "_1")->show();
    }
}

void    lecteur::hide_card(QLabel *j)
{
    j->hide();
}

void    lecteur::show_back_card(QLabel *j)
{
    j->show();
}

struct s_jeux    lecteur::Read_summary(QString txt)
{
    struct s_jeux           jeux;
    int                     nb_joueur(0);
    int                     nb_j_bt;
    int                     nb_early;
    bool                    open(true);
    QString                 joueur;
    QString                 debug;
    QMap<QString, int>  pos_joueur;


    int i(0);
    qDebug() << txt <<" \n\n" << endl << endl;
    QStringList l = txt.split('\n');
    i = 2;
    while(l.at(i).contains("Seat"))
    {
        i++;
        nb_joueur++;
    }
    while (!l.at(i++).contains("HOLE CARDS"));
    jeux.my_hand = hand(l.at(i));
    jeux.my_hand.joueur = l.at(i).mid(l.at(i).indexOf("to ") + 3, l.at(i).indexOf('[') - (l.at(i).indexOf("to ") + 4));

    i++;
    nb_early = 11 - nb_joueur;
    open = true;
    while (l.at(i).contains(": fold")  || l.at(i).contains(": raises") ||
           l.at(i).contains(": call") || l.at(i).contains(": bets") || l.at(i).contains(": check"))
    {
        joueur = l.at(i).mid(0, l.at(i).indexOf(':'));
        pos_joueur[joueur] = nb_early;
        if (open && jeux.my_hand.joueur == joueur)
        {
            Sql::Requete(QString(R"(UPDATE MY_OPEN_RANGE SET nb_possibilite_open = nb_possibilite_open + 1
WHERE type_hand = "%1" AND id_position = %2)").arg(jeux.my_hand.type_hand()).arg(pos_joueur[joueur]));
            if (l.at(i).contains(": raises"))
                Sql::Requete(QString(R"(UPDATE MY_OPEN_RANGE SET nb_open = nb_open + 1
WHERE type_hand = "%1" AND id_position = %2)").arg(jeux.my_hand.type_hand()).arg(pos_joueur[joueur]));
        }
        if (!l.at(i).contains(": fold"))
            open = false;
        i++;
        nb_early++;
    }
    while (!l.at(i++).contains("SUMMARY"));
    QString line = l.at(i);
    if (line.contains("Total pot"))
    {
        jeux.pot_final = line.mid(line.indexOf(u8"€") + 1, line.indexOf("|") - line.indexOf(u8"€") - 2).toDouble();
        jeux.rake = line.mid(line.lastIndexOf(u8"€") + 1).toDouble();
        ++i;
    }
    while (i < l.size()) {
        line = l.at(i++);
        if (line.contains("showed"))
        {
            QString joueur = line.mid(line.indexOf(":") + 2, line.mid(line.indexOf(":") + 2).indexOf(' '));
            if (jeux.my_hand.joueur != joueur)
                jeux.other_hand.push_back(new s_hand(joueur, line.mid(line.indexOf('[') + 1, line.indexOf(']') - line.indexOf('[') - 1)));
        }
        if (line.contains("collected") || line.contains("won"))
        {
            jeux.gagnan = line.mid(line.indexOf(":") + 2, line.mid(line.indexOf(":") + 2).indexOf(' '));
            if (jeux.gagnan == jeux.my_hand.joueur)
                jeux.gain = line.mid(line.indexOf('(') + 2, line.indexOf(')') - line.indexOf('(') - 2).toDouble();
            else {
                jeux.gain = 0;
                jeux.rake = 0;
            }
        }
    }
    return jeux;
}

lecteur::~lecteur()
{
    delete ui;
}

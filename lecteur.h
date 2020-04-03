#ifndef LECTEUR_H
#define LECTEUR_H

#include <QWidget>
#include <QMap>
#include <QLabel>
#include <QDebug>
#include "util.h"


namespace Ui {
class lecteur;
}

typedef struct s_etat{
    QString     action;
    int         bouton;
    int         joueur_actif;
    bool        j[6];
    double      tapis[6];
    double      mise[6];
    double      pot;
    card        flop[3];
    card        turn;
    card        river;
    s_etat(){
        for (int i(0); i < 6; i++)
            j[i] = false;
        joueur_actif = -1;
    }
}etat;

typedef struct s_action{
    QString     joueur;
    enum        a{fold = -1, check = 0, bet, raise};
    double      mise;
}action;

typedef struct s_jeux{
    double          prix;
    hand            my_hand = s_hand();
    QList<hand*>    other_hand;
    double          pot_final;
    double          rake;
    QString         gagnan;
    double          gain;
    s_jeux()
    {

    }
}jeux;

class lecteur : public QWidget
{
    Q_OBJECT

private:
    jeux                    jeux;
    int                     id_hero;
    QList<etat*>            l_etat;
    int                     nb_etat;
    QMap<QString, QString>  id_joueur;
    int                     current_etat;

public:
    explicit lecteur(QWidget *parent = nullptr);
    int     init_table(QStringList ligne);
    void    read_jeux(QString text = nullptr);
    void    read_summary(QStringList l, int debut);
    int     calcul_etat(QStringList l, int debut);
    void    read_etat(int index_etat);
    void    init_game();
    void    affiche_my_hand();
    void    affiche_hand(hand hand);
    void    affiche_hands();
    void    hide_card(QLabel *j);
    void    show_back_card(QLabel *j);
    void    hide_hand(int i);
    void    show_back_hand(int i);
    void    generate_etat(QString text = nullptr);
    static struct s_jeux    Read_summary(QString txt);
    ~lecteur();
public slots:
    void    etat_suivant();
    void    etat_precedent();

private:
    Ui::lecteur *ui;
};

#endif // LECTEUR_H

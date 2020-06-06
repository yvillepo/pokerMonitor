#ifndef READER_H
#define READER_H

#include <QObject>
#include <QDebug>
#include "util.h"

typedef enum type3E {
    NA = 0,
    VRAI=1,
    FAUX = -1,
} t_3E;

//typedef enum position {
//    BT = 6,
//    SB = 1,
//    BB = 2,
//    cut_of = 3,
//    MP = 4,
//    UTG = 5,
//    UTG1,
//    UTG2,
//    UTG3,
//    UTG4,
//    UTG5,
//    UTG6,
//    Nein = -1,
//} e_position;

typedef  enum a_name_bien_un_de_ses_Quatre {
    fold,
    check,
    call,
    tmp_raise,
}e_action;

typedef struct player_chips {
    QMap<QString, int> p();
}s_player_chips;

typedef struct prefflop{

    hand my_hand;
    t_3E open = NA;
    t_3E bet3 = NA;
    t_3E bet4 = NA;

} s_preflop;

typedef struct poistflop{

} s_postflop;

class reader
{
private:
    QString                     str_game;
    e_position            my_position;
    s_preflop                   preflop;
    int                         index;
    QStringList                 l_str_part;
    QMap<QString, e_position>   player_postion();
    QMap<QString, double>       player_chips();


public:
    reader(QString str);
    void        read_preflop();
    void        init_game();
};

#endif // READER_H

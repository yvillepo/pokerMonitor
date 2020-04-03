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

typedef enum position {
    BT = 6,
    SB = 1,
    BB = 2,
    cut_of = 3,
    MP = 4,
    UTG = 5,
    Nein = 0,
} e_position_6max;

typedef  enum a_name_bien_un_de_ses_Quatre {
    fold,
    check,
    call,
    raise,
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
    e_position_6max             my_position;
    s_preflop                   preflop;
    int                         index;
    QStringList                 l_str_part;
    QMap<QString, e_position_6max>   player_postion();
    QMap<QString, double>       player_chips();


public:
    reader(QString str);
    void        read_preflop();
    void        init_game();
};

#endif // READER_H

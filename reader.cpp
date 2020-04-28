 #include "reader.h"


reader::reader(QString str)
{
    str_game = str;
    l_str_part = str.split('\n');
    init_game();
    read_preflop();

}

inline e_action read_action(QString str)
{
    e_action    action = call;
    QString     str_action;

    int index_debut_action = str.indexOf(':') + 2;
    str_action = str.mid(index_debut_action);
    str_action = str_action.mid(0, str_action.indexOf(' '));
    qDebug() << str_action << endl;
    return action;
}
void reader::read_preflop()
{
    bool est_open = false;
    e_position pos = SB;
    QString line = l_str_part.at(index++);
    QMap<e_position, QString> action;
    preflop.my_hand = hand(line);
    qDebug() << preflop.my_hand.joueur << "  " << preflop.my_hand.type_hand();
    do {
        line = l_str_part.at(index++);
        read_action(line);
    }while (line[0] != '*');
}

void    reader::init_game()
{
    index = 0;
    while (l_str_part.at(index++) != "*** HOLE CARDS ***");
}

#include "mainwindow.h"
#include "hand_view.h"
#include "range_view.h"
#include "SQL.h"
#include "lecteur.h"
#include "test.h"
#include <QApplication>
#include "read_history.h"
#include <QWidget>
#include "range.h"
#include "reader.h"
#include "util.h"
#include <QPixmap>
#include <QScreen>
#include <QWidget>
#include "screen.h"
#include "scan_hand.h"
#include <QGraphicsView>
#include "rangeview.h"
#include "handviewwidget.h"
#include "rangeviewwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Sql     sql("/Users/yann/dbpoker/testpoker.db");
   // read_history("/Users/yann/Library/Application Support/PokerStarsFR/HandHistory/Luckers712/", &sql);
   // reader r(str_liste_hands("/Users/yann/dbpoker/hand_hystory_example_pokerstars.txt").at(0));
    MainWindow w;
    w.show();
    a.exec();
}

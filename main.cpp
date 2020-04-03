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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Sql     sql("/Users/yann/dbpoker/testpoker.db");
    //read_history("/Users/yann/Library/Application Support/PokerStarsFR/HandHistory/Luckers712/", &sql);
    reader r(str_liste_hands("/Users/yann/dbpoker/hand_hystory_example_pokerstars.txt").at(0));
    QScreen qscreen(QPlatformScreen);
    QPixmap originalPixmap = qscreen.grabWindow( QWidget::winId() ,QApplication::desktop()->winId(),00,00,1440,900);
    QLabel lscreen;
    lscreen.setPixmap(originalPixmap);
    lscreen.show();

//    MainWindow w;
//    w.show();
    a.exec();
}

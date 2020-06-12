#ifndef DIAGREADBET_H
#define DIAGREADBET_H

#include <QWidget>
#include "imagereader.h"

namespace Ui {
class diagReadBet;
}

class DiagReadBet : public QWidget
{
    Q_OBJECT

public:
    DiagReadBet(ImageReader *imR, QWidget *parent = nullptr);
    ~DiagReadBet();

public slots:
    void updateLabel();
private slots:
    void on_btStartStrop_clicked();

    void on_btTakeScreen_clicked();

private:
    Ui::diagReadBet *ui;
    ImageReader *imRead;
    ImOption    *imOpt;
    bool        run;
    int         nbScreen;
    bool        deleteImRead;

};

#endif // DIAGREADBET_H

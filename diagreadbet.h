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
    explicit DiagReadBet(QWidget *parent = nullptr);
    ~DiagReadBet();

public slots:
    void updateLabel();
private slots:
    void on_btStartStrop_clicked();

private:
    Ui::diagReadBet *ui;
    ImageReader *imRead;
    bool        run;

};

#endif // DIAGREADBET_H

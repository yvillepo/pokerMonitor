#ifndef DIAGNOSTICSCANNER_H
#define DIAGNOSTICSCANNER_H

#include "imagereader.h"
#include <QObject>
#include <QWidget>

class    DiagnosticScanner : public QWidget
{
    Q_OBJECT
private:
    ImageReader                 *imRead;
    QTimer                      *refrechTimer;
    bool                        diagnostic;
    bool                        boolShowPixPox;
    int                         nbHandRead;
    QGridLayout                 *mainBoxLayout;
    QLineEdit                   *refreshRateEdit;
    QPushButton                 *BtLancerTest;
    QLabel                      *newValueLabel;
    QVector<QLabel*>            labImC1;
    QVector<QLabel*>            labImC2;
    QVector<QLabel*>            labStrCart;
    QMap<e_position, QLabel*>   labPos;
    QMap<e_position, QLabel*>   labPixPos;
    QPushButton                 *btShowPixPox;
    Hand                        lastHand;
    e_position                  lastPosition;
    int                         nbRead;
    QLabel                      *labLastHand;
    QLabel                      *labNbRead;
public:
    DiagnosticScanner(ImageReader *im,QWidget *parent = nullptr, Qt::WindowFlags f = 0);
    ~DiagnosticScanner();
public slots:
    void    startDiagnostic();
    void    stopDiagnostic();
    void    toogleDiagnostic();
    void    newHand();
    void    updateLastHand(Hand newHand, e_position newPosition);
    void    toogleShowPixPos();
private:
    void    updateHand(Hand newHand);
    void    updatePosition();
    void    updatePixPox();
signals:
    void    deleteSignal();
};
#endif // DIAGNOSTICSCANNER_H

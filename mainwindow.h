#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ImRead/imagereader.h"
#include "ImRead/diagnosticscanner.h"
#include <QStackedWidget>
#include "myopenrange.h"
#include "preflophelperwidget.h"
#include "imagereader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow      *ui;
    DiagnosticScanner   *diag;
    QWidget             *wOpenRange;
    PreflopHelperWidget *preflopHelper;
    myOpenRange         *openRange;
    ImageReader        *imRead;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *Get_ui() {return ui;}
    ~MainWindow();
    void closeEvent(QCloseEvent*event);
private slots:
    void on_actionrange_triggered();
    void lancerDiagnosticReader();
    void diagScrandeleted();
    void afficheOpenRange();
    void rangeWhilePlaying();
    void on_actionDiag_Bet_triggered();
};

#endif // MAINWINDOW_H

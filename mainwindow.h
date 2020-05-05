#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *Get_ui() {return ui;}
    ~MainWindow();
    void closeEvent(QCloseEvent*event);
private slots:
    void on_actionrange_triggered();
    void lancerDiagnosticReader();
    void diagScrandeleted();
};

#endif // MAINWINDOW_H

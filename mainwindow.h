#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *Get_ui() {return ui;}
    ~MainWindow();
private slots:
    void on_actionrange_triggered();
};

#endif // MAINWINDOW_H

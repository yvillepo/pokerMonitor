#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "range_view.h"
#include <QString>
#include <QtWidgets>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    diag(nullptr)
{
    ui->setupUi(this);
    connect(ui->actionDiagnostic, &QAction::triggered,
            this, &MainWindow::lancerDiagnosticReader);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionrange_triggered()
{
    qDebug() << "action trigered" << endl;
}

void MainWindow::lancerDiagnosticReader()
{
    if (!diag)
    {
        diag = new DiagnosticScanner(this, Qt::Window);
        diag->setAttribute(Qt::WA_DeleteOnClose);
        connect(diag, SIGNAL(deleteSignal()), this, SLOT(diagScrandeleted()));
    }
    diag->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (diag != nullptr)
        diag->close();
    QWidget::closeEvent(event);
}

void MainWindow::diagScrandeleted()
{
    diag = nullptr;
}

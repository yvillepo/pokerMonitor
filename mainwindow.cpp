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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionrange_triggered()
{

}

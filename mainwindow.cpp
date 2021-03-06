#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "range_view.h"
#include "rangeviewwidget.h"
#include "ImRead/diagreadbet.h"
#include <QString>
#include <QWidget>
#include <string>
#include <iostream>
#include <fstream>
#include "treerangesmodel.h"
#include <QTreeView>
#include <QComboBox>
#include <QDockWidget>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    diag(nullptr),
    wOpenRange(nullptr),
    preflopHelper(nullptr),
    imRead(new ImageReader())
{
    ui->setupUi(this);
    connect(ui->actionDiagnostic, &QAction::triggered,
            this, &MainWindow::lancerDiagnosticReader);
    connect(ui->actionopenRange, &QAction::triggered,
            this, &MainWindow::afficheOpenRange);
    connect(ui->actionrange_2, &QAction::triggered,
            this, &MainWindow::rangeWhilePlaying);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionrange_triggered()
{
    qDebug() << "action trigered" ;
}

void MainWindow::lancerDiagnosticReader()
{
     diag = new DiagnosticScanner(imRead, this);
     diag->setAttribute(Qt::WA_DeleteOnClose);
     diag->setWindowFlag(Qt::Window);
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

void MainWindow::afficheOpenRange()
{
    openRange = new myOpenRange(":/open.txt");
    QStackedWidget *stackRange = new QStackedWidget(this);
    QComboBox *openComboBox = new QComboBox(this);
    Range   *current;
    for (int i = 1; i < 6; i++)
    {
        current = openRange->getRange(static_cast<e_position>(i));
        openComboBox->addItem(stringPos(static_cast<e_position>(i)));
        stackRange->addWidget(new RangeViewWidget(*current, stackRange));
    }
    connect(openComboBox, QOverload<int>::of(&QComboBox::activated),
                  stackRange, &QStackedWidget::setCurrentIndex);

    wOpenRange = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout(wOpenRange);
    vbox->addWidget(openComboBox);
    vbox->addWidget(stackRange);
    wOpenRange->setLayout(vbox);
    setCentralWidget(wOpenRange);
    wOpenRange->show();


    QDockWidget *dcWidget = new QDockWidget(this);

    TreeRangesModel *tree = new TreeRangesModel();
    QTreeView *treeView = new QTreeView();
    treeView->setModel(tree);
    dcWidget->setWidget(treeView);
    addDockWidget(Qt::LeftDockWidgetArea ,dcWidget, Qt::Horizontal);
}

void MainWindow::rangeWhilePlaying()
{
    preflopHelper = new PreflopHelperWidget();
    setCentralWidget(preflopHelper);
}

void MainWindow::on_actionDiag_Bet_triggered()
{
    DiagReadBet *diag = new DiagReadBet(imRead, this);
    diag->show();
}

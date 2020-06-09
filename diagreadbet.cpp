#include "diagreadbet.h"
#include "ui_diagreadbet.h"

DiagReadBet::DiagReadBet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diagReadBet),
    imRead(new ImageReader()),
    run(false)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::Window);
    this->setAttribute(Qt::WA_DeleteOnClose);
    imOpt = new ImOption();
    ImOptionModel *optMod = new ImOptionModel(imOpt, this);
    ui->tableView->setModel(optMod);
    connect(imRead, &ImageReader::refresh, this, &DiagReadBet::updateLabel);
}

DiagReadBet::~DiagReadBet()
{
    delete ui;
    delete imRead;
}

void DiagReadBet::updateLabel()
{
    ui->scanImage->setPixmap(imRead->pixEcran.scaled(ui->scanImage->size(),
                             Qt::KeepAspectRatio,
                             Qt::SmoothTransformation));
//    ui->imBetUtg->setPixmap(QPixmap::fromImage(imRead->imBet[UTG]));
//    ui->imBetMp->setPixmap(QPixmap::fromImage(imRead->imBet[MP]));
//    ui->imBetCo->setPixmap(QPixmap::fromImage(imRead->imBet[CO]));
//    ui->imBetBt->setPixmap(QPixmap::fromImage(imRead->imBet[BT]));
//    ui->imBetSb->setPixmap(QPixmap::fromImage(imRead->imBet[SB]));
//    ui->imBetBb->setPixmap(QPixmap::fromImage(imRead->imBet[BB]));
}

void DiagReadBet::on_btStartStrop_clicked()
{
    if (run)
    {
        ui->btStartStrop->setText("Start Reader");
        imRead->stop();
    }
    else
    {
        ui->btStartStrop->setText("Stop Reader");
        imRead->start();
    }
}

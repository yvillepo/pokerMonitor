#include "diagreadbet.h"
#include "ui_diagreadbet.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>

DiagReadBet::DiagReadBet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diagReadBet),
    imRead(new ImageReader()),
    run(false),
    nbScreen(0)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::Window);
    this->setAttribute(Qt::WA_DeleteOnClose);
    imOpt = new ImOption();
    ImOptionModel *optMod = new ImOptionModel(imOpt, this);
    ui->tableView->setModel(optMod);
    connect(imRead, &ImageReader::refresh, this, &DiagReadBet::updateLabel);
    updateLabel();
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
    QImage stack = imRead->scan(imRead->option.betRect.at(0));
    ui->v1->setPixmap(QPixmap::fromImage(stack.copy(18, 13, 6, 3)).scaled(ui->v1->size()));
    ui->v2->setPixmap(QPixmap::fromImage(stack.copy(24, 13, 6, 3)).scaled(ui->v1->size()));
    ui->v3->setPixmap(QPixmap::fromImage(stack.copy(30, 13, 6, 3)).scaled(ui->v1->size()));
    ui->imBetSb->setPixmap(QPixmap(":/virgule.png").scaled(ui->v1->size()));
    ui->stack1->setPixmap(QPixmap::fromImage(imRead->scan(imRead->option.betRect.at(0))));
}

void DiagReadBet::on_btStartStrop_clicked()
{
    if (run)
    {
        ui->btStartStrop->setText("Start Reader");
        imRead->stop();
        run = false;
    }
    else
    {
        ui->btStartStrop->setText("Stop Reader");
        imRead->start();
        run = true;
    }
}

void DiagReadBet::on_btTakeScreen_clicked()
{
    const QString format = "png";

    QString initialPath = "/Users/yann/dbpoker/Screen";
    const QString fileName = initialPath + "/" + QDateTime::currentDateTime().toString();
    if (!imRead->pixEcran.save(fileName + ".png")) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName + ".png")));
    }
    else
    {
        nbScreen++;
        ui->btTakeScreen->setText(QString("Take screen (%1)").arg(nbScreen));
//        ui->btTakeScreen->update();
//        ui->btTakeScreen->updateGeometry();
//        update();
//        updateGeometry();
    }
//    QPixmap virgule1 = imRead->pixEcran.copy(627, 667, 6, 3);
//    QPixmap virgule2 = imRead->pixEcran.copy(633, 667, 6, 3);
//    QPixmap virgule3 = imRead->pixEcran.copy(639, 667, 6, 3);
//    virgule1.save(fileName + "_v1" + ".png");
//    virgule2.save(fileName + "_v2" + ".png");
//    virgule3.save(fileName + "_v3" + ".png");
}

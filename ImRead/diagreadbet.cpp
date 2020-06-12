#include "diagreadbet.h"
#include "ui_diagreadbet.h"
#include "imoptionmodel.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsPixmapItem>

DiagReadBet::DiagReadBet(ImageReader *imR, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diagReadBet),
    imRead(imR),
    run(false),
    nbScreen(0),
    deleteImRead(false)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::Window);
    this->setAttribute(Qt::WA_DeleteOnClose);
    imOpt = imRead->option;
    ImOptionModel *optMod = new ImOptionModel(imRead, this);
    imRead->option->setScreenRect(QRect(-1920,0,960,690));
    ui->tableView->setModel(optMod);
    connect(imRead, &ImageReader::refresh, this, &DiagReadBet::updateLabel);
    updateLabel();
}

DiagReadBet::~DiagReadBet()
{
    delete ui;
    if (deleteImRead)
        delete imRead;
}

void DiagReadBet::updateLabel()
{
    drawScreenPixmap();
    ui->scanImage->setPixmap(screenEdit.scaled(ui->scanImage->size(),
                             Qt::KeepAspectRatio,
                             Qt::SmoothTransformation));
    QImage stack = imRead->scan(*(imRead->option->betRect.at(0)));
    ui->v1->setPixmap(QPixmap::fromImage(imRead->card1).scaled(ui->v1->size()));
    ui->v2->setPixmap(QPixmap::fromImage(stack.copy(24, 13, 6, 3)).scaled(ui->v1->size()));
    ui->v3->setPixmap(QPixmap::fromImage(imRead->card2).scaled(ui->v1->size()));
    ui->imBetSb->setPixmap(QPixmap(":/virgule.png").scaled(ui->v1->size()));
    ui->stack1->setPixmap(QPixmap::fromImage(imRead->scan(*(imRead->option->betRect.at(0)))));
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

    QString initialPath = "C:/Users/Megaport/Desktop/dbPoker/Screen";
    const QString fileName = initialPath +"/" + QString::number(imOpt->getScreenRect().width()) + "_" +
            QString::number(imOpt->getScreenRect().height()) + "_" + QString::number(nbScreen);
    if (!screenEdit.save(fileName + ".png")) {
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

void DiagReadBet::drawScreenPixmap()
{
    QGraphicsScene *scene = new QGraphicsScene();

    QPixmap *pix = &imRead->pixEcran;
  //  scene->setSceneRect(pix->rect());
    scene->addPixmap(*pix);
    scene->addRect(QRectF(imOpt->card1Rect));
    scene->addRect(QRectF(imOpt->card2Rect));

    screenEdit = QPixmap(pix->width(), pix->height());
    QPainter pt(&screenEdit);
    scene->render(&pt);
    delete scene;
}

//void Widget::on_createFondEcran_clicked()
//{
//    on_resize_clicked();
//    QGraphicsScene *scene = new QGraphicsScene();

//    scene->setSceneRect(QRectF(0, 0, 3840, 2160));
//    QPixmap pix2 = pix.copy();
//    QGraphicsPixmapItem * pixitm;
//    for (int i = 0; i < 6; i++)
//    {
//         pixitm = scene->addPixmap(pix2);
//         pixitm->setOffset(QPointF(i % 3 * 1280, (i / 3 * 1080)));
//    }
//    pix = QPixmap(3840, 2160);
//    QPainter pt(&pix);
//    scene->render(&pt);
//    delete scene;
//    updatePixLabel();
//}

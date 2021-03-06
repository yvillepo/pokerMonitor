#include "enregistreur.h"
#include <QDir>
#include <QMessageBox>

/**********tmp***********/
#include <QDebug>
/************************/


/***************Enr1**********************/

Enr1::Enr1(QImage image, QWidget *parent) : QWidget(parent)
{
    im = image;
    layout = new QVBoxLayout(this);
    imLabel = new QLabel(this);
    nameEdit = new QLineEdit(this);
    imLabel->setPixmap(QPixmap::fromImage(im));
    layout->addWidget(imLabel);
    layout->addWidget(nameEdit);
    nameEdit->setText("x");
    setLayout(layout);
}

void Enr1::enregistre()
{
    const QString format = "png";
    QString initialPath = "/Users/yann/dbpoker/img/card/";
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += nameEdit->text() + "." + format;
    if (!im.save(initialPath)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(initialPath)));
    }
}

/*******************************************/

void Enregistreurs::enregistrer()
{
    for (int i = 0; i < enregistreurList.size(); i++)
    {
        enregistreurList.at(i)->enregistre();
        delete enregistreurList.at(i);
    }
}

Enregistreurs::Enregistreurs(QWidget *parent) :
    QWidget(parent),
    nbImage(0),
    mainLayout(new QHBoxLayout(this)),
    imageLayout(new QGridLayout(/*this*/)),
    nbImageLbel(new QLabel("nb image : "/*, this*/)),
    saveButton(new QPushButton("enregistrer tout", this)),
  /*********tmp*********/
    read(new ImageReader())
{
    QHBoxLayout *head_layout = new QHBoxLayout(/*this*/);
    head_layout->addWidget(nbImageLbel);
    head_layout->addWidget(saveButton);
    mainLayout->addLayout(imageLayout);
    mainLayout->addWidget(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(enregistrer()));
    setLayout(mainLayout);
}

void Enregistreurs::addEnr1(QImage im)
{
    if (exist(im))
        return ;
    Enr1 *e = new Enr1(im, this);
    lImage.push_back(im);
    enregistreurList.push_back(e);
    imageLayout->addWidget(e, nbImage / 8, nbImage % 8);
    nbImage++;
    nbImageLbel->setText("nb image : " + QString::number(nbImage));
}

void Enregistreurs::addHAnd(QImage c1, QImage c2)
{
    addEnr1(c1);
    addEnr1(c2);
}

bool    Enregistreurs::exist(QImage im)
{
    for (QList<QImage>::const_iterator it = lImage.cbegin(); it != lImage.cend(); it++)
        if(*it == im)
            return true;
    return false;
}

void    Enregistreurs::deleteEnregistreur()
{
    while (!enregistreurList.isEmpty())
        delete enregistreurList.takeFirst();
}

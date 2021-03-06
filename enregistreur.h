#ifndef ENREGISTREUR_H
#define ENREGISTREUR_H

#include <QPixmap>
#include <QWidget>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

/**********tmp***********/
#include "ImRead/imagereader.h"
/************************/



class Enr1 : public QWidget //Affiche une image avec un label pour la sauvegarder
{
    Q_OBJECT
public:
    Enr1(QImage image, QWidget *parent = nullptr);
    void    enregistre();
    QImage getIm(){return im;}
private:
    QVBoxLayout *layout;
    QLabel      *imLabel;
    QLineEdit   *nameEdit;

    QImage  im;
};

class Enregistreurs : public QWidget //Affiche toutes les image ajouté
{
    Q_OBJECT
private:
    int nbImage;
    QImage lastScreen1;
    QImage lastScreen2;
    QImage lastlastScreen1;
    QImage lastlastScreen2;
    QList<QImage> lImage;
    QList<Enr1 *> enregistreurList;
    QHBoxLayout *mainLayout;
    QGridLayout *imageLayout;
    QLabel      *nbImageLbel;
    QPushButton *saveButton;
    /******** temporaire pour test **************/
    ImageReader *read;
    /********************************************/
public:
    Enregistreurs(QWidget *parent = nullptr);
    void addHAnd(QImage c1, QImage c2);
    void addEnr1(QImage im);
    bool exist(QImage im);
    void deleteEnregistreur();
public slots:
     void enregistrer();
};

#endif // ENREGISTREUR_H

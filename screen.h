#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QPixmap>
#include <QWidget>
#include <QLineEdit>
#include <QScrollArea>
#include "scan_hand.h"
#include "enregistreur.h"

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
QT_END_NAMESPACE

//! [0]
class Screenshot : public QWidget
{
    Q_OBJECT

public:
    Screenshot();
    void lancerEnregistrement();
    QPixmap scan(int x, int y, int width, int height);
    QTimer  *timer;
    int nb_image;


protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void newScreenshot();
    void saveScreenshot();
    void shootScreen();
    void updateCheckBox();
    void screenAndSave();

private:
    Enregistreurs   *e;
    void updateScreenshotLabel();
    void uptdatePosCursor(QMouseEvent *ev);
    QPixmap originalPixmap;
    QPixmap cardPixmap1;
    QPixmap cardPixmap2;
    QImage  lastCardImage1;
    QImage  lastCardImage2;

    QLabel *screenshotLabel;
    QLabel *cardLabel1;
    QLabel *cardLabel2;
    QLabel *nbScreenLabel;
    QLabel *mouseX;
    QLabel *mouseY;
    QLabel  *nbHandLabel;
    QSpinBox *delaySpinBox;
    QSpinBox *posX;
    QSpinBox *posY;
    QSpinBox *sizeX;
    QSpinBox *sizeY;
    QLineEdit *edtName;
    QLineEdit *nameHandLineEdit;
    QCheckBox *hideThisWindowCheckBox;
    QPushButton *newScreenshotButton;
    QPushButton *SCreenAndSave;
};
//! [0]

#endif // SCREENSHOT_H

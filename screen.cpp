#include <QtWidgets>

#include "screen.h"
#include "util.h"
#include <QDebug>

#define POSX 198
#define POSY 23
#define SIZEX 1242
#define SIZEY 877

//! [0]

void Screenshot::lancerEnregistrement()
{
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &Screenshot::shootScreen);
    /***********************$tmp***********************/
    e->show();
    /***************************************************/
}


Screenshot::Screenshot()
    : screenshotLabel (new QLabel(this)), nbScreenLabel(new QLabel(this)),
      edtName(new QLineEdit("untilted", this)),
      cardLabel1(new QLabel(this)), cardLabel2(new QLabel(this)),
      nameHandLineEdit(new QLineEdit(this)),
      nb_image(0), nbHandLabel(new QLabel("nb hand : ", this)),
      e(new Enregistreurs()), timer(new QTimer(this))
{
    nameHandLineEdit->setPlaceholderText("TcKh");
    screenshotLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenshotLabel->setAlignment(Qt::AlignCenter);

    const QRect screenGeometry = screen()->geometry();
    screenshotLabel->setMinimumSize(screenGeometry.width() / 8, screenGeometry.height() / 8);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(/*this*/);

    QGroupBox *optionsGroupBox = new QGroupBox(tr("Options"), this);
    delaySpinBox = new QSpinBox(optionsGroupBox);
    delaySpinBox->setSuffix(tr(" s"));
    delaySpinBox->setMaximum(60);

    connect(delaySpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &Screenshot::updateCheckBox);

    hideThisWindowCheckBox = new QCheckBox(tr("Hide This Window"), optionsGroupBox);

    QGridLayout *optionsGroupBoxLayout = new QGridLayout(optionsGroupBox);
    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screenshot Delay:"), this), 0, 0);
    optionsGroupBoxLayout->addWidget(delaySpinBox, 0, 1);
    optionsGroupBoxLayout->addWidget(hideThisWindowCheckBox, 1, 0, 1, 2);
    optionsGroupBoxLayout->addWidget(edtName, 3, 0, 1, 4);
    optionsGroupBoxLayout->addWidget(new QLabel ("position curseur", this), 4, 0, 1, 2);

    leftLayout->addWidget(optionsGroupBox);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;

    SCreenAndSave = new QPushButton(tr("Screen&Save"));
    connect(SCreenAndSave, &QPushButton::clicked, this, &Screenshot::screenAndSave);
    newScreenshotButton = new QPushButton(tr("lancer enregistrement"), this);
    connect(newScreenshotButton, &QPushButton::clicked, this, &Screenshot::lancerEnregistrement);
    buttonsLayout->addWidget(newScreenshotButton);
    QPushButton *saveScreenshotButton = new QPushButton(tr("Save Screenshot"), this);
    connect(saveScreenshotButton, &QPushButton::clicked, this, &Screenshot::saveScreenshot);
    buttonsLayout->addWidget(saveScreenshotButton);
    QPushButton *quitScreenshotButton = new QPushButton(tr("Quit"), this);
    quitScreenshotButton->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
    buttonsLayout->addWidget(SCreenAndSave);
    buttonsLayout->addWidget(quitScreenshotButton);
    buttonsLayout->addStretch();

    optionsGroupBoxLayout->addWidget(cardLabel1, 5, 0);
    optionsGroupBoxLayout->addWidget(cardLabel2, 5, 1);
    optionsGroupBoxLayout->addWidget(nameHandLineEdit, 5, 2);
    optionsGroupBoxLayout->addWidget(nbHandLabel, 5, 3);

    leftLayout->addWidget(optionsGroupBox);
    leftLayout->addLayout(buttonsLayout);

    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(screenshotLabel);
    shootScreen();
    delaySpinBox->setValue(5);

    setWindowTitle(tr("Screenshot"));
    resize(300, 200);
}
//! [0]

//! [1]
void Screenshot::resizeEvent(QResizeEvent * /* event */)
{
    QSize scaledSize = originalPixmap.size();
    scaledSize.scale(screenshotLabel->size(), Qt::KeepAspectRatio);
    if (!screenshotLabel->pixmap() || scaledSize != screenshotLabel->pixmap()->size())
        updateScreenshotLabel();
}
//! [1]

//! [2]
void Screenshot::newScreenshot()
{
    if (hideThisWindowCheckBox->isChecked())
        hide();
    newScreenshotButton->setDisabled(true);

    QTimer::singleShot(delaySpinBox->value() * 1000, this, &Screenshot::shootScreen);
}
//! [2]

//! [3]
void Screenshot::saveScreenshot()
{
    const QString format = "png";
    QString initialPath = "/Users/yann/dbpoker/img/";
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += edtName->text() + "." + format;
    if (!originalPixmap.save(initialPath)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(initialPath)));
    }
}
//! [3]

//! [4]
void Screenshot::shootScreen()
{
        QScreen *screen = QGuiApplication::primaryScreen();

        originalPixmap = screen->grabWindow(0, POSX, POSY, SIZEX, SIZEY);
        cardPixmap1 = originalPixmap.copy(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2);
        cardPixmap2 = originalPixmap.copy(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    QImage curentCard1 = scan(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    QImage curentCard2 = scan(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    if ((curentCard1 != lastCardImage1 || curentCard2 != lastCardImage2))
    {
        lastCardImage1 = curentCard1;
        lastCardImage2 = curentCard2;
        timer->stop();
        QTimer::singleShot(150, this, &Screenshot::readImageFixe);
    }
        updateScreenshotLabel();

//    newScreenshotButton->setDisabled(false);
//    if (hideThisWindowCheckBox->isChecked())
//        show();
    imRead.refrechEcran();
    /*****************************tmp pour test************************/
           // qDebug() << "hand : " << imRead.readHand().getStrHand() << endl;
     nbHandLabel->setText(stringPos(imRead.readPosition()) + " : " + imRead.readHand().getStrHand());
    /******************************************************************/
}

void Screenshot::readImageFixe()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    originalPixmap = screen->grabWindow(0, POSX, POSY, SIZEX, SIZEY);
    QImage utg = scan(676, 230, 1, 1);
    QImage mp = scan(394, 236, 1, 1);
    QImage co = scan(258, 416, 1, 1);
    QImage bt = scan(504, 549, 1, 1);
    QImage sb = scan(917, 504, 1, 1);
    QImage bb = scan(978, 300, 1, 1);
    qDebug() << "utg : " << utg.pixel(0,0) << endl;
    qDebug() << "mp : " << mp.pixel(0,0) << endl;
    qDebug() << "bt : " << co.pixel(0,0) << endl;
    qDebug() << "st : " << bt.pixel(0,0) << endl;
    qDebug() << "sb : " << sb.pixel(0,0) << endl;
    qDebug() << "bb : " << bb.pixel(0,0) << endl;
    QImage newCard1 = scan(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    QImage newCard2  = scan(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2);

    if ((newCard1 == lastCardImage1 && newCard2 == lastCardImage2))
    {
        if (!imRead.exist(newCard1))
            e->addEnr1(newCard1);
        if (!imRead.exist(newCard2))
            e->addEnr1(newCard2);
    }
    timer->start();
}

QImage Screenshot::scan(int x, int y, int width, int height)
{
    QPixmap p = originalPixmap.copy(x, y, width, height);
    return p.toImage();
}
//! [4]

//! [6]
void Screenshot::updateCheckBox()
{
    if (delaySpinBox->value() == 0) {
        hideThisWindowCheckBox->setDisabled(true);
        hideThisWindowCheckBox->setChecked(false);
    } else {
        hideThisWindowCheckBox->setDisabled(false);
    }
}
//! [6]


//! [10]
void Screenshot::updateScreenshotLabel()
{
    screenshotLabel->setPixmap(originalPixmap.scaled(screenshotLabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
    cardLabel1->setPixmap(cardPixmap1.scaled(cardLabel1->size(),
                                                Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
    cardLabel2->setPixmap(cardPixmap2.scaled(cardLabel2->size(),
                                                Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
    nbHandLabel->setText("nb hand vue : " + QString::number(nb_image));
}

void Screenshot::screenAndSave()
{
    shootScreen();
    saveScreenshot();
}

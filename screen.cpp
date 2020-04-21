#include <QtWidgets>

#include "screen.h"
#include <QDebug>

//! [0]

void Screenshot::lancerEnregistrement()
{
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &Screenshot::shootScreen);
    e->show();
}


Screenshot::Screenshot()
    : screenshotLabel (new QLabel(this)), nbScreenLabel(new QLabel(this)),
      mouseX(new QLabel(this)), mouseY(new QLabel(this)),
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
    QVBoxLayout *leftLayout = new QVBoxLayout(this);

    QGroupBox *optionsGroupBox = new QGroupBox(tr("Options"), this);
    delaySpinBox = new QSpinBox(optionsGroupBox);
    delaySpinBox->setSuffix(tr(" s"));
    delaySpinBox->setMaximum(60);
    posX = new QSpinBox(this);
    posY = new QSpinBox(this);
    sizeX = new QSpinBox(this);
    sizeY = new QSpinBox(this);
    posX->setMaximum(6000);
    posY->setMaximum(6000);
    sizeX->setMaximum(6000);
    sizeY->setMaximum(6000);
    posX->setValue(198);
    posY->setValue(23);
    sizeX->setValue(1242);
    sizeY->setValue(877);

    connect(delaySpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &Screenshot::updateCheckBox);

    hideThisWindowCheckBox = new QCheckBox(tr("Hide This Window"), optionsGroupBox);

    QGridLayout *optionsGroupBoxLayout = new QGridLayout(optionsGroupBox);
    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screenshot Delay:"), this), 0, 0);
    optionsGroupBoxLayout->addWidget(delaySpinBox, 0, 1);
    optionsGroupBoxLayout->addWidget(hideThisWindowCheckBox, 1, 0, 1, 2);
    optionsGroupBoxLayout->addWidget(posX, 2, 0, 1, 1);
    optionsGroupBoxLayout->addWidget(posY, 2, 1, 1, 1);
    optionsGroupBoxLayout->addWidget(sizeX, 2, 2, 1, 1);
    optionsGroupBoxLayout->addWidget(sizeY, 2, 3, 1, 1);
    optionsGroupBoxLayout->addWidget(edtName, 3, 0, 1, 4);
    optionsGroupBoxLayout->addWidget(new QLabel ("position curseur", this), 4, 0, 1, 2);
    optionsGroupBoxLayout->addWidget(mouseX, 4, 2);
    optionsGroupBoxLayout->addWidget(mouseY, 4, 3);

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
//    if (const QWindow *window = windowHandle())
//        screen = window->screen();
//    if (!screen)
//        return;


    int intPosX = posX->value();
    int intPosY = posY->value();
    int intSizeX = sizeX->value();
    int intSizeY = sizeY->value();
    originalPixmap = screen->grabWindow(0, intPosX, intPosY, intSizeX, intSizeY);
    cardPixmap1 = originalPixmap.copy(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    cardPixmap2 = originalPixmap.copy(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    QImage curentCard1 = cardPixmap1.toImage();
    QImage curentCard2 = cardPixmap2.toImage();
    e->addHAnd(curentCard1, curentCard2);
    if (curentCard1 != lastCardImage1 || curentCard2 != lastCardImage2)
    {
        nb_image++;
        lastCardImage1 = cardPixmap1.toImage();
        lastCardImage2 = cardPixmap2.toImage();
    }
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckBox->isChecked())
        show();
}

QPixmap Screenshot::scan(int x, int y, int width, int height)
{
    return originalPixmap.copy(x, y, width, height);
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

void    Screenshot::uptdatePosCursor(QMouseEvent *event)
{
    qDebug() << "global X Y  " << event->globalX() << " " << event->globalY() << endl;
    mouseX->setText(QString::number(event->globalX()));
    mouseY->setText(QString::number(event->globalY()));
}

#include "preflophelperwidget.h"
#include "myopenrange.h"
#include <QLayout>
#include <rangeviewwidget.h>

PreflopHelperWidget::PreflopHelperWidget(QWidget *parent)
    : QWidget(parent),
      start(false),
      LabHand(new QLabel("Hand")),
      labPos(new QLabel("pos")),
      labOpen(new QLabel("Open / Fold"))
{
    scanner = new ImageReader();
    openRange = new myOpenRange("/Users/yann/dbpoker/open.txt");
    stackRange = new QStackedWidget(this);
    Range   *current;
    for (int i = 1; i < 6; i++)
    {
        current = openRange->getRange(static_cast<e_position>(i));
        stackRange->addWidget(new RangeViewWidget(*current, stackRange));
    }
    QGridLayout *mainLayout = new QGridLayout(this);
    btStart = new QPushButton("Start Scan");

    mainLayout->addWidget(stackRange, 0, 0, 1, 4);
    mainLayout->addWidget(btStart, 1, 0, 1, 1);
    mainLayout->addWidget(LabHand, 1, 1, 1, 1);
    mainLayout->addWidget(labPos, 1, 2, 1, 1);
    mainLayout->addWidget(labOpen, 1, 3, 1 ,1);

    connect(btStart, &QPushButton::clicked,
            this, &PreflopHelperWidget::toogleScan);
    connect(scanner, SIGNAL(newHand(Hand, e_position))
            ,this, SLOT(setHandPosition(Hand, e_position)));
    setLayout(mainLayout);
}

PreflopHelperWidget::~PreflopHelperWidget()
{
    qDebug() << "preflopHelper supr" ;
    delete scanner;
}

void    PreflopHelperWidget::setPosition(e_position pos)
{
    stackRange->setCurrentIndex(static_cast<int>(pos) - 1); // - 1 car SB(staké en 1er)  = 1
}

void    PreflopHelperWidget::setHandPosition(Hand h, e_position pos)
{
    setPosition(pos);
    LabHand->setText(h.type_hand());
    labPos->setText(stringPos(pos));
    Range *r = openRange->getRange(static_cast<e_position>(pos));
    if (r->isTrue(h.type_hand()))
        labOpen->setText("Open");
    else
        labOpen->setText("Fold");

}

void    PreflopHelperWidget::toogleScan()
{
    if (start)
    {
        scanner->stop();
        btStart->setText("Start Scan");
        start = false;
    }
    else
    {
        scanner->start();
        btStart->setText("Stop Scan");
        start = true;
    }
}

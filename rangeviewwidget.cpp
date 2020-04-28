#include "rangeviewwidget.h"
#include "util.h"

RangeViewWidget::RangeViewWidget(Range r, QWidget *parent) :
    QWidget(parent)
{
    main_layout = new QGridLayout(this);
    main_layout->setMargin(0);
    main_layout->setSpacing(0);
    this->setGeometry(0,0,500,500);
    setContentsMargins(0,0,0,0);
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 13 ; j++)
        {
            HandViewWidget *hvw = new HandViewWidget(toStrCard(i, j), this);
            if (r.tab_range[i][j])
                hvw->color();
            l_hands_widget.push_back(hvw);
            main_layout->addWidget(hvw, i, j);
        }
    setLayout(main_layout);
}

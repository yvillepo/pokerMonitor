#include "test.h"
#include "ui_test.h"

test::test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    QPalette p;
    p = palette();
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/48173892.jpg")));
    setPalette(p);
}

test::~test()
{
    delete ui;
}

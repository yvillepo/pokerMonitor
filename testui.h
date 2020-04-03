#ifndef TESTUI_H
#define TESTUI_H

#include <QWidget>

namespace Ui {
class testui;
}

class testui : public QWidget
{
    Q_OBJECT

public:
    explicit testui(QWidget *parent = nullptr);
    ~testui();

private:
    Ui::testui *ui;
};

#endif // TESTUI_H

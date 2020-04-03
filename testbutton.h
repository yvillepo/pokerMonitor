#ifndef TESTBUTTON_H
#define TESTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QSize>

class testButton : public QPushButton
{
    Q_OBJECT
public:
    QSize           sizeHint() const;
    testButton(QWidget *parent = nullptr);
    int             heightForWidth(int w);
};

#endif // TESTBUTTON_H

#ifndef RANGE_VIEW_H
#define RANGE_VIEW_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>

namespace Ui {
class range_view;
}

class range_view : public QFrame
{
    Q_OBJECT

public:
    explicit        range_view(QWidget *parent = nullptr);
    int             heightForWidth(int w) const;
    void            activate(int i);
    void            disable(int i);
    void            no_data(int i);
    void            read_bd(int pos);
    QPushButton      *btAt(int i);
    void            init();
   // QSize   sizeHint() const{return QSize(520,520);}
    ~range_view();

private:
    Ui::range_view *ui;
};

#endif // RANGE_VIEW_H

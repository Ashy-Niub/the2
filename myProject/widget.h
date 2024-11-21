#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "register.h"
#include "mywedget.h"
#include <QPaintEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *event);
    ~Widget();

private slots:
    void on_btn_in_clicked(bool checked);

    void on_btn_register_clicked(bool checked);

    void on_btn_out_clicked(bool checked);

    void on_btn_clear_clicked(bool checked);

private:
    Ui::Widget *ui;
    Register *r = new Register();
    MyWedget *mw;
    FILE *f;
    bool loginTag = 0;

};

#endif // WIDGET_H

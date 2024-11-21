#ifndef MYWEDGET_H
#define MYWEDGET_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QSerialPort>
#include "classifier.h"
namespace Ui {
class MyWedget;
}

class MyWedget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWedget(QWidget *parent = 0);
    ~MyWedget();
    QDateTime *sys_time = new QDateTime();
    void paintEvent(QPaintEvent *event);


private slots:
    void on_btn_1_clicked(bool checked);

    void on_btn_2_clicked(bool checked);

    void on_btn_3_clicked(bool checked);

    void on_btn_4_clicked(bool checked);

    void on_btn_5_clicked(bool checked);

    void on_open_clicked();

    void on_btn_find_clicked();

    void on_btn_sub_clicked();

    void on_btn_add_clicked();

    void on_btn_clear_clicked();


    void on_btn_14_clicked();

    void on_btn_11_clicked();

    void on_btn_12_clicked();

    void on_btn_13_clicked();

private:
    Ui::MyWedget *ui;
    QTimer *timer;
    QVector<ClassiFier*> v;
};

#endif // MYWEDGET_H

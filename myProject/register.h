#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_btn_clicked(bool checked);
    void paintEvent(QPaintEvent *event);

private:
    Ui::Register *ui;
    FILE *f;
signals:
    void come();
};

#endif // REGISTER_H

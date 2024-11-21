#ifndef SUN_H
#define SUN_H

#include <QWidget>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Sun;
}

class Sun : public QWidget
{
    Q_OBJECT

public:
    explicit Sun(QWidget *parent = 0);
    ~Sun();

private:
    Ui::Sun *ui;
};

#endif // SUN_H

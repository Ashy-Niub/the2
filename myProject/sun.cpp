#include "sun.h"
#include "ui_sun.h"
#include <QBarSeries>
#include <QBarSet>
#include <QtCharts>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include <QVector>
#include <QDebug>

QVector<int>data0;
QVector<int>data1;
QVector<int>data2;
QVector<int>data3;

using namespace QtCharts;
Sun::Sun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sun)
{
    ui->setupUi(this);
    for (int i = 0; i < 6; ++i) {
        data0.push_front(0);
        data1.push_front(0);
        data2.push_front(0);
        data3.push_front(0);
    }
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        data0.push_front(ui->lineEdit_1->text().toInt());
        data1.push_front(ui->lineEdit_2->text().toInt());
        data2.push_front(ui->lineEdit_3->text().toInt());
        data3.push_front(ui->lineEdit_4->text().toInt());

        QBarSet *set0 = new QBarSet("日光(min)");
        QBarSet *set1 = new QBarSet("UV(min)");
        QBarSet *set2 = new QBarSet("日光(month)");
        QBarSet *set3 = new QBarSet("UV(month)");

        QVector<int>::iterator it1 = data0.begin();
        QVector<int>::iterator it2 = data1.begin();
        QVector<int>::iterator it3 = data2.begin();
        qDebug()<<it1<<"|"<<it2<<"|"<<it3;
        //if(i)
        for(QVector<int>::iterator it4 = data3.begin();it4<data3.begin()+5;it4++)
        {
            *set0 << *it1<< *(it1+1) << *(it1+2) << *(it1+3) << *(it1+4) << *(it1+5);
            *set1 << *it2<< *(it2+1) << *(it2+2) << *(it2+3) << *(it2+4) << *(it2+5);
            *set2 << *it3<< *(it3+1) << *(it3+2) << *(it3+3) << *(it3+4) << *(it3+5);
            *set3 << *it4<< *(it4+1) << *(it4+2) << *(it4+3) << *(it4+4) << *(it4+5);
            it1++;
            it2++;
            it3++;
        }
    //    *set0 << 5 << 2 << 3 << 4 << 5 << 6;
    //    *set1 << 7 << 0 << 0 << 4 << 0 << 7;
    //    *set2 << 9 << 5 << 8 << 19<< 8 << 5;
    //    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        QChart *c = new QChart();
        c->setTitle("光照UV强度");
        c->addSeries(series);
        ui->graphicsView->setChart(c);
        c->legend()->setVisible(true);
        c->setAnimationOptions(QChart::SeriesAnimations);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        c->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
        QValueAxis *axisX = new QValueAxis();//轴变量、数据系列变量，都不能声明为局部临时变量
        QValueAxis *axisY = new QValueAxis();//创建X/Y轴
        axisX->setRange(0, 6);
        axisY->setRange(0, 10);//设置X/Y显示的区间
        c->setAxisX(axisX);
        c->setAxisY(axisY);//设置chart的坐标轴
        series->attachAxis(axisX);
        c->legend()->setVisible(true); //设置图例为显示状态
        c->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部

    });
}

Sun::~Sun()
{
    delete ui;
}

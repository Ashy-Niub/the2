#include "mywedget.h"
#include "ui_mywedget.h"
#include <QStackedWidget>
#include <QPushButton>
#include <QSerialPortInfo>
#include <QTableWidget>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
MyWedget::MyWedget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWedget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->start();
    connect(timer,&QTimer::timeout,this,[&](){
        ui->label->setText(sys_time->currentDateTime().toString("yyyy.MM.dd\nhh:mm:ss"));
    });
    ui->btn_1->setStyleSheet("background-color: rgba(100,140,140,0.5)");
    ui->btn_2->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_3->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_4->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_5->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_11->setStyleSheet("background-color: rgba(40,80,40,0.5)");
    ui->btn_12->setStyleSheet("background-color: rgba(40,40,40,0.5)");
    ui->btn_13->setStyleSheet("background-color: rgba(40,40,40,0.5)");
    ui->btn_14->setStyleSheet("background-color: rgba(255,0,0,0.5)");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->CF_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MyWedget::~MyWedget()
{
    delete ui;
}

void MyWedget::paintEvent(QPaintEvent *event)
{
    QPainter *p = new QPainter(this);
    QPixmap pix;
    pix.load(":/login_images/lantian.png");

    p->drawPixmap(0,0,this->width(),this->height(),pix);
}

//使
void MyWedget::on_btn_1_clicked(bool checked)
{
    ui->sw->setCurrentIndex(0);
    ui->btn_2->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_3->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_4->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_5->setStyleSheet("background-color: rgba(140,80,100,0.8)");
}

void MyWedget::on_btn_2_clicked(bool checked)
{
    ui->sw->setCurrentIndex(1);
    ui->btn_2->setStyleSheet("background-color: rgba(150,150,150,1)");
    ui->btn_3->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_4->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_5->setStyleSheet("background-color: rgba(140,80,100,0.8)");

}

void MyWedget::on_btn_3_clicked(bool checked)
{
    ui->sw->setCurrentIndex(2);
    ui->btn_2->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_3->setStyleSheet("background-color: rgba(150,150,150,1)");
    ui->btn_4->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_5->setStyleSheet("background-color: rgba(140,80,100,0.8)");

}

void MyWedget::on_btn_4_clicked(bool checked)
{
    ui->sw->setCurrentIndex(3);
    ui->btn_2->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_3->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_4->setStyleSheet("background-color: rgba(150,150,150,1)");
    ui->btn_5->setStyleSheet("background-color: rgba(140,80,100,0.8)");
}

void MyWedget::on_btn_5_clicked(bool checked)
{
    ui->sw->setCurrentIndex(4);
    ui->btn_2->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_3->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_4->setStyleSheet("background-color: rgba(140,80,100,0.8)");
    ui->btn_5->setStyleSheet("background-color: rgba(150,150,150,1)");
}



void MyWedget::on_open_clicked()
{
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity checkBits;
    QSerialPort::StopBits stopBits;

    if(ui->boundrateCb->currentText() == "4800")
    {
        baudRate = QSerialPort::Baud4800;
    }else if(ui->boundrateCb->currentText() == "9600")
    {
        baudRate = QSerialPort::Baud9600;
    }else if(ui->boundrateCb->currentText() == "115200")
    {
        baudRate = QSerialPort::Baud115200;
    }

    if(ui->databaseCb->currentText() == "5")
    {
        dataBits = QSerialPort::Data5;
    }else if(ui->databaseCb->currentText() == "6")
    {
        dataBits = QSerialPort::Data6;
    }else if(ui->databaseCb->currentText() == "7")
    {
        dataBits = QSerialPort::Data7;
    }else if(ui->databaseCb->currentText() == "8")
    {
        dataBits = QSerialPort::Data8;
    }

    if(ui->stopCb->currentText() == "1")
    {
        stopBits = QSerialPort::OneStop;
    }else if(ui->checkCb->currentText() == "1.5")
    {
        stopBits = QSerialPort::OneAndHalfStop;
    }else if(ui->checkCb->currentText() == "2")
    {
        stopBits = QSerialPort::TwoStop;
    }

    if(ui->checkCb->currentIndex() == 0)
    {
        checkBits == QSerialPort::NoParity;
    }else if(ui->checkCb->currentIndex() == 1)
    {
        checkBits == QSerialPort::OddParity;
    }if(ui->checkCb->currentIndex() == 2)
    {
        checkBits == QSerialPort::EvenParity;
    }

}


//用于查询分类器是否存在,并将其所在位置显示在edit上
void MyWedget::on_btn_find_clicked() //查询
{
    if(ui->lineEdit->text() == "")
        return;
    int row02 = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row02);
    //往操作记录里加入查询的记录
    ui->tableWidget->setItem(row02,0,new QTableWidgetItem("查找"+ui->lineEdit->text()));
    ui->tableWidget->setItem(row02,1, new QTableWidgetItem(sys_time->currentDateTime().toString("yyyy.MM.dd \n hh:mm:ss")));
    for(int i = 0; i < v.size(); i++)
    {
        v.at(i)->row = i+1;
    }
    //遍历容器,若与查询的内容一致,取出该数据,打印其行号与分类器名
    for(int i = 0; i < v.size();i++)
    {
        if(v.at(i)->s == ui->lineEdit->text())
        {
            ui->find_edit->setText("行:" + QString::number(v.at(i)->row) + "   " + v.at(i)->s);
            ui->lineEdit->setText("");
            return;
        }
    }
    QMessageBox::about(this,"提示","无该分类器");



}

void MyWedget::on_btn_sub_clicked()
{
    if(ui->lineEdit->text() == "")
        return;
    int row02 = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row02);
    ui->tableWidget->setItem(row02,0,new QTableWidgetItem("删除"+ui->lineEdit->text()));
    ui->tableWidget->setItem(row02,1, new QTableWidgetItem(sys_time->currentDateTime().toString("yyyy.MM.dd \n hh:mm:ss")));
    int size = v.size();
    //一旦删除一个元素,删除的元素后面的迭代器就全失效了,因为后面的元素要往前补,所以删除以后,我们直接跳出循环,避免继续调用失效的迭代器
    for (int i = 0; i <= size-1; i++) {
        if (v.at(i)->s == ui->lineEdit->text()) {
            ui->CF_tableWidget->removeRow(i);
            delete v[i];  // 如果存储的是指针，确保释放内存
            v.erase(v.begin() + i);
            break;  //及时跳出循环!!!!!
        }
    }
    ui->lineEdit->setText("");
}

//用于增加分类器
void MyWedget::on_btn_add_clicked()
{
    if(ui->lineEdit->text() == "")
        return;
    int row02 = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row02);
    ui->tableWidget->setItem(row02,0,new QTableWidgetItem("增加"+ui->lineEdit->text()));
    ui->tableWidget->setItem(row02,1, new QTableWidgetItem(sys_time->currentDateTime().toString("yyyy.MM.dd \n hh:mm:ss")));
    //获取当前tablewidget的大小,存入容器,并把数据加入到tablewidget中,使二者同步,
    int row = ui->CF_tableWidget->rowCount();
    ClassiFier *cf = new ClassiFier(row+1,ui->lineEdit->text());
    v.push_back(cf);
    ui->CF_tableWidget->insertRow(row);
    ui->CF_tableWidget->setItem(row,0,new QTableWidgetItem(v.at(row)->s));
    qDebug() << v.at(row)->s << v.at(row)->row << " " << row << endl;
    ui->CF_tableWidget->setItem(row,1, new QTableWidgetItem(sys_time->currentDateTime().toString("yyyy.MM.dd \n hh:mm:ss")));
    ui->lineEdit->setText("");

}


//用于清空分类器查询到的内容
void MyWedget::on_btn_clear_clicked()
{
    ui->find_edit->setText("");
}

void MyWedget::on_btn_14_clicked()
{
    this->close();
}

void MyWedget::on_btn_11_clicked()
{
    QMessageBox::about(this,"提示","敬请期待!");
}

void MyWedget::on_btn_12_clicked()
{
    QMessageBox::about(this,"提示","敬请期待!");
}

void MyWedget::on_btn_13_clicked()
{
    QMessageBox::about(this,"提示","敬请期待!");
}

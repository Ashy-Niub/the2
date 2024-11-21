#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(r,&Register::come,this,[&](){
        this->show();
    });


}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *p = new QPainter(this);
    QPixmap pix;
    pix.load(":/login_images/dongri.png");
    p->drawPixmap(0,0,this->width(),this->height(),pix);
}



Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_in_clicked(bool checked)
{
    if(ui->ledit_usr->text() == "")
    {
        QMessageBox::warning(this,"警告","请输入账号");
        return;
    }
    else if(ui->ledit_pwd->text() == "")
    {
        QMessageBox::warning(this,"警告","请输入密码");
        return;
    }
    f = fopen("../a.txt","r");
    char c[50];
    while(fgets(c,50,f))
    {
        c[strcspn(c, "\n")] = '\0';
        QString s02 = "usr=";
        QString s = s02 + ui->ledit_usr->text().toUtf8().data();
//        strcmp()
        if(strcmp(c,s.toUtf8().data()) != 0)
        {
            continue;
        }
        loginTag = 1;
        if(loginTag == 1)
        {
            fgets(c,50,f);
            c[strcspn(c, "\n")] = '\0';
            QString password(c + 4);
            if(strcmp(ui->ledit_pwd->text().toUtf8().data(),password.toUtf8().data()) == 0)
            {
                QMessageBox::about(this, "登录成功", "登录成功");
                this->hide();
                mw = new MyWedget();
                mw->show();
                return;
            }
            else
            {
                loginTag = 0;
                QMessageBox::critical(this, "错误", "账号密码不匹配");
                return;
            }
        }
    }
    if(loginTag == 0)
    {
        QMessageBox::critical(this,"错误","账号不存在");
        return;
    }

}


void Widget::on_btn_register_clicked(bool checked)
{
    this->hide();
    r->show();
}

void Widget::on_btn_out_clicked(bool checked)
{
    this->close();
}

void Widget::on_btn_clear_clicked(bool checked)
{
    ui->ledit_usr->clear();
    ui->ledit_pwd->clear();
}

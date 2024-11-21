#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
//#include <QFile>
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}


Register::~Register()
{
    delete ui;
}

void Register::paintEvent(QPaintEvent *event)
{
    QPainter *p = new QPainter(this);
    QPixmap pix;
    pix.load(":/login_images/fengjing.png");
    p->drawPixmap(0,0,this->width(),this->height(),pix);
}

void Register::on_btn_clicked(bool checked)
{
    if(ui->leid_usr->text() == "")
    {
        QMessageBox::warning(this,"警告","请输入账号");
    }
    if(ui->ledit_pwd->text() == "")
    {
        QMessageBox::warning(this,"警告","请输入密码");
        return;
    }
    if(ui->ledit_pwd->text() != ui->ledit_pwd_02->text())
    {
        QMessageBox::warning(this,"警告","密码不一致");
        return;
    }
    char c[50];
    f = fopen("../a.txt","a+");
    while (fgets(c,50,f)) {
        qDebug() << c << endl;
        QString s = "usr=" + ui->leid_usr->text();
        //我们发现c数组中会获得\n,所以,我们把它为\n的位置的值(\n)换为\0
        c[strcspn(c, "\n")] = '\0';
        if(strcmp(c,s.toUtf8().data()) == 0)
        {
            QMessageBox::warning(this,"警告","账号已存在");
            return;
        }
    }
    QMessageBox::about(this,"提示","注册成功");
    QString s = "usr=" + ui->leid_usr->text() + "\n";
    QString s02 = "pwd=" + ui->ledit_pwd->text() + "\n";
    fwrite(s.toUtf8().data(),s.size(),1,f);
    fwrite(s02.toUtf8().data(),s02.size(),1,f);
    fclose(f);
    emit come();
    this->close();
}

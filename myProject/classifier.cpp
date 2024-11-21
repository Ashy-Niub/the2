#include "classifier.h"

ClassiFier::ClassiFier(QObject *parent) : QObject(parent)
{
    row = 0;
}

ClassiFier::ClassiFier(int row, QString s)
{
    this->row = row;
    this->s = s;
}

ClassiFier::ClassiFier(ClassiFier &c)
{
    row = c.row;
    s = c.s;
}

ClassiFier::~ClassiFier()
{

}

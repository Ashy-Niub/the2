#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <QObject>
#include <QString>
#include <QVector>

class ClassiFier : public QObject
{
    Q_OBJECT
public:
    explicit ClassiFier(QObject *parent = 0);
    ClassiFier(int row,QString s);
    ClassiFier(ClassiFier &c);
    ~ClassiFier();
    int row;
    QString s;

signals:

public slots:

private:

};

#endif // CLASSIFIER_H

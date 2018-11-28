#include "rodent.h"

Rodent::Rodent(QString name)
{
    QString qsTemp = "New rodend %1 was born! Weigh is %2";
    qDebug() << qsTemp.arg(name).arg(this->weight);
    this->name = name;
}

Rodent::~Rodent()
{
    QString qsTemp = "Thes rodend %1 was die! :( RIP Weigh is %2";
    qDebug() << qsTemp.arg(name).arg(this->weight);
}

void Rodent::feed(double food)
{
    weight+=food;

}

bool Rodent::lifeDay()
{
    weight-=0.34;
    if(weight<0.0)return(false);
    age++;
    return(true);
}

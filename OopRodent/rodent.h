#ifndef RODENT_H
#define RODENT_H

#include <QDebug>
#include <QString>

class Rodent
{
    double weight =1.0; //gramm
    int age=0; //age in days
    int maxLifeSpan = 1000; // in days
    QString name;
public:
    Rodent(QString name); // Constructor
   ~Rodent(); // Destructor
    QString getName() {return name;}
    void feed(double food); // Feed rodent with some gramm of food
    bool lifeDay(); // spend one day of life, ferurn false is rodent die.
};

#endif // RODENT_H

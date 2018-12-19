#ifndef RODENT_H
#define RODENT_H

#include <QDebug>
#include <QString>

class Rodent
{
     int maxLifeSpan = 1000; // in days
protected:
    double weight =1.0; //gramm
    // Maximum weigth is 250 gramm

    int age=0; //age in days
    QString name;

public:
    Rodent();
    Rodent(QString name); // Constructor
   ~Rodent(); // Destructor
    // get and set name
    QString getName() {return name;}
    void setName(QString newName) {name = newName;}

    double getWeight() {return weight;}

    // Add function - get Info, return QString with all information

    void feed(double food); // Feed rodent with some gramm of food
    bool lifeDay(); // spend one day of life, ferurn false is rodent die.
};


class Mouse: public Rodent{
public:
    Mouse(QString name); // Constructor
    void addTwoGrams();
    bool lifeDay();
};

//Add new class Hamster, base on Rodent

#endif // RODENT_H

# Oop Rodent
main class for all rodents.

C++ Inheritance
https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

C++ Class Constructor and Destructor
https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm

```javascript
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
```

```javascript
class Mouse: public Rodent{
public:
    Mouse(QString name); // Constructor
    void addTwoGrams();   // super power :)
    bool lifeDay();     // function overloading
};
```


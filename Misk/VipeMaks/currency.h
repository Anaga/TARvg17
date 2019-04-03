#ifndef CURRENCY_H
#define CURRENCY_H

#include <QtGlobal>
#include <QString>

class Currency
{
private:
    qint16 m_val;
public:
    Currency(){m_val=0;}
    Currency(int const val);
    Currency(double const val);
    Currency &operator=(const int val);
    Currency &operator=(const double val);
    Currency &operator+(const Currency &other){
        m_val+=other.m_val;
        return  *this;
    }
    long getVal() {return m_val;}
    QString toPrint();
    operator QString() const { return QString::number(m_val/100.0,'f',2); }
};

Q_DECLARE_TYPEINFO(Currency, Q_MOVABLE_TYPE );

#endif // CURRENCY_H

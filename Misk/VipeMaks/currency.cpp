#include "currency.h"

Currency::Currency(const int val)
{
    m_val = static_cast<qint16>(val*100);
}

Currency::Currency(const double val)
{
    m_val = static_cast<qint16>(val*100);
}

Currency &Currency::operator=(const int val)
{
     m_val = static_cast<qint16>(val*100);
     return *this;
}

Currency &Currency::operator=(const double val)
{
    m_val = static_cast<qint16>(val*100);
    return *this;
}

QString Currency::toPrint()
{
    double f_val = m_val/100.00;
    return QString::number(f_val,'f',2);
}

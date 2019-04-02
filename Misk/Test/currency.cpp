#include "currency.h"

Currency::Currency(const int val)
{
    m_val = static_cast<quint16>(val*100);
}

Currency::Currency(const double val)
{
    m_val = static_cast<quint16>(val*100);
}

Currency &Currency::operator=(const int val)
{
     m_val = static_cast<quint16>(val*100);
     return *this;
}

Currency &Currency::operator=(const double val)
{
    m_val = static_cast<quint16>(val*100);
    return *this;
}

QString Currency::toPrint()
{
    return "10.34";
}

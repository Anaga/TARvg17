#include "mastercard.h"

mastercard::mastercard(QObject *parent) : QObject(parent)
{
    m_totalPay = 1;
}

void mastercard::setCardNumber(long long newCardNumber)
{
    m_cardNumber = newCardNumber;
}

bool mastercard::canVipe(Currency summa)
{
    Currency oneTimeLimit = 25;
    if (summa.getVal() >= oneTimeLimit.getVal()) return false;

    Currency manyTimeLimit = 50;

    Currency temp;
    temp = summa + m_totalVipe;
    if (temp.getVal() >= manyTimeLimit.getVal()) return false;

    int payTimesLimit = 10;
    if (m_totalPay>= payTimesLimit) return false;

    m_totalPay++;
    m_totalVipe = temp;

    return true;
}

QString mastercard::getInfo()
{
    QString qsTemp = "Card %1 has %2 euro per vipe %3 times";
    return qsTemp.arg(m_cardNumber)
            .arg(m_totalVipe.toPrint())
            .arg(m_totalPay);
}

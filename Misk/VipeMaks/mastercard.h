#ifndef MASTERCARD_H
#define MASTERCARD_H

#include <QObject>
#include "currency.h"

class mastercard : public QObject
{
    Q_OBJECT
    long long m_cardNumber;
    Currency m_totalVipe;
    int m_totalPay;
public:
    explicit mastercard(QObject *parent = nullptr);
    void setCardNumber(long long newCardNumber);
    long long getCardNumber() {return m_cardNumber;}
    bool canVipe( Currency summa);
    QString getInfo();
signals:

public slots:
};

#endif // MASTERCARD_H

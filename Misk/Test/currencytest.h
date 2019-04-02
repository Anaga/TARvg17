#ifndef CURRENCYTEST_H
#define CURRENCYTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "currency.h"

class CurrencyTest : public QObject
{
    Q_OBJECT
public:
    explicit CurrencyTest(QObject *parent = nullptr);

signals:

public slots:
private slots:
    void initTestCase();
    void intConstructor();
    void cleanupTestCase();

};

#endif // CURRENCYTEST_H

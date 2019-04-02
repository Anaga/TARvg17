#include "currencytest.h"

CurrencyTest::CurrencyTest(QObject *parent) : QObject(parent)
{

}

void CurrencyTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void CurrencyTest::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}

void CurrencyTest::intConstructor()
{
    Currency oneEuro(1);
    Currency SomeSents = 0.34;

    Currency total = oneEuro+SomeSents;
    QVERIFY(total.toPrint() == "HELLO");

}

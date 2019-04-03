#include <QtTest>
#include <QDebug>
// add necessary includes here
#include "currency.h"

class CurTest : public QObject
{
    Q_OBJECT

public:
    CurTest();
    ~CurTest();

private slots:
    void test_CurConstuctor();
    void test_case1();
    void test_CurSumma();
    void test_CurSumma_data();

};

CurTest::CurTest()
{
    qDebug() << "Start testing";
}

CurTest::~CurTest()
{
    qDebug() << "Ending testing";
}

void CurTest::test_CurConstuctor()
{
     Currency oneEuro(1);
     qDebug() << oneEuro.toPrint();
     QVERIFY2(oneEuro.toPrint() == "1.00", "One Euro it is 1.00");

     Currency twoEuro = 2;
     qDebug() << twoEuro.toPrint();
     QVERIFY2(twoEuro.toPrint() == "2.00", "Two Euro it is 2.00");

     Currency negativVal = -3;
     qDebug() << negativVal.toPrint();
     QVERIFY2(negativVal.toPrint() == "-3.00", "This shall be negative");

     Currency SomeSents = 0.34;
     qDebug() << SomeSents.toPrint();
     QVERIFY2(SomeSents.toPrint() == "0.34", "SomeSents is 0.34");

     Currency negSents(-0.02);
     qDebug() << negSents;
     QVERIFY2(negSents.toPrint() == "-0.02", "negSents is -0.02");

     Currency bigMix = 321.67890;
     qDebug() << bigMix;
    QVERIFY2(bigMix.toPrint() == "321.67", "bigMix is 321.67");

}

void CurTest::test_CurSumma()
{
    QFETCH(double, first);
    QFETCH(double, second);
    QFETCH(QString, result);

    Currency currA(first);
    Currency currB(second);

    Currency total = currA+currB;
    qDebug() << total;
    QVERIFY(total.toPrint() == result);
}

void CurTest::test_CurSumma_data()
{
    QTest::addColumn<double>("first");
    QTest::addColumn<double>("second");
    QTest::addColumn<QString>("result");

    QTest::newRow("tenEuro + someNegSents") << 10.0 << -0.34 << "9.66";
    QTest::newRow("tenEuro + someSents")    << 10.0 <<  0.34 << "10.34";
}

void CurTest::test_case1()
{
    Currency oneEuro(10);
    Currency SomeSents = 0.34;

    Currency total = oneEuro+SomeSents;
    QVERIFY(total.toPrint() == "10.34");
    oneEuro = 1;
    total = oneEuro+SomeSents;
    qDebug() << total.toPrint();
    QVERIFY(total.toPrint() == "1.34");
}

QTEST_APPLESS_MAIN(CurTest)

#include "tst_curtest.moc"

#include <QtTest>

// add necessary includes here
#include <QDebug>

#include "mastercard.h"

class vipe : public QObject
{
    Q_OBJECT

    mastercard goldenCard;

public:
    vipe();
    ~vipe();

private slots:
    void test_case1();
    void test_canIPay();
    void test_canIPayMulti();
    void test_tryCounts();
    void test_tryCounts_data();


};

vipe::vipe()
{
    goldenCard.setCardNumber(1111222233334444);
}

vipe::~vipe()
{

}

void vipe::test_case1()
{
    mastercard vipe1;
    vipe1.setCardNumber(1234123412341234);
    QVERIFY(vipe1.getCardNumber() == 1234123412341234);

    QVERIFY2(vipe1.getCardNumber() == 1234123412341234,
             "card number shall be 1234123412341234");
}

void vipe::test_canIPay()
{
    mastercard vipe1;
    vipe1.setCardNumber(1234123412341234);

    Currency someEuro(13);
    QVERIFY2(vipe1.canVipe(someEuro) == true,
             "We can pay 13 euro by vipe");
    someEuro = 30;
    QVERIFY2(vipe1.canVipe(someEuro) == false,
             "We cannot pay 30 euro by vipe");
}

void vipe::test_canIPayMulti()
{
    mastercard vipe1;
    vipe1.setCardNumber(1234123412341234);
    qDebug() << vipe1.getInfo();

    Currency someEuro(21);
    QVERIFY2(vipe1.canVipe(someEuro) == true,
             "We can pay 21 euro by vipe (total 21)");
    qDebug() << vipe1.getInfo();

    someEuro = 23;
    QVERIFY2(vipe1.canVipe(someEuro) == true,
             "We can pay 23 euro by vipe (total 44)");
    qDebug() << vipe1.getInfo();

    someEuro = 10;
    QVERIFY2(vipe1.canVipe(someEuro) == false,
             "We cannot pay 10 euro by vipe, total limit exided (total 54)");
    qDebug() << vipe1.getInfo();

    someEuro = 4;
    QVERIFY2(vipe1.canVipe(someEuro) == true,
             "We can pay 4 euro by vipe, total limit exided (total 54)");
    qDebug() << vipe1.getInfo();
}

void vipe::test_tryCounts()
{
    qDebug() << goldenCard.getInfo();

    QFETCH(int, first);
    QFETCH(bool, result);
    Currency toPay(first);

    QVERIFY2(goldenCard.canVipe(toPay) == result,
             "We can pay 1 euro by vipe, total x");

    qDebug() << goldenCard.getInfo();
}

void vipe::test_tryCounts_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("1") << 1 << true;
    QTest::newRow("2") << 1 << true;
    QTest::newRow("3") << 1 << true;
    QTest::newRow("4") << 1 << true;
    QTest::newRow("5") << 1 << true;
    QTest::newRow("6") << 1 << true;
    QTest::newRow("7") << 1 << true;
    QTest::newRow("8") << 1 << true;
    QTest::newRow("9") << 1 << true;
    QTest::newRow("10")<< 1 << false;

}

QTEST_APPLESS_MAIN(vipe)

#include "tst_vipe.moc"

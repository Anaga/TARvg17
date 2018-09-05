#include <QCoreApplication>
#include <QDebug> //F1 for help
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication ann(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    qDebug() << "Hello TAR vg 17!" ; // Qt debug output to console
    qDebug() << "Let's pull it!";
    int a, b;
    int n, m, l;
    qDebug() << "Please enter size of brick \n";
    cin >> n >> m >> l;
    QString qsSizes = "size of brick is %1x%2x%3\n";
    qsSizes = qsSizes.arg(n).arg(m).arg(l);
    qDebug() << qsSizes;

    qDebug() << "Please enter size of hole \n";
    cin >> a >> b;
    qsSizes = "size of hole is %1x%2\n" ;
    qsSizes = qsSizes.arg(a).arg(b);
    qDebug() << qsSizes;

    return ann.exec();
}

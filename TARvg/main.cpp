#include <QCoreApplication>
#include <QDebug> //F1 for help
#include <QTextStream>
#include <QString>

#include "swithgender.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication ann(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    qDebug() << "Hello TAR vg 17!" ; // Qt debug output to console

    while (mainFunc())
    {
         qDebug() << "while body";
    }


#if 0 // fast way to disable some code
    qDebug() << "Let's pull it!";
    int a, b;
    int n, m, l;
    for (;;) {
        qDebug() << "Please enter size of brick";
        cin >> n >> m >> l;
        QString qsSizes = "size of brick is %1x%2x%3";
        qsSizes = qsSizes.arg(n).arg(m).arg(l);
        qDebug() << qsSizes;
        if ((n == 0) || (m==0) || (l==0)) return 0;

        qDebug() << "Please enter size of hole";
        cin >> a >> b;
        qsSizes = "size of hole is %1x%2" ;
        qsSizes = qsSizes.arg(a).arg(b);
        qDebug() << qsSizes;
        if ((a == 0) || (b==0)) return 0;

        // First check brick ( put on M side ): 20x3x4  hole: 3x5
        {
            qDebug() << "First check brick ( put on M side ):";
            if ((l<a) && (n<b)) qDebug() << "fits 1.1";
            if ((l<b) && (n<a)) qDebug() << "fits 1.2";
        }

        // Second check ( put on N side ),
        {
            qDebug() << "Second check brick ( put on N side ):";
            if ((m<a) && (l<b)) qDebug() << "fits 2.1";
            if ((m<b) && (l<a)) qDebug() << "fits 2.2";
        }

        // Last check ( put on L side )
        {
            qDebug() << "Last check brick ( put on L side ):";
            if ((m<a) && (n<b)) qDebug() << "fits 2.1";
            if ((m<b) && (n<a)) qDebug() << "fits 2.2";
        }
    }
#endif // End of code disabling

    return ann.exec();
}


















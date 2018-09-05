#include <QCoreApplication>
#include <QDebug> //F1 for help

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello TAR vg 17!" ; // Qt debug output to console
    qDebug() << "Let's pull it!";

    return a.exec();
}

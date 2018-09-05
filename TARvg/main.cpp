#include <QCoreApplication>
#include <QDebug> //F1 for help

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello TAR vg 17!" ; // Qt debug output to console

    return a.exec();
}

#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello Qt";
    qDebug() << "Rусский Текст";

    return a.exec();
}

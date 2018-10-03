#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "Helo Qt from new class!";
    QCoreApplication a(argc, argv);

    return a.exec();
}

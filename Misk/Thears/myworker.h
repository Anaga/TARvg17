#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(QObject *parent = nullptr);

signals:
    void valueChange(int);

private slots:
    void setNextValue();

public slots:
    void workHarder();
    void breakWork();
    void setTimeout(int value);

private:
    int m_delay;
    int m_value;

    QTimer *m_timer;

};

#endif // MYWORKER_H

#include "myworker.h"

MyWorker::MyWorker(QObject *parent) : QObject(parent)
{
    m_value = 0;
    m_delay = 100;
    m_timer = new QTimer(this);

    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(setNextValue()));


    qDebug() << __PRETTY_FUNCTION__;

}

void MyWorker::setNextValue()
{
    qDebug() << __PRETTY_FUNCTION__;
    qDebug() << "m_value" << m_value;
    m_value++;
    emit valueChange(m_value);
}

void MyWorker::workHarder()
{
    qDebug() << __PRETTY_FUNCTION__;
    m_timer->start(m_delay);

}

void MyWorker::breakWork()
{
    qDebug() << __PRETTY_FUNCTION__;

    m_timer->stop();
}

void MyWorker::setTimeout(int value)
{
    qDebug() << __PRETTY_FUNCTION__;
    qDebug() << "m_delay" << m_delay << "m_value" << m_value;
    m_delay = value;
}

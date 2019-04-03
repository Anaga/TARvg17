QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_vipe.cpp \
    currency.cpp \
    mastercard.cpp

HEADERS += \
    currency.h \
    mastercard.h

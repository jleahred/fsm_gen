TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    *.cpp

HEADERS += \
    *.h \
    *.hpp

DISTFILES += \
    iceberg.dot \
    iceberg.fsm

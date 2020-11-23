TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    *.cpp

HEADERS += \
    *.h \
    *.hpp \

DISTFILES += \
    login.dot \
    login.fsm

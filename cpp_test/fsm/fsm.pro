TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    *.cpp \
    fsm/*.cpp \

HEADERS += \
    *.h \
    *.hpp \
    fsm/*.h \
    fsm/*.hpp \

DISTFILES += \
    login.dot \
    login.fsm

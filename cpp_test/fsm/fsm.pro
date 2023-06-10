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
    fsm_login/*.h \
    fsm_login/*.hpp \
    fsm_login/*.cpp \

DISTFILES += \
    login.dot \
    login.fsm

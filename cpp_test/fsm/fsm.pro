TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    fsm_login_gen.cpp

HEADERS += \
    fsm_login_types.h \
    fsm_login_gen.h \
    fsm_login_private.hpp

DISTFILES += \
    login.dot \
    login.fsm

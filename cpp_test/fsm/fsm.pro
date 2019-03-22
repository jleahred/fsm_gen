TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    fsm_login.cpp \
    fsm_login_gen.cpp

HEADERS += \
    fsm_login.h \
    fsm_login_gen.h

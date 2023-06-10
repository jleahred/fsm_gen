TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    *.cpp \
    fsm_login/*.cpp \
    fsm_login/impl/*.cpp \

HEADERS += \
    *.h \
    *.hpp \
    fsm_login/*.h \
    fsm_login/*.hpp \
    fsm_login/impl/*.h \
    fsm_login/impl/*.hpp \

DISTFILES += \
    login.dot \
    login.fsm

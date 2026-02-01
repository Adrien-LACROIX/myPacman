TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/classes.cpp \
    src/settings.cpp \
    src/pacman/src/easterEggs.cpp \
    src/menu.cpp \
    src/matrix.cpp \
    src/move.cpp \
    src/main.cpp

DISTFILES += \
    config.yaml

HEADERS += \
    include/type.h \
    include/models.h

unix {
    TARGET = MyPacman
}

win32 {
    TARGET = MyPacman
}
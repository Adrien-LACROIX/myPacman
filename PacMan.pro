TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/pacman/src/Doc_Prof/game.cpp \
    src/pacman/src/Doc_Prof/gridmanagement.cpp \
    src/pacman/src/Doc_Prof/params.cpp \
    src/pacman/src/EasterEggs.cpp \
    src/pacman/src/EasterEggs.cpp \
    src/pacman/src/map.cpp \
    src/pacman/src/move.cpp \
    src/pacman/src/main.cpp

DISTFILES += \
    config.yaml

HEADERS += \
    src/pacman/headers/Doc_Prof/game.h \
    src/pacman/headers/Doc_Prof/gridmanagement.h \
    src/pacman/headers/Doc_Prof/params.h \
    src/pacman/headers/Doc_Prof/type.h \
    src/pacman/headers/models.h

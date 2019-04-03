QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Character.cpp \
    Command.cpp \
    Item.cpp \
    Location.cpp \
    main.cpp \
    Weapon.cpp \
    mainwindow.cpp \
    ZorkCore.cpp \
    inventorywindow.cpp \
    armour.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
	NewZork.pro

DISTFILES += \
	NewZork.pro.user

HEADERS += \
    Character.h \
    Command.h \
    Item.h \
    Location.h \
    Weapon.h \
    mainwindow.h \
    ZorkCore.h \
    inventorywindow.h \
    armour.h

FORMS += \
    mainwindow.ui \
    ZorkCore.ui \
    inventorywindow.ui

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = gui_test_code

DESTDIR = $$PWD/../../../bin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/src

SOURCES += \
    main.cpp \
    src/control/control01_widget01.cpp \
    src/helper/control_helper.cpp \
    src/helper/main_helper.cpp \
    src/helper/part_helper.cpp \
    src/part01/part01_widget01.cpp

HEADERS += \
    src/control/control01_widget01.h \
    src/helper/control_helper.h \
    src/helper/main_helper.h \
    src/helper/part_helper.h \
    src/part01/part01_widget01.h

FORMS += \
    resources/ui/control01_widget01.ui \
    resources/ui/part01_widget01.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

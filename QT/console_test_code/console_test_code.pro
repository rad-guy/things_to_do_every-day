QT += core network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TARGET = console_test_code

DESTDIR = $$PWD/../../../bin

QMAKE_CXXFLAGS += -Werror=return-type       # 无返回值
QMAKE_CXXFLAGS += -Werror=return-local-addr # 返回局部变量地址
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        src/classes/test_QCoreApplication.cpp \
        src/classes/test_QSettings.cpp \
        src/helper/classes_helper.cpp \
        src/helper/main_helper.cpp \
        src/helper/module_helper.cpp \
        src/helper/part_helper.cpp \
        src/helper/utils_helper.cpp \
        src/part01/part01_class01.cpp \
        src/part01/part01_class02.cpp \
        src/utils/file_utils.cpp \
        src/utils/string_utils.cpp \
        src/utils/system_utils.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/classes/test_QCoreApplication.h \
    src/classes/test_QSettings.h \
    src/helper/classes_helper.h \
    src/helper/main_helper.h \
    src/helper/module_helper.h \
    src/helper/part_helper.h \
    src/helper/utils_helper.h \
    src/include/include.h \
    src/part01/part01_class01.h \
    src/part01/part01_class02.h \
    src/utils/file_utils.h \
    src/utils/string_utils.h \
    src/utils/system_utils.h

INCLUDEPATH += \
    $$PWD/src

#include "helper/main_helper.h"
#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 设置组织名字，设置程序名字
    QCoreApplication::setOrganizationName("self");
    QCoreApplication::setOrganizationDomain("c30.com");
    QCoreApplication::setApplicationName("console_test");

    QSettings set;
    set.setDefaultFormat(QSettings::IniFormat);
    set.setValue("help/mine","test");
    CMainHelper helper;
    helper.excutePart01();
    helper.excuteUtils01();
    helper.excuteClasses01();
    return a.exec();
}

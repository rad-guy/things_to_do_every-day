#include <QCoreApplication>
#include "helper/main_helper.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CMainHelper helper;
    helper.excutePart01();
    helper.excuteUtils01();
    return a.exec();
}

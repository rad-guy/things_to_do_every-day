#include <QCoreApplication>
#include "helper/main_helper.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPartHelper::excuteClass01();
    return a.exec();
}

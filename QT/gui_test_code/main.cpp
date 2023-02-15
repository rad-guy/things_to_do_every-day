#include "helper/main_helper.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPartHelper::excuteWidget01();
    return a.exec();
}

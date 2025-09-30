#include "helper/main_helper.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CMainHleper::testControlHelper();
    CMainHleper::testPartHelper();


    return a.exec();
}

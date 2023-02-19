#include "classes/test_QCoreApplication.h"
#include "include/include.h"
#include <QCoreApplication>

void CTestQCoreApplication::testStaticFunc()
{
    QString exeDirPath = QCoreApplication::applicationDirPath();
    QString exePath = QCoreApplication::applicationFilePath();
    QString exeName = QCoreApplication::applicationName();
    qint64 exePid = QCoreApplication::applicationPid();
    QString exeVersion = QCoreApplication::applicationVersion();
    QStringList arguList = QCoreApplication::arguments();

}

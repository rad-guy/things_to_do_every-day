#include "helper/main_helper.h"

void CMainHelper::excutePart01()
{
    CPartHelper::excuteClass01();
}

void CMainHelper::excuteUtils01()
{
    Utils::CSystemHelper systemHelper;
    systemHelper.testSystemUtils();
    Utils::CFileHelper fileHelper;
    fileHelper.testFileUtils();
}

void CMainHelper::excuteClasses01()
{
    CClassesHelper::testQCoreApplication();
    CClassesHelper::testQSettings();
}

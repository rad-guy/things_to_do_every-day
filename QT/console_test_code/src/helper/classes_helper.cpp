#include "helper/classes_helper.h"

void CClassesHelper::testQCoreApplication()
{
    CTestQCoreApplication testQCoreApplication;
    testQCoreApplication.testStaticFunc();

}

void CClassesHelper::testQSettings()
{
    CTestQSettings testQSettings;
    testQSettings.testWriteReadIniFile();
    testQSettings.testNoPath();
}

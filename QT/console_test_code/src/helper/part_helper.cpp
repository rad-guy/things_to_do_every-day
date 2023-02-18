#include "helper/main_helper.h"

#include "part01/part01_class01.h"
#include "part01/part01_class02.h"


void CPartHelper::excuteClass01()
{
    CPart01Class01 class01;
    class01.testQStringList();
    class01.testStrTranscode();
    class01.testAllPath();
    class01.testNoReturn();
    std::string testString = class01.testFeferenceReturn();
    qInfo() << "结论：返回局部变量的引用，程序崩溃";
}

void CPartHelper::excuteClass02()
{

}

#include "classes/test_QSettings.h"
#include "include/include.h"
#include <QSettings>

void CTestQSettings::testNoPath()
{
    // 组织和程序名字已经设置了，所以这里不用传参数  可以用这个作为系统 app 的配置文件
    QSettings settings;
    settings.setValue("app/path","123");
    settings.setValue("test/name","1234");
    QString testStr = settings.value("help/mine").toString();
    qInfo() << "设置组织 和 程序名 可以无参公用一个配置文件，但是路径不知道在哪";
}

void CTestQSettings::testWriteReadIniFile()
{
    // QSettings::NativeFormat 在 windows 中是注册表 linux 中 是 .conf 后缀文件
    // QSettings::IniFormat

    QSettings settings("./test.ini",QSettings::IniFormat);
    // 写
    // 方法1
    settings.setValue("test1/name","dhx");  // test1 节 不存在则创建
    settings.setValue("test1/age","27");
    qInfo() << "结论：添加成功，创建了 test.ini 文件";

    // 方法2
    settings.beginGroup("test2");  // 进入节 没有还没有创建节
    if (!settings.childKeys().contains("sex"))  // 判断 key 是否包含
    {
        settings.setValue("sex","man");   // 这一步 创建了节 也创建了 key
    }
    settings.endGroup();

    // 读
    if (!settings.contains("test3/exist"))
    {
        settings.setValue("test3/exist","yes");  // 不存在则创建
    }
    else
    {
        QString value = settings.value("test3/exist").toString(); // 存在 读取
        qInfo() << "结论：读取成功，value = " << value;
    }
}

#include "part01/part01_class01.h"

#include <QLatin1Char>
#include <QStringList>
#include <QDebug>
#include <QTextCodec>
#include <QCoreApplication>

void CPart01Class01::testQStringList()
{
    // QStringList 字符串列表
    // 1. 初始化
    QStringList qstrList;
    // 2. 增加字符串 << append
    qstrList << "Python" << "C++" << "JavaScript" << "Go" ;
    qstrList.append("C");
    // 3. 插入字符串
    qstrList.insert(0,"REPLACE");
    // 4. 替换字符串
    qstrList.replace(0,"QStringList");
    // 5. 合并字符串
    QString joinStr = qstrList.join(",-");
    qDebug() << "joinStr=" << joinStr << "\n";

    // 6.拆分字符串
    QString numStr = "1,2,3,,4,5";
    // QStringLiteral  类提供一个 8 位 ASCII/Latin-1 字符
    QStringList list1 = numStr.split(QStringLiteral(","));
    // list1: [ "1", "2","3"," ", "4", "5" ]
    QStringList list2 = numStr.split(",", Qt::SkipEmptyParts);
    // list2:[ "1", "2", "3", "4" , "5"]

    // 7.删除字符串
    qstrList.removeAt(4);

    // 8.索引
    int index = qstrList.indexOf("C++");

    // 9.替换 replaceInStrings
    qstrList.replaceInStrings("C++","C");

    // 10.过滤 提取一个新的列表包含一个特定的字符串或匹配特定正则表达式）
    QStringList filterList = qstrList.filter("Java");

    // 11.遍历
    QStringListIterator qstrIt(qstrList);
    while (qstrIt.hasNext())
        qDebug() << qstrIt.next() << "\n";

}

void CPart01Class01::testStrTranscode()
{
    // utf-8 to gb2312
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(utf8);
    QTextCodec* gbk = QTextCodec::codecForName("gbk");

    QString str1="您好";
    char *p=str1.toLocal8Bit().data(); //如此可以等到它的char*

    qDebug() << p;
    //utf8 -> gbk
    //1. utf8 -> unicode
    QString strUnicode= utf8->toUnicode(str1.toLocal8Bit().data());
    //2. unicode -> gbk, 得到QByteArray
    QByteArray gb_bytes= gbk->fromUnicode(strUnicode);
    p =  gb_bytes.data(); //获取其char *
    qDebug() << p;
    //gbk -> utf8
    //1. gbk to unicode
    strUnicode=gbk->toUnicode(p);
    //2. unicode -> utf-8
    QByteArray utf8_bytes=utf8->fromUnicode(strUnicode);
    p = utf8_bytes.data(); //获取其char *
    qDebug() << p;
}

void CPart01Class01::testAllPath()
{
    QString exePath = QCoreApplication::applicationFilePath();
    QString exeDirPath = QCoreApplication::applicationDirPath();

}

std::string CPart01Class01::testNoReturn()
{
    std::string temp = "testNoReturnFunc";
    qInfo() << temp.data();
    qInfo() << "结论：函数声明有返回，实现无返回，编译通过，程序崩溃";
    return temp;
}

const std::string &CPart01Class01::testFeferenceReturn()
{
//    return "[]";    // 返回局部变量的引用，程序崩溃
    static std::string temp = "test";
    return temp;
}

#pragma once
#include "helper/utils_helper.h"
#include <QDebug>

using namespace Utils;

void CSystemHelper::testSystemUtils()
{
    // 测试获取 本机 ip
    QString ipAddress = CSystemUtils::getLocalIp();
    qInfo() << "get ip = " << ipAddress;
    // 测试获取 网络信息
    CSystemUtils::testNetInfo();
    //
}

void CFileHelper::testFileUtils()
{
    // 测试 获取目录下 所有文件的路径 递归
    QVector<QString> files;
    CFileUtils::getDirFilesPath("D:/res",files,"png",true);
    qInfo() << "结论：验证成功";

    // 测试 获取目录下 所有文件信息和文件夹路径
    QVector<QFileInfo> fileInfos;
    QVector<QString> folders;
    CFileUtils::getDirFilesFolders("D:/res",fileInfos,folders);
    qInfo() << "结论：验证成功";

    // 测试 获取目录所在磁盘的 可用空间 gb 为单位
    qint64 diskFreeSize = CFileUtils::getDiskFreeSpaceSize("D:/temp") / 1024;
    qInfo() << "结论：验证成功";
}

#pragma once
#include "src/include/include.h"


#include <QFileInfo>

class CFileUtils
{
public:

    //  获取目标路径下 所有的文件的路径信息 isRecursion 是否递归
    static void		getDirFilesPath(const QString & destPath, QVector<QString>& files,const QString& ext = "", bool isRecursion = false);
    //  获取目标路径下 所有的文件信息
    static void		getDirFilesInfo(const QString & destPath, QFileInfoList& files, bool isRecursion = false);
    //  获取目标路径下 所有的文件 文件夹信息 (不递归)
    static void		getDirFilesFolders(const QString & destPath, QVector<QFileInfo>& files, QVector<QString>& folders);
    static void		getDirFilesFolders(const QString & destPath, QFileInfoList& files);

    //  获取 盘符 剩余空间
    static qint64   getDiskFreeSpaceSize(const QString& destPath);


    static int      copyFolder(const QString & srcPath, const QString & destPath);
    static int      renameFolder(const QString & srcPath, const QString & destPath);
    static int      moveFolder(const QString & srcPath, const QString & destPath);

    static bool     copyFile(const QString & srcPath, const QString & destPath);
    static bool     renameFile(const QString & srcPath, const QString & destPath);
    static bool     moveFile(const QString & srcPath, const QString & destPath);

};

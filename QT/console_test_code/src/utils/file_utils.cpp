#include "utils/file_utils.h"

#include <QDir>

#ifdef Q_OS_WIN
    #include "windows.h"
#endif

void CFileUtils::getDirFilesPath(const QString &destPath, QVector<QString> &files, const QString &ext, bool isRecursion/* = false*/)
{
    QFileInfoList fileInfos;
    getDirFilesInfo(destPath,fileInfos,isRecursion);
    for (auto fileInfo : fileInfos)
    {
        if (!ext.isEmpty() && fileInfo.suffix() != ext)
            continue;
        files.push_back(fileInfo.filePath());
    }
}

void CFileUtils::getDirFilesInfo(const QString &destPath, QFileInfoList &files, bool isRecursion/* = false*/)
{
    QDir destDir(destPath);
    if (!destDir.exists())
    {
        qWarning() << "error,destPath is not exist, destPath = " << destPath ;
        return;
    }
    files.append(destDir.entryInfoList(QDir::Files));
    if (isRecursion)
    {
        QFileInfoList dirs = destDir.entryInfoList(QDir::Dirs | QDir::NoDot | QDir::NoDotDot);
        for (auto dirInfo : dirs)
        {
            getDirFilesInfo(dirInfo.filePath(),files,true);
        }
    }
}

void CFileUtils::getDirFilesFolders(const QString &destPath, QVector<QFileInfo> &files, QVector<QString> &folders)
{
    QFileInfoList itemList;
    getDirFilesFolders(destPath,itemList);
    for (auto item : itemList)
    {
        if (item.isDir())
            folders.push_back(item.filePath());
        else if (item.isFile())
            files.push_back(item);
    }
}

void CFileUtils::getDirFilesFolders(const QString &destPath, QFileInfoList &files)
{
    QDir destDir(destPath);
    if (!destDir.exists())
    {
        qWarning() << "error,destPath is not exist, destPath = " << destPath ;
        return;
    }
    files.append(destDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot));
}

qint64 CFileUtils::getDiskFreeSpaceSize(const QString &destPath)
{
    qint64 mb = (1024*1024);
    qint64 freeSpaceSize = 0;
    #ifdef Q_OS_WIN
        DWORDLONG i64FreeBytesToCaller = 0;
        DWORDLONG i64TotalBytes = 0;
        DWORDLONG i64FreeBytes = 0;
        LPCWSTR wpath = (LPCWSTR)destPath.utf16();
        GetDiskFreeSpaceEx(wpath, (PULARGE_INTEGER)&i64FreeBytesToCaller,
                (PULARGE_INTEGER)&i64TotalBytes, (PULARGE_INTEGER)&i64FreeBytes);
        freeSpaceSize = i64FreeBytes;
    #elif defined(Q_OS_UNIX) && !defined(Q_OS_WASM)
        struct statfs diskInfo;
        const char* path = destPath.toUtf8().data();
        statfs(path, &diskInfo);
        unsigned long long blocksize                = diskInfo.f_bsize;	//每个block里包含的字节数
        unsigned long long totalsize                = blocksize * diskInfo.f_blocks; 	//总的字节数，f_blocks为block的数目
        unsigned long long freeDisk                 = diskInfo.f_bfree * blocksize;	//剩余空间的大小
        unsigned long long availableDisk            = diskInfo.f_bavail * blocksize; 	//可用空间大小
        freeSpaceSize = availableDisk;
    #endif

        return freeSpaceSize / mb;
}

int CFileUtils::copyFolder(const QString &srcPath, const QString &destPath)
{
    int ret = 0;
//    QVector<QString> files;
//    getDirFilesPath(QString::fromStdWString(srcPath),files,"",true);

//    for (auto item : files)
//    {
//        QString path = item.toStdWString();
//        if (wcsncmp(path.data(), srcPath.data(), srcPath.length()) != 0)
//            continue;

//        QString dest_file = destPath + path.substr(srcPath.length());
//        if (!CFileUtils::CopyFile(path, dest_file))
//        {
//            qInfo() << "CopyFolder, srcPath: " << CTextConverter::wStringToString(srcPath)
//                << ", destPath: " << CTextConverter::wStringToString(destPath);
//            return ret;
//        }
//    }
    return ret;
}

int CFileUtils::renameFolder(const QString &srcPath, const QString &destPath)
{
    return 0;
}

int CFileUtils::moveFolder(const QString &srcPath, const QString &destPath)
{
    return 0;
}

bool CFileUtils::copyFile(const QString &srcPath, const QString &destPath)
{
//    if (!CFileUtils::IsFile(srcPath))
//        return false;

//    CFileUtils::mkdirIfFilePathNotExists(destPath.c_str());

//    QFile::copy(QString::fromStdWString(srcPath), QString::fromStdWString(destPath));
    return false;
}

bool CFileUtils::renameFile(const QString &srcPath, const QString &destPath)
{
//    if (!CFileUtils::IsFile(srcPath))
//        return false;

//    if (CFileUtils::IsFile(destPath))
//        CFileUtils::unlinkFile(destPath);
//    else
//        CFileUtils::mkdirIfFilePathNotExists(destPath);

//    return QFile::rename(QString::fromStdWString(srcPath), QString::fromStdWString(destPath));
    return false;
}

bool CFileUtils::moveFile(const QString &srcPath, const QString &destPath)
{
    return false;
}


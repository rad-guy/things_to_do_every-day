#pragma once
#include "helper/utils_helper.h"
#include <QDebug>

using namespace Utils;

void CSystemHelper::testSystemUtils()
{
    // 测试获取 本机 ip
    QString ipAddress = CSystemUtils::getLocalIp();
    qInfo() << "get ip = " << ipAddress;

    //
}

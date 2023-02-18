#pragma once

// 此头文件用于 main.cpp 引用，继承各个 helper
#include <QDebug>

#include "helper/part_helper.h"
#include "helper/module_helper.h"
#include "helper/utils_helper.h"


class CMainHelper
{
public:
    static void excutePart01();
    static void excuteUtils01();
    static void excuteUtils02();

};

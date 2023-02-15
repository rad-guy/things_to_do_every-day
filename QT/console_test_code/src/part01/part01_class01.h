#pragma once
#include <string>

class CPart01Class01
{
public:
	CPart01Class01() {};
	~CPart01Class01() {};

    // 用于测试 QStingList
    void testQStringList();
    // 用于测试 str 编码转换
    void testStrTranscode();
    // 用于测试 qt api 返回路径
    void testAllPath();
    // 测试 忘记返回引起崩溃 linux系统。
    std::string testNoReturn();

};

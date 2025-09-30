#pragma once

#include <string>
#include <vector>
#include <map>
using namespace std;

class CPart01Class05
{
public:
	CPart01Class05() {};
	~CPart01Class05() {};


public:

	// 测试构造函数初始化顺序函数
	void testConstructInitOrder();
	// 测试AES解密
	void testAES16pck7();
	void testAES16pck5();

	void testAES32pck7();
	void testAES32pck5();

};

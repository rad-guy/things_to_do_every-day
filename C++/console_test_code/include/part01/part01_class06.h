#pragma once

#include <string>


using namespace std;

//std::string g_test_str21 = "test";
//int g_test_int21 = 21;


class TestBase
{
public:
	TestBase(std::string a, int b)
		: m_sTestStr(a)
		, m_iTestInt(b)
	{

	};
	~TestBase() {};

public:
	std::string m_sTestStr;
	int m_iTestInt;
};

class Derived : public TestBase
{
public:
	Derived()
		: TestBase("test", 21)
	{};
	~Derived() {};
};
class CB
{
public:
	CB(int i)
		: mi(i)
	{};
	~CB() {};

	int mi;
};

class CAA
{
public:
	CAA(const std::string& str)
		: ma(str)
	{
		mb = new CB(10);
	};
	~CAA() { delete mb; };
	std::string ma;
	CB* mb;
};

class AA
{
public:
	AA(int _size) : size(_size)
	{
		data = new int[size];
	} // 假如其中有一段动态分配的内存 
	AA() {};
	//AA(const AA& _A) : size(_A.size)
	//{
	//	data = new int[size];
	//} // 深拷贝 
	~AA()
	{
		delete[] data;
	} // 析构时释放资源
private:
	int* data;
	int size;
};

struct Struct1
{
	string name_;
	int age_;
};

class CPart01Class06
{
public:
	CPart01Class06() {};
	~CPart01Class06() {};

	void testClass();
	void testDeepCopy();

	void testStruct(const Struct1& s);
	void testEndWith();

	void testStdBindFunc();
public:

};

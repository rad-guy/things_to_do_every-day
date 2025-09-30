#include "part01/part01_class06.h"

#include <iostream>




void CPart01Class06::testClass()
{
	Derived derived;
	std::cout << derived.m_sTestStr << std::endl;
	std::cout << derived.m_iTestInt << std::endl;
}



void println(const CAA& ca)
//void println(CA ca)
{
	std::cout << ca.ma << "  " << ca.mb->mi << std::endl;
}


void  CPart01Class06::testDeepCopy()
{
	CAA testa = CAA("hello");
	CAA testb = testa;
	println(testb);

	//AA a(5); // 这次就没问题了 
	//AA b = a;
	string ss = "";
}

void CPart01Class06::testStruct(const Struct1& s)
{
	std::cout << s.name_ << "  " << s.age_ << std::endl;
}

bool test_ends_with(const std::wstring& wstr, const std::wstring& ext)
{
	size_t str_len = wstr.length();
	size_t suffix_len = ext.length();

	if (str_len < suffix_len) {
		return false;
	}

	return wstr.compare(str_len - suffix_len, suffix_len, ext) == 0;

	if (wstr.length() < ext.length())
		return false;
	size_t pos = wstr.find_last_of(ext);
	if (wstr.length() != pos + ext.length())
		return false;

	return true;
}

void CPart01Class06::testEndWith()
{
	wstring wstr = L"123456.zip.jpg.zip.text.zip";
	wstring ext = L".zip";
	bool ret = test_ends_with(wstr, ext);
	std::cout << " end_with,ret = " << ret << std::endl;

}

//#define STDBIND_TRYCATCH_FUNC(func) auto bind_func = std::bind(&func, \
//	this, placeholders::_1, placeholders::_1, placeholders::_1)       \
//	try																  \
//	{
//		bind_func()
//	}
//	catch(...)
//	{
//
//	}

//class CTestBind
//{
//public:
//	CTestBind() = default;
//	~CTestBind() = default;
//
//	void testbind(string str1, int int2, bool bool3)
//	{
//		printf("bindfuncrun = %s%d%d\n", str1, int2, bool3);
//	}
//};

//class AA
//{
//protected:
//	virtual void test() { std::cout << "test AA" << std::endl; } ;
//};
//
//class BB : public AA
//{
//protected:
//	virtual void test() { std::cout << "test BB" << std::endl; };
//};

void CPart01Class06::testStdBindFunc()
{
	//BB* bb = new BB();
	//AA* aa = dynamic_cast<AA*>(bb);
	//aa->test();
	//
}

#include "part01/part01_class04.h"
#include <iostream>


// 函数模板
//// 两个整形交换函数
//void swapInt(int &a,int &b)
//{
//	swap(a, b);
//}
//void swapFloat(float& a, float b)
//{
//	swap(a, b);
//}
//// template 函数模板
//template<typename T> //声明一个模板，告诉编辑器后面代码中的 T 不要报错，T 是一个通用数据类型
//void mySwap(T& a, T& b)
//{
//	swap(a, b);
//}

// 普通函数与函数模板调用规则
//void myPrint(int a,int b)
//{
//	cout << "调用普通函数" << endl;
//};
//template <typename T>
//void myPrint(T a,T b)
//{
//	cout << "调用模板函数" << endl;
//}
//template <typename T>
//void myPrint(T a, T b,T c)
//{
//	cout << "调用重载模板函数" << endl;
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	myPrint(a ,b);
//	// 通过空模板参数列表，强制调用函数模板
//	myPrint<>(a, b);
//	myPrint(a, b, 100);
//	char c = 'a';
//	char d = 'b';
//	myPrint(c,d);
//}
// 特定数据类型用具体化方式做特殊实现
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	};
//	string m_Name;
//	int m_Age;
//};
//template<typename T>
//bool myCompare(T& a, T& b)
//{
//	// 第一种方式是运算符重载，当传入 Person 对象时 可以进行比较
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//// 利用具体化 Person 的版本具体实现，具体化优先调用
//template<> bool myCompare(Person& p1, Person& p2)
//{
//	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//void test02()
//{
//	Person p1("Tom", 10);
//	Person p2("Tom", 10);
//	bool ret = myCompare(p1, p2);
//	if (ret)
//	{
//		cout << "p1 == p2" << endl;
//	}else
//	{
//		cout << "p1 != p2" << endl;
//	}
//}

// 类模板
//template<class NameType,class AgeType>
//class Person
//{
//public:
//	Person(NameType name, AgeType age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	void showPerson()
//	{
//		cout << "name:" << this->m_Name << " age:" << this->m_Age << endl;
//	}
//	NameType m_Name;
//	AgeType m_Age;
//};
//void test03()
//{
//	Person<string, int> p1("孙悟空", 500);
//	p1.showPerson();
//}

// Lambda 表达式
// 捕获列表
//class Lam
//{
//public:
//	int	i_ = 1;
//	void func(int x,int y)
//	{
//		//auto x1 = [] {return i_; }; // error 没有捕获外部变量，i_ 未定义
//		auto x2 = [=] {return i_ + x + y; }; // OK,捕获所有外部变量
//		cout << x2() << endl;  // 4
//		auto x3 = [&] { return i_ + x + y; }; // OK，捕获所有外部变量
//		cout << x3() << endl;  // 4
//		auto x4 = [this] { return i_; }; // OK，捕获this指针
//		cout << x4() << endl; // 1
//		//auto x5 = [this] { return i_ + x + y; }; // error，没有捕获x、y
//		auto x6 = [this, x, y] { return i_ + x + y; };  // OK，捕获this指针、x、y
//		cout << x6() << endl;
//		auto x7 = [this] { return ++i_; }; // OK，捕获this指针，并修改成员的值
//		cout << x7() << endl; // 2
//	}
//	
//};

//// 函数对象类
//std::function<int(int)> Functional;
//
//// 普通函数
//int TestFunc(int a)
//{
//	return a;
//}
//// Lambda表达式
//auto lambda = [](int a)->int { return a; };
//// 仿函数(functor)
//class Functor
//{
//public:
//	int operator()(int a)
//	{
//		return a;
//	}
//};
//// 1.类成员函数
//// 2.类静态函数
//class TestClass
//{
//public:
//	int ClassMember(int a) { return a; }
//	static int StaticMember(int a) { return a; }
//};

//class CountEven
//{
//	int& count_;
//public:
//	CountEven(int& count) : count_(count) {}
//	void operator()(int val)
//	{
//		if (!(val & 1))       // val % 2 == 0
//		{
//			++count_;
//		}
//	}
//};

void CPart01Class04::testLambda()
{

	//int a = 1, b = 2;
	////swapInt(a, b);
	//// 利用函数模板交换
	//// 两种方式使用函数模板
	//// 1.自动类型推导
	//mySwap(a, b);
	//// 2.显示指定类型
	//mySwap<int>(a, b);
	//cout << a << b << endl;
	//float aa = 1.4;
	//float bb = 2.5;
	//swapFloat(aa, bb);
	//cout << aa << " " << bb << endl;

	/*test01();*/
	/*test02();*/
	//test03();

	// Lambda 表达式
	// 省略 捕获列表和函数选项
	//auto lma1 = [](int a) -> int {return a + 1; };
	//cout << lma1(1) << endl; // 2
	//// 省略 返回值定义
	//auto lma2 = [](int a){return a + 1; };
	//cout << lma2(2) << endl; // 3
	//auto lma3 = []() {return 1; };
	//cout << lma3() << endl;  // 1
	//// 省略形参列表，省略参数列表
	//auto lma4 = []{return 'a'; };
	//cout << lma4() << endl; // a

	// 测试 class Lam 效果
	//Lam lam;
	//lam.func(1, 2);

	// 捕获列表
	//int a = 0, b = 1;
	////auto f1 = [] { return a; }; // error，没有捕获外部变量
	//auto f2 = [&] { return ++a; }; // OK，捕获所有外部变量，并对a执行自加运算 此时改变 a 为 1
	//cout << f2() << endl; // 1
	//auto f3 = [=] { return a; };   // OK，捕获所有外部变量，并返回a
	//cout << f3() << endl; // 1
	////auto f4 = [=] { return a++; }; // error，a是以复制方式捕获的，无法修改
	////auto f5 = [a] { return a + b; }; // error，没有捕获变量b
	//auto f6 = [a, &b] { return a + (++b); };  // OK，捕获a和b的引用，并对b做自加运算 f2 的引用已经改变了 a 的值 此时改变 b 为 2
	//cout << f6() << endl; // 3
	//auto f7 = [=, &b] { return a + (++b); };  // OK，捕获所有外部变量和b的引用，并对b做自加运算 此时 改变 b 为 3
	//cout << f7() << endl;  // 4
	// 捕获延迟调用
	//int a = 0;
	//auto f = [=] { return a; };     // 按值捕获外部变量
	////auto f = [&] { return a; };     // 按值捕获外部变量
	//a += 1;                         // a被修改了
	//std::cout << f() << std::endl;  // 如果是按值捕获，输出 捕获时复制的 值 即 0
	////std::cout << f() << std::endl;  // 如果是按引用捕获，输出 此的 值 即 1
	// 修改按值捕获的外部变量
	//int a = 0;
	////auto f1 = [=] { return a++; };             // error，修改按值捕获的外部变量
	//auto f2 = [=]() mutable { return ++a; };  // OK，mutable
	//cout << f2() << endl; // 1
	//cout << a << endl;  // 0

	//// 普通函数
	//Functional = TestFunc;
	//int result = Functional(10);
	//cout << "普通函数：" << result << endl;
	//// Lambda表达式
	//Functional = lambda;
	//result = Functional(20);
	//cout << "Lambda表达式：" << result << endl;
	//// 仿函数
	//Functor testFunctor;
	//Functional = testFunctor;
	//result = Functional(30);
	//cout << "仿函数：" << result << endl;
	//// 类成员函数
	//TestClass testObj;
	//Functional = std::bind(&TestClass::ClassMember, testObj, std::placeholders::_1);
	//result = Functional(40);
	//cout << "类成员函数：" << result << endl;
	//// 类静态函数
	//Functional = TestClass::StaticMember;
	//result = Functional(50);
	//cout << "类静态函数：" << result << endl;


	// Lambda类型
	//std::function<int(int)>  f1 = [](int a) { return a; };
	//std::function<int(void)> f2 = std::bind([](int a) { return a; }, 123);
	//cout << f1(1) << endl;  // 1
	//cout << f2() << endl;   // 123 无法传参，bind 已经传过参了

	// 对于没有捕获任何变量的 lambda 表达式，还可以被转换成一个普通的函数指针：
	//using func_t = int(*)(int);
	//func_t f = [](int a) { return a; };
	//cout << f(123) << endl;
	// 
	//typedef void(*Ptr)(int*);
	//int a = 12;
	//int* dd = &a;
	//cout << *dd << endl;
	//Ptr p = [](int* p) {delete p; };  // 正确，没有状态的lambda（没有捕获）的lambda表达式可以直接转换为函数指针
	//cout << *dd << endl;
	//Ptr p1 = [&](int* p) {delete p; };  // 错误，有状态的lambda不能直接转换为函数指针

	// 获取偶数
	//std::vector<int> v = { 1, 2, 3, 4, 5, 6,7 };
	//int even_count = 0;
	//for_each(v.begin(), v.end(), CountEven(even_count));
	//std::cout << "The number of even is " << even_count << std::endl;
	// Lambda 表达式
	//std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	//int even_count = 0;
	//for_each(v.begin(), v.end(), [&even_count](int val)
	//	{
	//		if (!(val & 1))  // val % 2 == 0
	//		{
	//			++even_count;
	//		}
	//	});
	//std::cout << "The number of even is " << even_count << std::endl;
}


// 函数指针
//int (*f)(int x, int y);
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}

// 指针函数指针
//int c;
//int* (*f)(int x, int y);
//int* add(int x, int y)
//{
//	c = x + y;
//	return &c;
//		
//}
//int* sub(int x, int y)
//{
//	c = x - y;
//	return &c;
//}



void CPart01Class04::testFunc()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d", i);
	//}
	// 函数指针调用
	//f = add; // 函数指针 加不加 取地址符 都一样
	//printf("1 + 2 = %d \n", (*f)(1, 2));
	//f = &sub;
	//printf("1 - 2 = %d \n", (*f)(1, 2));

	// 指针函数指针调用
	//f = add;
	//printf("1 + 2 = %d \n", *(*f)(1, 2));
	//f = sub;
	//printf("1 - 2 = %d \n", *(*f)(1, 2));
}

#define VDEV_CLOSE      (1 << 0)
#define VDEV_PAUSE      (1 << 1)
#define VDEV_COMPLETED  (1 << 2)
#define VDEV_CLEAR      (1 << 3)

void CPart01Class04::testBitwise()
{
	unsigned int result1 = 0x00000001 | 0x00000002;
	unsigned int result2 = 0xFF00 | 0x00FF;


	int state = 0;
	// |= 并
	state |= VDEV_CLOSE;
	state |= VDEV_PAUSE;
	state |= VDEV_COMPLETED;
	state |= VDEV_CLEAR;
	// &=~ 取反 按位与 赋值 清空 VDEV_COMPLETED 位
	state &= ~VDEV_COMPLETED;
	// &= 按位与 赋值
	state &= VDEV_PAUSE;

	//for (int i = 0; i < 256; i++)
	//{
	//	int dd = i & 255;
	//	printf("i = %d,dd = %d.\n",i,dd);
	//}
	int ret = 0 & 255;
	int res = 0 | 255;
	printf("任意数与0 按位与 为0,与0 按位或 为本身\n");
	int ret1 = 5 & 255;
	int res1 = 5 | 255;
	ret1 = 210 & 330;
	res1 = 210 | 330;
	res1 = 210 ^ 330;
	// 判断某一位是0还是1
	int m = 3;
	int num = 11;
	if (1 << m & num)
		printf("1 << m & 判断某一位是0还是1 , num 的从左向右第m位是 1 \n");
	else 
		printf("1 << m & 判断某一位是0还是1 , num 的从左向右第m位不是 1 \n");

	// 任意数与0异或保持不变
	int num1 = 222;
	int ret2 = num1 ^ 0;
	printf("任意数与0异或保持不变 , 222 ^ 0 = %d \n",ret2);

	// 任意数与本身异或为0
	int num2 = 111;
	int ret3 = num2 ^ num2;
	printf("任意数与本身异或为0 , ret3 ^ ret3 = %d \n", ret3);

	// 任意数与本身 按位与 为本身
	int ret4 = 255 & 255;
	int ret5 = 255 | 255;
	printf("任意数与本身 按位与 为本身，任意数与本身 按位或 为本身 \n");

	//int ret0 = 0 & 255;
}

#include <thread>


void download1()
{
	std::cout << "开始下载第一个视频..." << std::endl;
	for (int i = 0; i < 100; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout << "第一个视频下载进度:" << i << endl;
	}
	cout << "第一个视频下载完成..." << endl;
}
void download2()
{
	cout << "开始下载第二个视频..." << endl;
	for (int i = 0; i < 100; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
		cout << "第二个视频下载进度:" << i << endl;
	}
	cout << "第二个视频下载完成..." << endl;
}
void process()
{
	cout << "开始处理两个视频" << endl;
}
//class CTestStdThread
//{
//public:
//
//
//private:
//	std::thread m_thread;
//};

#include <array>
void show() { cout << "hello cplusplus!" << endl; }
void CPart01Class04::testStdThread()
{
	//cout << "主线程开始运行\n";
	//std::thread d2(download2);
	//download1();
	//d2.join();
	//process();

	thread th = thread(show);
	th.detach();
	cout << "是否可以join:" << th.joinable() << endl;
	//开3个线程
	array<thread, 3>  threads = { thread(show), thread(show), thread(show) };
	for (int i = 0; i < 3; i++)
	{
		cout << threads[i].joinable() << endl;
		//判断线程是否可以join
		threads[i].join();
		//主线程等待当前线程执行完成再退出
	}

}

void CPart01Class04::testStdSubstr()
{
	//string url = "https://fs.iclass30.com/znbk/resources/static_resource/physical_map/wuli_xt_gx_2.png?x-oss-process%3Dimage%2Fcrop%2Cx_0%2Cy_0%2Cw_300%2Ch_341";
	string url = "https://fs.iclass30.com/znbk/resources/static_resource/physical_map/wuli_xt_gx_2.png";
	string file_ext = "";
	int param_pos = url.find_first_of("?");
	int ext_pos = url.find_last_of(".") + 1;
	if (param_pos != url.npos && param_pos > ext_pos)
	{
		file_ext = url.substr(ext_pos, param_pos - ext_pos);
	}
	else
	{
		file_ext = url.substr(ext_pos);
	}
}


#include <Windows.h>
#include <RestartManager.h>
#include <stdio.h>
#pragma comment(lib, "Rstrtmgr.lib")
void CPart01Class04::testReleaseOccupyedFile()
{
	DWORD dwSession = 0;
	WCHAR szSessionKey[CCH_RM_SESSION_KEY + 1];
	DWORD dwError = RmStartSession(&dwSession, 0, szSessionKey);
	if (dwError != ERROR_SUCCESS)
	{
		wprintf(L"RmStartSession Start Error, ErrorCode: %d\n", dwError);
	}
	//你的dll 绝对路径
	PCWSTR pszFile = L"D:/Program Files (x86)/Datedu/znbk/Log/bkservice/20231007083442.log";
	dwError = RmRegisterResources(dwSession, 1, &pszFile, 0, NULL, 0, NULL);
	if (dwError != ERROR_SUCCESS)
	{
		wprintf(L"RmRegisterResources for File %ls Error, ErrorCode: %d\n", pszFile, dwError);
	}

	DWORD dwReason = 0;
	UINT i = 0;
	UINT nProcInfoNeeded = 0;
	UINT nProcInfo = 10;
	RM_PROCESS_INFO rgpi[10];
	memset(rgpi, 0, sizeof(rgpi));
	dwError = RmGetList(dwSession, &nProcInfoNeeded, &nProcInfo, rgpi, &dwReason);
	if (dwError != ERROR_SUCCESS)
	{
		wprintf(L"RmGetList Error, ErrorCode: %d\n", dwError);
	}

	if (nProcInfoNeeded == 0)
	{
		wprintf(L"This file is not in locked!");
	}

	for (i = 0; i < nProcInfo; i++)
	{
		wprintf(L"The locked file: %ls\n\n", pszFile);
		wprintf(L"Who lock this file:\n");
		wprintf(L"Name: \t%ls\n", rgpi[i].strAppName);
		wprintf(L"ID  : \t%d\n", rgpi[i].Process.dwProcessId);


		HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, rgpi[i].Process.dwProcessId);

		if (hProcess)
		{
			// 这个if语句是为了判断是否是某个程序的某个进程(因为一个程序可以有多个进程)
			FILETIME ftCreate, ftExit, ftKernel, ftUser;
			if (GetProcessTimes(hProcess, &ftCreate, &ftExit, &ftKernel, &ftUser)
				&& CompareFileTime(&rgpi[i].Process.ProcessStartTime, &ftCreate) == 0)
			{
				WCHAR sz[MAX_PATH] = { 0 };
				DWORD ProcPathMaxLength = MAX_PATH;
				if (QueryFullProcessImageNameW(hProcess, 0, sz, &ProcPathMaxLength) && ProcPathMaxLength <= MAX_PATH)
				{
					wprintf(L"Path: \t%ls\n", sz);
				}
			}

			wprintf(L"\n");
			CloseHandle(hProcess);
		}
	}

	RmEndSession(dwSession);

}
#include <atlconv.h>
#include <atlstr.h>

std::string W2A_WIN_ATL(const std::wstring& wsrc)
{
	std::string str;
	str = CW2A(wsrc.data(), CP_UTF8);
	return str;
}
#include <codecvt>
bool isUTF8(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
	try
	{
		converter.from_bytes(str);
		return true;
	}
	catch (const std::range_error&)
	{
		return false;
	}
}
void CPart01Class04::testSpeSpecialCharacter()
{
	CString inputCString = _T("²");
	//CString inputCString = _T("{\"sortid\":\"ppt_event\",\"event_name\":\"SlideShowNextSlide\",\"is_office\":\"0\",\"ppt_full_name\":\"C: / Users / xudeh / Desktop / y = ax².pptx\",\"ppt_width\":\"960\",\"ppt_height\":\"540\",\"slide_count\":\"1\",\"slide_index\":\"1\",\"animation_count\":\"0\",\"animation_index\":\"0\"}");
	string utf8_str = W2A_WIN_ATL(inputCString.GetString());
	int ret = testIsUtf_8String(utf8_str);
	bool res = isUTF8(utf8_str);
	bool is_utf8 = testIsUtf_8String(utf8_str);
	std::wstring wstr;
	wstr = CA2W(utf8_str.data(), CP_UTF8);

}

int isGBKString(const string& str)
{
	unsigned int nBytes = 0;//GBK可用1-2个字节编码,中文两个 ,英文一个
	unsigned char chr = 0;
	bool bAllAscii = true; //如果全部都是ASCII,
	for (int i = 0; i < str.size(); i++)
	{
		chr = str.at(i);
		if ((chr & 0x80) != 0 && nBytes == 0)
		{
			// 判断是否ASCII编码,如果不是,说明有可能是GBK
			bAllAscii = false;
		}
		if (nBytes == 0)
		{
			if (chr >= 0x80)
			{
				if (chr >= 0x81 && chr <= 0xFE)
					nBytes = +2;
				else
					return -1;
				nBytes--;
			}
		}
		else
		{
			if (chr < 0x40 || chr>0xFE)
				return -1;
			nBytes--;
		}//else end
	}

	if (nBytes != 0)
	{   //违返规则
		return -1;
	}
	if (bAllAscii)
	{
		//如果全部都是ASCII, 也是GBK
		return 1;
	}
	return 0;
}


bool STD_IsUTF81(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
	try
	{
		converter.from_bytes(str);
		return true;
	}
	catch (const std::range_error&)
	{
		return false;
	}
}
int CPart01Class04::testIsUtf_8String(const string& str)
{
	unsigned int nBytes = 0;//UFT8可用1-6个字节编码,ASCII用一个字节
	unsigned char chr = 0;
	bool bAllAscii = true, isUTF8 = false;
	for (int i = 0; i < str.size(); i++)
	{
		chr = str.at(i);
		if (nBytes == 0 && (chr & 0x80) != 0)
			bAllAscii = false;

		if (nBytes == 0)
		{
			//如果不是ASCII码,应该是多字节符,计算字节数
			if (chr >= 0x80)
			{
				if (chr >= 0xFC && chr <= 0xFD)
					nBytes = 6, isUTF8 = true;
				else if (chr >= 0xF8)
					nBytes = 5, isUTF8 = true;
				else if (chr >= 0xF0)
					nBytes = 4, isUTF8 = true;
				else if (chr >= 0xE0)
					nBytes = 3, isUTF8 = true;
				else if (chr >= 0xC0)
					nBytes = 2;
				else
					return -1;

				nBytes--;
			}
		}
		else
		{
			//多字节符的非首字节,应为 10xxxxxx
			if ((chr & 0xC0) != 0x80)
				return -1;
			//减到为零为止
			nBytes--;
		}
	}

	//违返UTF8编码规则
	if (nBytes != 0)
		return -1;

	//如果全部都是ASCII, 也是UTF8
	if (bAllAscii)
		return 1;

	// add by xdh at 10/30/23
	if (isUTF8) return 0;

	int is_gbk = isGBKString(str);
	if (is_gbk < 0)
		return 0;
	if (is_gbk == 0)
	{
		if (STD_IsUTF81(str)) return 0;
		else return -1;
	}

	return 1;
}

wstring stringToWString(const std::string& str)
{

	return wstring(CA2W(str.data()));

}
#ifdef WIN32
#define S_ISDIR(x)  (((x)&S_IFDIR)==S_IFDIR)
#define S_ISREG(x)  (((x)&S_IFREG)==S_IFREG)
#endif
int my_mkdirA(LPCSTR pDir)
{
	struct _stat64i32 stDir;
	wstring path = stringToWString(pDir);
	int ret = _wstat(path.data(), &stDir);

#ifdef WIN32
	if (ret == -1)
		return _wmkdir(path.data());
#endif

#ifdef UNIX
	if (ret == -1 && errno == ENOENT)
		return mkdir(pDir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
	else if (ret == 0)
	{
		int ret = S_ISDIR(stDir.st_mode);
		if (!ret)
		{
			wchar_t szTmpName[MAX_PATH] = { 0 };
			wsprintf(szTmpName, L"%s.bak", pDir);
			::_wrename(path.data(), szTmpName);
#ifdef WIN32
			return _wmkdir(path.data());
#endif

#ifdef UNIX
			return mkdir(pDir, 0755);
#endif
		}
		else
			return 0;
	}

	return -1;
}

int mkdirIfNotExists(LPCSTR path, bool recursive)
{
	if (!recursive)
		return my_mkdirA(path);

	char szPath[MAX_PATH] = { 0 },
		szActualPath[MAX_PATH] = { 0 },
		* pStart = szPath,
		* p = NULL;
	int len = 0, ret = 0;

	::strncpy(szPath, path, sizeof(szPath) - 1);
	szPath[sizeof(szPath) - 1] = '\0';

	while (*pStart != 0)
	{
		if (*pStart == '\\') *pStart = '/';
		pStart++;
	}
	pStart = szPath;

	if (*pStart == '/')
		len += _snprintf(szActualPath + len, sizeof(szActualPath) - len, "/");

	while ((p = ::strchr(pStart, '/')) != NULL)
	{
		*p = '\0';

		if (pStart && *pStart != '\0')
		{
			len += _snprintf(szActualPath + len, sizeof(szActualPath) - len, "%s", pStart);
			if (len < 3) szActualPath[len] = '/';
			ret = my_mkdirA(szActualPath);
			szActualPath[len++] = '/';

			if (ret != 0)
				return ret;
		}

		pStart = ++p;
	}

	if (pStart && *pStart != '\0')
	{
		len += _snprintf(szActualPath + len, sizeof(szActualPath) - len, "%s", pStart);

		ret = my_mkdirA(szActualPath);
		if (ret != 0)
			return ret;
	}

	return 0;
}

string getFilePath(const string& filepath)
{
	size_t pos = filepath.find_last_of("\\/");
	return (std::string::npos == pos) ? "" : filepath.substr(0, pos);
}
int mkdirIfFilePathNotExists(LPCSTR filepath)
{
	string dir = getFilePath(filepath);
	return mkdirIfNotExists(dir.c_str(),true);
}

int CPart01Class04::testLongShortPath()
{
	wstring wpath = L"\\\\?\\D:\\_cgi-bin_mmwebwx-bin_webwxgetmsgimg__&MsgID=5302397174540336766&skey=@crypt_791b3541_d50d9cef8079ead994d5e03f2cc7275c&mmweb_appid=wx_webfilehelper\\ttttttttttt\\11111111223.jpg";
	long     length = 0;
	TCHAR* buffer = NULL;
	length = GetShortPathName(wpath.data(), NULL, 0);
	buffer = new TCHAR[length];
	length = GetShortPathName(wpath.data(), buffer, length);
	if (length == 0)
		return -1;
	return 0;
}

int CPart01Class04::testWOpen()
{
	wstring url = L"C:/Users/xudeh/Desktop/新建示文稿.pptx";
	std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	std::string utf8url = convert.to_bytes(url);     // wstring => utf-8
	FILE* fp = NULL;
	fp = fopen(utf8url.c_str(), "rb");
	errno_t err = fopen_s(&fp, utf8url.c_str(), "rb, ccs=UTF-8");;
	if (fp)
	{
		fclose(fp);
	}

	wstring wpath = L"\\\\?\\..\\bin\\1111111111111111111111111111111111111111111111111111111111111_cgi-bin_mmwebwx-bin_webwxgetmsgimg__&MsgID=5302397174540336766&skey=@crypt_791b3541_d50d9cef8079ead994d5e03f2cc7275c&mmweb_appid=wx_webfilehelper.jpg";
	
	FILE* fout = _wfopen(wpath.data(), L"wb");
	if (fout)
	{

		std::fclose(fout);
	}


	return 0;
}

void CPart01Class04::testSubtractRect()
{
	RECT rect1 = { 0, 0, 1920, 1080 }; // 第一个矩形，left, top, right, bottom
	RECT rect2 = { 50, 50, 150, 150 }; // 第二个矩形

	RECT intersectRect;
	if (IntersectRect(&intersectRect, &rect1, &rect2)) {
		RECT diffRect;
		SubtractRect(&diffRect, &rect1, &rect2);

		printf("Difference Rect: Left=%d, Top=%d, Right=%d, Bottom=%d\n",
			diffRect.left, diffRect.top, diffRect.right, diffRect.bottom);
	}
	else {
		printf("Rectangles do not intersect.\n");
	}
}

std::map<std::string, std::string> CPart01Class04::s_mapTest = {};
void CPart01Class04::testMap()
{
	s_mapTest.insert(make_pair("11", "22"));
	string dd = s_mapTest.at("11");
}


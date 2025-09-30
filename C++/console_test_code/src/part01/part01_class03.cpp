#include "part01/part01_class03.h"
#include <iostream>
#include <fstream>
#include <map>
#include <tchar.h>


void CPart01Class03::testGetIpStrHeader()
{
	string ip = "192.168.1.110";
	unsigned char* val = (unsigned char*)&(ip);
	if (val[0] == 192)
	{
		cout << "测试获取 ip 第一端数据，可以获取";
	}
}

void CPart01Class03::testTempVarNewPoint()
{
	map<string, CTestNew> mapCT;
	for (int i = 0; i < 100; i++)
	{
		//CTestNew test_new;
		//mapCT.insert(make_pair(to_string(i), test_new));
	};
	cout << "测试在临时变量中 new 一指针，在析构中销毁，然后这个变量保存到 map 中，程序崩溃" << endl;;
}

string get_string_addr()
{
	string str = "test";
	int addr = (int)&str;
	cout << "The temp variable address is " << addr << endl;
	return str;
}

void CPart01Class03::testTempVariableReturn()
{
	string&& target_addr = get_string_addr();
	int addr = (int)&target_addr;
	cout << "The returned variable address is " << addr << endl;;
}

void CPart01Class03::testReadFile()
{

    ifstream ifs;
    ifs.open("aaa.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    };
    // 第一种读取方式  一次一个字节
    char buf[1024] = { 0 };
    while (ifs >> buf)
    {
        cout << buf << endl;
    };
    ifs.close();
    // 输出
    // 鏂囦欢鍚 ? 澶у皬, 璺緞
    // castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    // 鏂囦欢鍚 ? 澶у皬, 璺緞
    // localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    // 鏂囦欢鍚 ? 澶у皬, 璺緞
    // app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png
    
    
    
    // 第二种读取方式  一次一行中的一个字节
    char buf1[1024] = { 0 };
    ifstream ifs1;
    ifs1.open("aaa.txt", ios::in);
    while (ifs1.getline(buf1, sizeof(buf1)))
    {
        cout << buf1 << endl;
    };
    ifs1.close();
    // 输出
    /*鏂囦欢鍚 ? 澶у皬, 璺緞
    castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    鏂囦欢鍚 ? 澶у皬, 璺緞
    localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    鏂囦欢鍚 ? 澶у皬, 璺緞
    app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png*/
    
    
    // 第三种读取方式 一次一行
	string buffer;
    ifstream ifs2;
    ifs2.open("aaa.txt", ios::in);
	while (getline(ifs2, buffer))
	{
		cout << buffer << endl;
	};
    ifs2.close();
    // 输出
    /*鏂囦欢鍚 ? 澶у皬, 璺緞
    castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    鏂囦欢鍚 ? 澶у皬, 璺緞
    localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    鏂囦欢鍚 ? 澶у皬, 璺緞
    app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png*/
    
    
    // 第四种读取方式
    char c;
    ifstream ifs3;
    ifs3.open("aaa.txt", ios::in);
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    };
    ifs3.close();
    // 输出
    //鏂囦欢鍚 ?
    
    // 上面四种是分段获取打印的，下面可以获取文本中所有字符，保存到字符串中
    ifstream ifs4;
    ifs4.open("aaa.txt", ios::in);
	istreambuf_iterator<char> beg(ifs4), end;
	string ifsStr(beg, end);
	cout << ifsStr << endl;
	//关闭文件
	ifs4.close();
    // 输出
    /*鏂囦欢鍚 ? 澶у皬, 璺緞
    castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    鏂囦欢鍚 ? 澶у皬, 璺緞
    localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    鏂囦欢鍚 ? 澶у皬, 璺緞
    app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png*/
    

}

class Person
{
public:
	char m_Name[64];
	int m_Age;
};
// 类以字符流的方式写入文件
void testWriteFileInStream()
{
    ofstream ofs("person.txt", ios::out | ios::binary); // 这样也可以的
    //ofs.open("person.txt", ios::out | ios::binary);
    Person p = { "张三",18 };
    ofs.write((const char*)&p, sizeof(p));
    ofs.close();
};
// 类以字符流的方式写入文件
void testReadFileInStream()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
	};
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
	ifs.close();
}

void CPart01Class03::testWriteClassInStream()
{
	testWriteFileInStream();
	testReadFileInStream();
}

void CPart01Class03::testStrcpm()
{
	char tmp[20];
	int result;

	char string1[] = "A";
	char string2[] = "a";
	// Case sensitive
	printf("Compare strings:\n%s\n%s\n\n", string1, string2);
	result = strcmp(string1, string2);
	if (result > 0)
		strcpy_s(tmp, _countof(tmp), "greater than");
	else if (result < 0)
		strcpy_s(tmp, _countof(tmp), "less than");
	else
		strcpy_s(tmp, _countof(tmp), "equal to");
	printf("   strcmp:   String 1 is %s string 2\n", tmp);

	// Case insensitive (could use equivalent _stricmp)
	result = _stricmp(string1, string2);
	if (result > 0)
		strcpy_s(tmp, _countof(tmp), "greater than");
	else if (result < 0)
		strcpy_s(tmp, _countof(tmp), "less than");
	else
		strcpy_s(tmp, _countof(tmp), "equal to");
	printf("   _stricmp:  String 1 is %s string 2\n", tmp);

	_TCHAR arr[20];
	printf("sizeof(arr) = %zu bytes\n", sizeof(arr));
	printf("_countof(arr) = %zu elements\n", _countof(arr));
}


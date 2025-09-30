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
		cout << "���Ի�ȡ ip ��һ�����ݣ����Ի�ȡ";
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
	cout << "��������ʱ������ new һָ�룬�����������٣�Ȼ������������浽 map �У��������" << endl;;
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
        cout << "�ļ���ʧ��" << endl;
        return;
    };
    // ��һ�ֶ�ȡ��ʽ  һ��һ���ֽ�
    char buf[1024] = { 0 };
    while (ifs >> buf)
    {
        cout << buf << endl;
    };
    ifs.close();
    // ���
    // 文件� ? 大小, 路径
    // castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    // 文件� ? 大小, 路径
    // localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    // 文件� ? 大小, 路径
    // app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png
    
    
    
    // �ڶ��ֶ�ȡ��ʽ  һ��һ���е�һ���ֽ�
    char buf1[1024] = { 0 };
    ifstream ifs1;
    ifs1.open("aaa.txt", ios::in);
    while (ifs1.getline(buf1, sizeof(buf1)))
    {
        cout << buf1 << endl;
    };
    ifs1.close();
    // ���
    /*文件� ? 大小, 路径
    castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    文件� ? 大小, 路径
    localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    文件� ? 大小, 路径
    app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png*/
    
    
    // �����ֶ�ȡ��ʽ һ��һ��
	string buffer;
    ifstream ifs2;
    ifs2.open("aaa.txt", ios::in);
	while (getline(ifs2, buffer))
	{
		cout << buffer << endl;
	};
    ifs2.close();
    // ���
    /*文件� ? 大小, 路径
    castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    文件� ? 大小, 路径
    localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    文件� ? 大小, 路径
    app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png*/
    
    
    // �����ֶ�ȡ��ʽ
    char c;
    ifstream ifs3;
    ifs3.open("aaa.txt", ios::in);
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    };
    ifs3.close();
    // ���
    //文件� ?
    
    // ���������Ƿֶλ�ȡ��ӡ�ģ�������Ի�ȡ�ı��������ַ������浽�ַ�����
    ifstream ifs4;
    ifs4.open("aaa.txt", ios::in);
	istreambuf_iterator<char> beg(ifs4), end;
	string ifsStr(beg, end);
	cout << ifsStr << endl;
	//�ر��ļ�
	ifs4.close();
    // ���
    /*文件� ? 大小, 路径
    castview.png, 1976, E : \Project\code\interact\build\Debug\skin\airplay\image\castview.png
    文件� ? 大小, 路径
    localview_hot.png, 1993, E : \Project\code\interact\build\Debug\skin\airplay\image\localview_hot.png
    文件� ? 大小, 路径
    app_bookshelf.png, 8066, E : \Project\code\interact\build\Debug\skin\c30_desktop\desktop\images\app_bookshelf.png*/
    

}

class Person
{
public:
	char m_Name[64];
	int m_Age;
};
// �����ַ����ķ�ʽд���ļ�
void testWriteFileInStream()
{
    ofstream ofs("person.txt", ios::out | ios::binary); // ����Ҳ���Ե�
    //ofs.open("person.txt", ios::out | ios::binary);
    Person p = { "����",18 };
    ofs.write((const char*)&p, sizeof(p));
    ofs.close();
};
// �����ַ����ķ�ʽд���ļ�
void testReadFileInStream()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
	};
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������" << p.m_Name << "���䣺" << p.m_Age << endl;
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


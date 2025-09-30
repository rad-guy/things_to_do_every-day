#include "test/test-memory.h"

#include <iostream>
#include <map>
using namespace std;

typedef map<string, string> MapData;
class CM1
{

};

class CM2
{
	void* pointer;
};

class CM3
{
public:
	virtual void test() = 0;
};

class CM4 : public CM3
{
	virtual void test() { };
private:
	char c:1;
};

class CM5
{
public:
	virtual void test() = 0;

	MapData m_mapData;
};

class CM6 : public CM5
{
public:
	virtual void test() { };
	char c : 1;
};

class CMT
{
public:
	virtual void test() { };
	int i;
};

class CM7 : public CM5
{
public:
	virtual void test() { };
	CMT t;
};

void CMemory01::testMemory()
{
	cout << "���� size = " << sizeof(CM1) << endl;
	cout << "map size = " << sizeof(MapData) << endl;
	cout << "��Ա������һ��ָ����� size = " << sizeof(CM2) << endl;
	cout << "�����麯������ size = " << sizeof(CM3) << endl;
	cout << "�̳нӿ��ຬ�г�Ա����char���� size = " << sizeof(CM4) << endl;
	cout << "�̳к���map�ӿ��ಢ���г�Ա����char���� size = " << sizeof(CM6) << endl;
	cout << "�̳к���map�ӿ��ಢ���г�Ա����CM5���� size = " << sizeof(CM7) << endl;
}
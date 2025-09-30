#include <string>
#include <vector>
using namespace std;

class CA
{
public:
	CA() {};
	~CA() {};
};
class CTestNew
{
public:
	CTestNew() : m_pCa(NULL) { m_pCa = new CA(); };
	~CTestNew()
	{
		if (m_pCa) delete m_pCa; m_pCa = NULL;
	};

private:
	CA* m_pCa;
};

class CPart01Class03
{
public:
	CPart01Class03() {};
	~CPart01Class03() {};

	void testGetIpStrHeader();
	// 测试临时变量中 new 一个指针
	void testTempVarNewPoint();

	// 测试 临时变量返回 是否会拷贝构造
	void testTempVariableReturn();

	// 测试读取文件的各种方式
	void testReadFile();

	// 测试把类变成字符流写入文件，并读出来
	void testWriteClassInStream();

	// 测试 字符比较
	void testStrcpm();
};

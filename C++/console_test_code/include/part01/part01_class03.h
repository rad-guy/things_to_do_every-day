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
	// ������ʱ������ new һ��ָ��
	void testTempVarNewPoint();

	// ���� ��ʱ�������� �Ƿ�´������
	void testTempVariableReturn();

	// ���Զ�ȡ�ļ��ĸ��ַ�ʽ
	void testReadFile();

	// ���԰������ַ���д���ļ�����������
	void testWriteClassInStream();

	// ���� �ַ��Ƚ�
	void testStrcpm();
};

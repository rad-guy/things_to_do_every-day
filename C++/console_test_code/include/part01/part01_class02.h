#include <string>

#include <vector>
using namespace std;

typedef struct tagSScreenPhysicsSize
{
	long x;
	long y;
}SScreenPhysicsSize;

class CPart01Class02Test
{
public:
	CPart01Class02Test();
	~CPart01Class02Test();

	static void setStaticVariable(int val);
	int			getStaticVariable();
	void		setName(string name);



public:
	string		m_sName;
private:
	static int  m_iTestVariable;

};

class CPart01Class02
{
public:
	CPart01Class02() {};
	~CPart01Class02() {};

	// ����1��������̬��Ա�������޸ı���ֵ�ľ�̬�������Ƿ��Ժ�ÿ��ʵ����ֵ���Ǹı���ֵ
	// ʵ��֤������̬��Ա�����;�̬��Ա���� �Ѿ��洢����̬�洢������ϵ��ʵ���Ѿ������������Ա��
	// ����ÿ��ʵ�����ɷ��������̬��Ա������ֵ��һ�����·������๫������һ��
	void				prove01();
	// windows �� ��ȡ��������ߴ��С
	void				getScreenScreenPhysicsSize(SScreenPhysicsSize& master, SScreenPhysicsSize& slave);
	void				getIntArrByteNum();

	// ����ɾ���ļ����������ļ�
	int					removeDirAllFile(const wstring& dir_path);

	// ���Կ����ļ�
	int					CopyFolder(const wstring& src_path, const wstring& dest_path);
	// ���Ի�ȡ�ļ����������ļ�
	static void			GetDirAllFiles(const wstring& file_path, vector<wstring>& files, const wstring& ext = L"");

	// ���Է����ļ���׺
	static wstring		getFileSuffix(const wstring& filepath);

	// ���� winapi MonitorFromWindow
	static void			testMonitorFromWindow();
	// ���� LPCTSTR ��ֵ�� string  ��ֵ����
	static void			testLPCSTR2String();

private:
	CPart01Class02Test		m_cTest01;
	CPart01Class02Test		m_cTest02;
};

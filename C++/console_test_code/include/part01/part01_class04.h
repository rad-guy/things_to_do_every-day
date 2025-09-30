#include <string>
#include <vector>
#include <map>
using namespace std;

class CPart01Class04
{
public:
	CPart01Class04() {};
	~CPart01Class04() {};


	void testLambda();

	void testFunc();

	// 测试位运算
	void testBitwise();

	void testStdThread();

	// 测试 substr 裁剪函数 add by dhx at 2023/08/17
	void testStdSubstr();

	// 测试 获取文件被占用的进程信息 add by dhx at 2023/10/07
	void testReleaseOccupyedFile();

	// 测试 y=ax² CString -> utf-8 string -> CString
	void testSpeSpecialCharacter();
	//(0: utf8 1: ASCII) -1: 其他
	int testIsUtf_8String(const string& str);


	// 测试长短路径
	int testLongShortPath();
	int testWOpen();

	// 测试矩形差集
	void testSubtractRect();
public:

	static std::map<std::string, std::string> s_mapTest;
	void testMap();

};

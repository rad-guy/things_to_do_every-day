#include "study01/study01_class03.h"

#include <string>

using namespace std;
void CStudy01Class03::studySTL2()
{
	studyString();
}

void CStudy01Class03::studyString()
{
	// 构造函数
	string test_str = "test_string";
	string test_str2 = string(test_str);
	// 第一个参数是string ，则从第四个位置到最后
	string test_str3 = string(test_str,4);
	// 第一个参数是char* ，则从第一个位置数4个字符
	string test_str4 = string(test_str.data(),4);


	string test_str5 = "0: 56\r\n";
	char* p_test_str5 = (char*)test_str5.data();
	// 后移2位" 56\r\n"
	char* p_c = p_test_str5 + 2;
	// 第三个字符" "
	char c = p_test_str5[2];

	int len;
	// ret = 1; 返回值是一个整数，表示成功解析并匹配的参数个数
	// -1 解析失败，发生了错误。
	// 0  没有匹配到任何参数
	int ret = sscanf(p_test_str5 + 2, "%d", &len);
	char str[] = "123 3.14";
	int num;
	float f;
	// result = 2;
	int result = sscanf(str, "%d %f", &num, &f);


}

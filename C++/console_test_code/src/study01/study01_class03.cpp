#include "study01/study01_class03.h"

#include <string>

using namespace std;
void CStudy01Class03::studySTL2()
{
	studyString();
}

void CStudy01Class03::studyString()
{
	// ���캯��
	string test_str = "test_string";
	string test_str2 = string(test_str);
	// ��һ��������string ����ӵ��ĸ�λ�õ����
	string test_str3 = string(test_str,4);
	// ��һ��������char* ����ӵ�һ��λ����4���ַ�
	string test_str4 = string(test_str.data(),4);


	string test_str5 = "0: 56\r\n";
	char* p_test_str5 = (char*)test_str5.data();
	// ����2λ" 56\r\n"
	char* p_c = p_test_str5 + 2;
	// �������ַ�" "
	char c = p_test_str5[2];

	int len;
	// ret = 1; ����ֵ��һ����������ʾ�ɹ�������ƥ��Ĳ�������
	// -1 ����ʧ�ܣ������˴���
	// 0  û��ƥ�䵽�κβ���
	int ret = sscanf(p_test_str5 + 2, "%d", &len);
	char str[] = "123 3.14";
	int num;
	float f;
	// result = 2;
	int result = sscanf(str, "%d %f", &num, &f);


}

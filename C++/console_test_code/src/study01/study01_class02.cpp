#include "study01/study01_class02.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

// for_each �ص�����
//void myPrint(int val)
//{
//	cout << val << endl;
//}
//void test01()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	// ͨ�����������������е�����
//	//vector<int>::iterator itBegin = v.begin();
//	//vector<int>::iterator itEnd = v.end();
//	// ��һ�ֱ�����ʽ whileѭ��
//	//while (itBegin != itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//};
//	// �ڶ��ֱ�����ʽ forѭ��
//	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << *it << endl;
//	//}
//	// �����ֱ�����ʽ ����STL�ṩ�����㷨
//	for_each(v.begin(), v.end(), myPrint); // �����������ǻص�������myPrint�е��βξ��� ÿһ�������ڵ�Ԫ��
//
//}

// vector����Զ�����������
//class Person
//{
//public:
//	Person(string name, int age) :m_Name(name), m_Age(age)
//	{
//
//	}
//	string m_Name;
//	int m_Age;
//};
//void test02()
//{
//	vector<Person> v1;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	// ���������������
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//
//	for (vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		// �Ƚ����� �ٵ�������������� -> ��ͷ��������������Ļ� ��������
//		cout << "������" << it->m_Name << "���䣺" << (*it).m_Age << endl;
//	}
//}
//// ����Զ�������ָ��
//void test03()
//{
//	vector<Person*> v2;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	// ���������������
//	v2.push_back(&p1);
//	v2.push_back(&p2);
//	v2.push_back(&p3);
//
//	for (vector<Person*>::iterator it = v2.begin(); it != v2.end(); it++)
//	{
//		// ������vector����ʲô���ݣ���it�����ú����ʲô����
//		cout << "������" << (*it)->m_Name << "���䣺" << (*it)->m_Age << endl;
//	}
//}

//// ����Ƕ������
//void test04()
//{
//	vector<vector<int>> v;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	for (int i = 0; i < 4; i++)
//	{
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
//		{
//			cout << *it2 << " ";
//		};
//		cout << endl;
//	}
//}

// string
//void test05()
//{
//	// �����ַ���
//	//string s1; // Ĭ�Ϲ���
//	//
//	//const char* str = "hello world";  // C ����ַ���
//	//string s2(str);
//
//	//string s3(s2);
//
//	//string s4(10, 'a');
//
//	// ��ֵ�ַ���
//	//string str1;
//	//str1 = "hello world";
//	//cout << str1 << endl;
//
//	//string str2;
//	//str2 = str1;
//	//cout << str2 << endl;
//
//	//string str3;
//	//str3 = 'a';
//	//cout << str3 << endl;
//
//	//string str4;
//	//str4.assign("hello C++");
//	//cout << str4 << endl;
//
//	//string str5;
//	//str5.assign("hello C++,I am DehaoXu.", 10);
//	//cout << str5 << endl;
//
//	//string str6;
//	//str6.assign(15, 'b');
//	//cout << str6 << endl;
//
//	//string str7;
//	//str7.assign(str6);
//	//cout << str7 << endl;
//
//	// �ַ���ƴ��
//	//string str1 = "hello,world";
//	//str1 += ",I am DehaoXu";
//	//cout << str1 << endl;
//
//	//string str2 = "hello world";
//	//str2 += 'a';
//	//cout << str2 << endl;
//
//	//string str3 = "Haha!";
//	//str3 += str2;
//	//cout << str3 << endl;
//
//	//string str4 = "hello,world2";
//	//str4.append("-nihao");
//	//cout << str4 << endl;
//
//	//string str5 = "hello world3";
//	//str5.append("yaya5Haaa", 7);
//	//cout << str5 << endl;
//
//	//string str6 = "hello world4";
//	//str6.append(str5);
//	//cout << str6 << endl;
//
//	//string str7 = "hello world5";
//	//str7.append(str5, 3, 5);
//	//cout << str7 << endl;
//
//	// string ���Һ��滻
//	//string strSrc = "abcdefgde";
//	//int pos1 = strSrc.find("de");
//	//if (pos1 == -1)
//	//{
//	//	cout << "δ�ҵ�" << endl;
//	//}
//	//else
//	//{
//	//	cout << pos1 << endl;
//	//};
//	//// rfind �� find ����
//	//// rfind �����������  find �������Ҳ���
//	//pos1 = strSrc.rfind("de");
//	//if (pos1 == -1)
//	//{
//	//	cout << "δ�ҵ�" << endl;
//	//}
//	//else
//	//{
//	//	cout << pos1 << endl;
//	//};
//	
//	// �� pos λ�ò��� s ��ǰ n ���ַ���һ��λ��
//	//string str = "abcdefga";
//	//int pos = str.find("ab", 1, 1);
//	//cout << pos << endl;
//
//	// �Ƚ��ַ���
//	//string str = "xbc";
//	//string str2 = "abce";
//	//int res = str.compare(str2);
//	//cout << res << endl;
//
//	// �ַ�����ȡ
//	//string str = "hello";
//	//for (int i = 0; i < str.size(); i++)
//	//{
//	//	cout << str[i] << " ";
//	//}
//	//cout << endl;
//	//string str = "hello";
//	//for (int i = 0; i < str.size(); i++)
//	//{
//	//	cout << str.at(i) << " ";
//	//}
//	//cout << endl;
//
//	// �ַ���������ɾ��
//	//string str = "hello";
//	//// ����
//	//str.insert(1, " world");
//	//cout << str << endl;
//
//	//str.insert(1, 2, 'a');
//	//cout << str << endl;
//	//// ɾ��
//	//str.erase(1, 8);
//	//cout << str << endl;
//
//	// ��ȡ�ַ���
//	//string str = "hello world";
//	//string str1 = str.substr(0, 5);
//	//cout << str << endl;
//	//cout << str1 << endl;
//
//};
//void test06()
//{
//	//string str1 = "abcdefgde";
//	//str1.replace(1, 3, "1111");
//	//cout << str1 << endl;
//
//	//string str2 = "abcdefgde";
//	//str2.replace(1, 1, str1);
//	//cout << str2 << endl;
//}

//void test07()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.insert(v.begin(), 10, 12);
//	//cout << *v.begin() << endl;
//	//cout << v.front() << endl;
//	// �����ұ� ����ɾ��Ԫ�أ�
//	//v.erase(v.begin(),v.end());
//	vector<int> v2;
//	v2.resize(10);
//	v.swap(v2);
//	cout << v2.size() << endl;
//	cout << v.size() << endl;
//}

// vector Ԥ���ռ�
// �鿴 ��̬��չ����
//void test08()
//{
//	vector<int> v;
//
//	// ���� reserve Ԥ���ռ�
//	v.reserve(100000);
//	int num = 0;
//	int* p = NULL;
//	for (int i = 0; i < 100000; i++)
//	{
//		v.push_back(i);
//		// ����һ��ָ�� ָ�� ���� ��Ԫ�صĵ�ַ
//		// ��� v �����¿ռ䣬���ͷŵ���ǰ��ָ�룬���ʱ���ٰ�ָ��ָ����Ԫ�ص�ַ������
//		if (p != &v[0])
//		{
//			p = &v[0];
//			num++;
//		}
//	};
//	cout << num << endl;
//}

// ��������
//class MyAdd
//{
//public:
//	int operator()(int v1, int v2)
//	{
//		return v1 + v2;
//	}
//};
//class MyPrint
//{
//public:
//	MyPrint()
//	{
//		count = 0;
//	}
//	void operator()(string test)
//	{
//		this->count++;
//		cout << test << endl;
//	}
//
//	int count;  // �ڲ��Լ���״̬
//};
//void doPrint(MyPrint& mp, string test)
//{
//	mp(test);
//	cout << mp.count << endl;
//}
//void test10()
//{
//	MyPrint myPrint;
//	doPrint(myPrint, "hello,C++");
//
//}

// ν��
// һԪν��
//class GreaterFive
//{
//public:
//	bool operator()(int val)
//	{
//		return val > 5;
//	}
//};
//void test11()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	};
//	// ���������У���û�д��� 5 ������
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.end())
//	{
//		cout << "δ�ҵ�" << endl;
//	}
//	else
//	{
//		cout << "�ҵ�Ϊ��" << *it << endl;
//	}
//}
// ��Ԫν��
//class MyCompare
//{
//public:
//	bool operator()(int val1, int val2)
//	{
//		return val1 > val2;
//	}
//};
//void test12()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(50);
//
//	sort(v.begin(), v.end()); // ��������
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	// ʹ�ú������󣬸ı��㷨���ԣ���Ϊ�������Ӵ�С
//	//sort(v.begin(), v.end(), MyCompare());
//	sort(v.begin(), v.end(), greater<int>());
//	for (vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
//	{
//		cout << *it2 << " ";
//	}
//	cout << endl;
//}

// �º���
// һԪ�º���
// ȡ���º���
//void test13()
//{
//	negate<int> n;
//	cout << n(50) << endl;
//}

// ��Ԫ�º���
// �ӷ��º���
//void test14()
//{
//	plus<int> n;
//	cout << n(12, 23) << endl;
//}

// �㷨
// for_each
// ��ͨ����
//void print01(int val)
//{
//	cout << val << endl;
//}
//// �º���
//class print02
//{
//public:
//
//	void operator()(int val)
//	{
//		cout << val << endl;
//	};
//};
//void test15()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	};
//
//	for_each(v.begin(), v.end(), print01);
//	for_each(v.begin(), v.end(), print02());
//	cout << endl;
//}

// transform
//void test16()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	};
//
//	vector<int>vTarget;
//	vTarget.resize(v.size());
//	transform(v.begin(), v.end(), vTarget.begin(), negate<int>());
//	for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}

////find
////����������������
//class GreaterFive
//{
//public:
//	bool operator()(int val)
//	{
//		//return val;
//		// find_if
//		return val > 5;
//	}
//};
//
//void test20()
//{
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	};
//	//vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
//	//����������
//	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());
//	if (it == v1.end())
//	{
//		cout << "δ�ҵ�" << endl;
//	}
//	else
//	{
//		cout << *it << endl;
//	}
//}
////�����Զ�����������
//class Person
//{
//public:
//	Person(string name, int age) :m_Name(name), m_Age(age)
//	{
//
//	};
//	// �Զ������� �޷��Աȣ�����Ҫ���� == ��
//	// ��ֹ�޸ĵײ�� ���� ���Լ�һ�� const
//	//bool operator==(const Person &p)
//	//{
//	//	if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//	//	{
//	//		return true;
//	//	}
//	//	else
//	//	{
//	//		return false;
//	//	}
//	//}
//	string m_Name;
//	int m_Age;
//};
//class Greater16
//{
//public:
//	bool operator()(Person& p)
//	{
//		return p.m_Age > 16;
//	}
//};
//void test21()
//{
//	vector<Person> v;
//	Person p1("aaa", 15);
//	Person p2("bbb", 16);
//	Person p3("ccc", 17);
//	Person p4("ddd", 18);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//	//vector<Person>::iterator it = find(v.begin(), v.end(), p1);
//	//���������� // find_if
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater16());
//	if (it == v.end())
//	{
//		cout << "δ�ҵ�" << endl;
//	}
//	else
//	{
//		cout << it->m_Name << " " << it->m_Age << endl;
//	}
//}

// adjacent_find
//void test22()
//{
//	vector<int> v;
//	v.push_back(0);
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(3);
//
//	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
//	if (it == v.end())
//	{
//		cout << "δ�ҵ������ظ�Ԫ��" << endl;
//	}
//	else
//	{
//		cout << "�ҵ�" << *it << endl;
//	}
//}

//// binary_search
//void test23()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	};
//	v.push_back(2); // �� 0-9 �м��ֲ�����һ��Ԫ�أ����ҽ���Ͳ�׼ȷ����Ϊ������������
//	// ע�⣺�������������������
//	bool ret = binary_search(v.begin(), v.end(), 9);
//	if (ret)
//	{
//		cout << "�ҵ���" << endl;
//	}
//	else
//	{
//		cout << "δ�ҵ�" << endl;
//	}
//}

// count
// ͳ��������������
//void test24()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(40);
//	
//	int num = count(v.begin(), v.end(), 40);
//	cout << "ͳ�Ƶ����ָ�����" << num << endl;
//}
//// ͳ���Զ�����������
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	};
//	bool operator==(const Person& p)
//	{
//		if (this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	string m_Name;
//	int m_Age;
//};
//void test25()
//{
//	vector<Person> v;
//	Person p1("����", 35);
//	Person p2("����", 35);
//	Person p3("�ŷ�", 35);
//	Person p4("����", 24);
//	Person p5("�ܲ�", 57);
//	Person p6("��", 24);
//	Person p7("�����", 35);
//	Person p8("���", 22);
//	Person p9("����", 18);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	v.push_back(p6);
//	v.push_back(p7);
//	v.push_back(p8);
//	v.push_back(p9);
//
//	Person p("����", 35);
//
//	int num = count(v.begin(), v.end(), p);
//	if (num)
//	{
//		cout << "���������һ�������У� " << num << " ��" << endl;
//	}
//	else
//	{
//		cout << "û�����������һ������" << endl;
//	}
//}

// �����㷨 random_shuffle
//void test26()
//{
//	// ��ʱ��Ϊ׼�����������
//	srand((unsigned int)time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	};
//	random_shuffle(v.begin(), v.end());
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;
//	}
//}

// merge
//class MyReplace
//{
//public:
//	bool operator()(int val)
//	{
//		return val > 5;
//	}
//};
//class MyPrint
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//void test27()
//{
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 1);
//	};
//	
//	// Ŀ������
//	vector<int> vTarget;
//
//	// ��ǰ��Ŀ����������ռ�
//	vTarget.resize(v1.size() + v2.size());
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
//	{
//		cout << *it << " ";
//	};
//	cout << endl;
//
//	// reverse
//	reverse(vTarget.begin(), vTarget.end());
//
//	for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
//	{
//		cout << *it << " ";
//	};
//	cout << endl;
//
//	vector<int> copyV;
//
//	copyV.resize(vTarget.size());
//	copy(vTarget.begin(), vTarget.end(), copyV.begin());
//
//	for (vector<int>::iterator it = copyV.begin(); it != copyV.end(); it++)
//	{
//		cout << *it << " ";
//	};
//	cout << endl;
//
//	replace(copyV.begin(), copyV.end(), 9, 111);
//	for (vector<int>::iterator it = copyV.begin(); it != copyV.end(); it++)
//	{
//		cout << *it << " ";
//	};
//	cout << endl;
//
//	replace_if(copyV.begin(), copyV.end(), MyReplace(), -1);
//	for (vector<int>::iterator it = copyV.begin(); it != copyV.end(); it++)
//	{
//		cout << *it << " ";
//	};
//	cout << endl;
//
//	swap(vTarget, copyV);
//	for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
//	{
//		cout << *it << " ";
//	};
//	cout << endl;
//	for_each(copyV.begin(), copyV.end(), MyPrint());
//	cout << endl;
//}

// �������������㷨
// accumulate
//void test28()
//{
//	vector<int> v;
//	for (int i = 0; i < 100; i++)
//	{
//		v.push_back(i);
//	};
//	// ����3 ��һ����ʼ�ۼ�ֵ
//	int total1 = accumulate(v.begin(), v.end(), 0);
//	int total2 = accumulate(v.begin(), v.end(), 1000);
//	cout << total1 << endl;
//	cout << total2 << endl;
//}

// fill
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//void test29()
//{
//	vector<int> v;
//	v.resize(10);
//	// �����������
//	fill(v.begin(), v.end(), 132);
//	for_each(v.begin(), v.end(), MyPrint());
//	cout << endl;
//}

// ���ü����㷨
void test30()
{
	vector<int> v1;
	vector<int> v2;
	//vector<int> vTarget;
	vector<int> vTargetV1_V2;
	vector<int> vTargetV2_V1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	};

	// set_intersection
	// ��Ϊ�ǽ��������� vTarget ���size Ϊ������������С������size,���� min ����
	//vTarget.resize(min(v1.size(),v2.size()));
	//// �㷨���ص��� �������λ�õĵ�����
	//vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//for_each(vTarget.begin(), itEnd, MyPrint()); // ��� 5 6 7 8 9
	// �������д�Ļ� ���Ϊ 5 6 7 8 9 0 0 0 0 0
	//for_each(vTarget.begin(), vTarget.end(), MyPrint());
	//cout << endl;

	// set_union
	// ��Ϊ�ǲ��������� vTarget ���size Ϊ����������size ֮��
	//vTarget.resize(v1.size() + v2.size());
	//vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//for_each(vTarget.begin(), itEnd, MyPrint()); // ��� 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
	//// �������д�Ļ� ���Ϊ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 0 0 0 0 0
	////for_each(vTarget.begin(), vTarget.end(), MyPrint());
	//cout << endl;

	// set_difference
	// ��Ϊ�ǲ������ vTarget ���size Ϊ�������������������size,���� max ����
	vTargetV1_V2.resize(max(v1.size(), v2.size()));
	vTargetV2_V1.resize(max(v1.size(), v2.size()));
	// v1 ��ǰ�棬���ص��� v1 �е�ʣ��Ԫ��
	vector<int>::iterator itEndV1_V2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTargetV1_V2.begin());
	// v2 ��ǰ�棬���ص��� v2 �е�ʣ��Ԫ��
	vector<int>::iterator itEndV2_V1 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTargetV2_V1.begin());
	for_each(vTargetV1_V2.begin(), itEndV1_V2, MyPrint());
	cout << endl;
	for_each(vTargetV2_V1.begin(), itEndV2_V1, MyPrint());
	cout << endl;
}

void CStudy01Class02::studySTL()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	// ��������
	//MyAdd myAdd;
	//cout << myAdd(10, 20) << endl;
	//MyPrint myPrint;
	//myPrint("hello world");
	//myPrint("hello world");
	//myPrint("hello world");
	//myPrint("hello world");
	//myPrint("hello world");
	//cout << "���ô�����" << myPrint.count << endl;
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();

	//test20();
	//test21();
	//test22();
	//test23();
	//test24();
	//test25();
	//test26();
	//test27();
	//test28();
	//test29();

	test30();
}

#include "study01/study01_class02.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

// for_each 回到函数
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
//	// 通过迭代器访问容器中的数据
//	//vector<int>::iterator itBegin = v.begin();
//	//vector<int>::iterator itEnd = v.end();
//	// 第一种遍历方式 while循环
//	//while (itBegin != itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//};
//	// 第二种遍历方式 for循环
//	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << *it << endl;
//	//}
//	// 第三种遍历方式 利用STL提供遍历算法
//	for_each(v.begin(), v.end(), myPrint); // 第三个参数是回调函数，myPrint中的形参就是 每一个容器内的元素
//
//}

// vector存放自定义数据类型
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
//	// 向容器中添加数据
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//
//	for (vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		// 先解引用 再点操作符，可以用 -> 箭头操作符，如果不的话 加上括号
//		cout << "姓名：" << it->m_Name << "年龄：" << (*it).m_Age << endl;
//	}
//}
//// 存放自定义类型指针
//void test03()
//{
//	vector<Person*> v2;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	// 向容器中添加数据
//	v2.push_back(&p1);
//	v2.push_back(&p2);
//	v2.push_back(&p3);
//
//	for (vector<Person*>::iterator it = v2.begin(); it != v2.end(); it++)
//	{
//		// 看上面vector中是什么数据，对it解引用后就是什么数据
//		cout << "姓名：" << (*it)->m_Name << "年龄：" << (*it)->m_Age << endl;
//	}
//}

//// 容器嵌套容器
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
//	// 构造字符串
//	//string s1; // 默认构造
//	//
//	//const char* str = "hello world";  // C 风格字符串
//	//string s2(str);
//
//	//string s3(s2);
//
//	//string s4(10, 'a');
//
//	// 赋值字符串
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
//	// 字符串拼接
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
//	// string 查找和替换
//	//string strSrc = "abcdefgde";
//	//int pos1 = strSrc.find("de");
//	//if (pos1 == -1)
//	//{
//	//	cout << "未找到" << endl;
//	//}
//	//else
//	//{
//	//	cout << pos1 << endl;
//	//};
//	//// rfind 和 find 区别
//	//// rfind 从右往左查找  find 从左往右查找
//	//pos1 = strSrc.rfind("de");
//	//if (pos1 == -1)
//	//{
//	//	cout << "未找到" << endl;
//	//}
//	//else
//	//{
//	//	cout << pos1 << endl;
//	//};
//	
//	// 从 pos 位置查找 s 的前 n 个字符第一次位置
//	//string str = "abcdefga";
//	//int pos = str.find("ab", 1, 1);
//	//cout << pos << endl;
//
//	// 比较字符串
//	//string str = "xbc";
//	//string str2 = "abce";
//	//int res = str.compare(str2);
//	//cout << res << endl;
//
//	// 字符串存取
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
//	// 字符串插入与删除
//	//string str = "hello";
//	//// 插入
//	//str.insert(1, " world");
//	//cout << str << endl;
//
//	//str.insert(1, 2, 'a');
//	//cout << str << endl;
//	//// 删除
//	//str.erase(1, 8);
//	//cout << str << endl;
//
//	// 截取字符串
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
//	// 以左开右闭 区间删除元素，
//	//v.erase(v.begin(),v.end());
//	vector<int> v2;
//	v2.resize(10);
//	v.swap(v2);
//	cout << v2.size() << endl;
//	cout << v.size() << endl;
//}

// vector 预留空间
// 查看 动态扩展次数
//void test08()
//{
//	vector<int> v;
//
//	// 利用 reserve 预留空间
//	v.reserve(100000);
//	int num = 0;
//	int* p = NULL;
//	for (int i = 0; i < 100000; i++)
//	{
//		v.push_back(i);
//		// 定义一个指针 指向 容器 首元素的地址
//		// 如果 v 开辟新空间，会释放掉以前的指针，这个时候再把指针指向到首元素地址，计数
//		if (p != &v[0])
//		{
//			p = &v[0];
//			num++;
//		}
//	};
//	cout << num << endl;
//}

// 函数对象
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
//	int count;  // 内部自己的状态
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

// 谓词
// 一元谓词
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
//	// 查找容器中，有没有大于 5 的数字
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.end())
//	{
//		cout << "未找到" << endl;
//	}
//	else
//	{
//		cout << "找到为：" << *it << endl;
//	}
//}
// 二元谓词
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
//	sort(v.begin(), v.end()); // 升序排列
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	// 使用函数对象，改变算法策略，变为排序规则从大到小
//	//sort(v.begin(), v.end(), MyCompare());
//	sort(v.begin(), v.end(), greater<int>());
//	for (vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
//	{
//		cout << *it2 << " ";
//	}
//	cout << endl;
//}

// 仿函数
// 一元仿函数
// 取反仿函数
//void test13()
//{
//	negate<int> n;
//	cout << n(50) << endl;
//}

// 二元仿函数
// 加法仿函数
//void test14()
//{
//	plus<int> n;
//	cout << n(12, 23) << endl;
//}

// 算法
// for_each
// 普通函数
//void print01(int val)
//{
//	cout << val << endl;
//}
//// 仿函数
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
////查找内置数据类型
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
//	//按条件查找
//	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());
//	if (it == v1.end())
//	{
//		cout << "未找到" << endl;
//	}
//	else
//	{
//		cout << *it << endl;
//	}
//}
////查找自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age) :m_Name(name), m_Age(age)
//	{
//
//	};
//	// 自定义类型 无法对比，所以要重载 == 号
//	// 防止修改底层的 代码 所以加一个 const
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
//	//按条件查找 // find_if
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater16());
//	if (it == v.end())
//	{
//		cout << "未找到" << endl;
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
//		cout << "未找到相邻重复元素" << endl;
//	}
//	else
//	{
//		cout << "找到" << *it << endl;
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
//	v.push_back(2); // 在 0-9 中间又插入了一个元素，查找结果就不准确，因为不是有序序列
//	// 注意：容器必须是有序的序列
//	bool ret = binary_search(v.begin(), v.end(), 9);
//	if (ret)
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "未找到" << endl;
//	}
//}

// count
// 统计内置数据类型
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
//	cout << "统计的数字个数：" << num << endl;
//}
//// 统计自定义数据类型
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
//	Person p1("刘备", 35);
//	Person p2("关羽", 35);
//	Person p3("张飞", 35);
//	Person p4("赵云", 24);
//	Person p5("曹操", 57);
//	Person p6("马超", 24);
//	Person p7("诸葛亮", 35);
//	Person p8("周瑜", 22);
//	Person p9("貂蝉", 18);
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
//	Person p("大乔", 35);
//
//	int num = count(v.begin(), v.end(), p);
//	if (num)
//	{
//		cout << "与大乔年龄一样的人有： " << num << " 个" << endl;
//	}
//	else
//	{
//		cout << "没有与大乔年龄一样的人" << endl;
//	}
//}

// 排序算法 random_shuffle
//void test26()
//{
//	// 以时间为准的随机数种子
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
//	// 目标容器
//	vector<int> vTarget;
//
//	// 提前给目标容器分配空间
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

// 常用算数生成算法
// accumulate
//void test28()
//{
//	vector<int> v;
//	for (int i = 0; i < 100; i++)
//	{
//		v.push_back(i);
//	};
//	// 参数3 是一个起始累加值
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
//	// 后期重新填充
//	fill(v.begin(), v.end(), 132);
//	for_each(v.begin(), v.end(), MyPrint());
//	cout << endl;
//}

// 常用集合算法
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
	// 因为是交集，所以 vTarget 最大size 为两个容器中最小容器的size,利用 min 函数
	//vTarget.resize(min(v1.size(),v2.size()));
	//// 算法返回的是 交集最后位置的迭代器
	//vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//for_each(vTarget.begin(), itEnd, MyPrint()); // 输出 5 6 7 8 9
	// 如果这样写的话 输出为 5 6 7 8 9 0 0 0 0 0
	//for_each(vTarget.begin(), vTarget.end(), MyPrint());
	//cout << endl;

	// set_union
	// 因为是并集，所以 vTarget 最大size 为两个容器中size 之和
	//vTarget.resize(v1.size() + v2.size());
	//vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//for_each(vTarget.begin(), itEnd, MyPrint()); // 输出 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
	//// 如果这样写的话 输出为 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 0 0 0 0 0
	////for_each(vTarget.begin(), vTarget.end(), MyPrint());
	//cout << endl;

	// set_difference
	// 因为是差集，所以 vTarget 最大size 为两个容器中最大容器的size,利用 max 函数
	vTargetV1_V2.resize(max(v1.size(), v2.size()));
	vTargetV2_V1.resize(max(v1.size(), v2.size()));
	// v1 在前面，返回的是 v1 中的剩余元素
	vector<int>::iterator itEndV1_V2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTargetV1_V2.begin());
	// v2 在前面，返回的是 v2 中的剩余元素
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
	// 函数对象
	//MyAdd myAdd;
	//cout << myAdd(10, 20) << endl;
	//MyPrint myPrint;
	//myPrint("hello world");
	//myPrint("hello world");
	//myPrint("hello world");
	//myPrint("hello world");
	//myPrint("hello world");
	//cout << "调用次数：" << myPrint.count << endl;
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

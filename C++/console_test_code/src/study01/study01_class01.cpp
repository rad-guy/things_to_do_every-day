#include "study01/study01_class01.h"

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <iostream>
#include <list>
#include <tuple>
#include <bitset>
#include <random>
#include <Windows.h>
#include <array>
#include <forward_list>
#include <map>
#include <set>
#include <sstream>
using namespace std;

template <class T> class Blob
{
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	Blob() {};  // 构造函数
	Blob(std::initializer_list<T> il) {};

	// Blob 中的元素数目
	size_type size() const
	{
		return data->size();
	}

	bool empty() const { return data->empty(); }

	// 添加和删除元素
	void push_back(const T& t) { data->push_back(t); }
	// 移动版本
	void push_back(T&& t)
	{
		data->push_back(std::move(t));
	}
	void pop_back()
	{
		check(0, "pop_back on empty Blob");
		data->pop_back();
	}


	// 元素访问
	T& back()
	{
		check(0, "back on empty Blob");
		return data->back();
	}
	T& operator[](size_type i)
	{

		return (*data)[i];
	}

private:
	std::shared_ptr<std::vector<T>> data;
	// 若 data[i] 无效，则抛出 msg
	void check(size_type i, const string& msg) const;
};
// 若 data[i] 无效，则抛出 msg
template <class T>
void Blob<T>::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}


void CStudy01Class01::studyTemplate()
{
	Blob<int> ia;
	Blob<int> ia2 = { 0,1,2,3 };
}

void CStudy01Class01::studyRegex()
{
	testRegexMatch();
	testRegexMatchBool();
	testRegexSearch();
	testRegexSearchBool();

	// 测试
	/*string ss = "xml";
	regex ip_reg = regex(ss);
	string content = "agjdkflsajdxmljdklflaskjdf";
	if (!std::regex_search(content, ip_reg))
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到" << endl;
	};*/
	// 测试
	//regex reg = regex("@");
	//string cxt = "shade_close@200.png";
	//if (!std::regex_search(cxt, reg))
	//{
	//    cout << "没找到" << endl;
	//}
	//else
	//{
	//    cout << "找到" << endl;
	//};
}

void CStudy01Class01::testRegexMatch()
{

}

void CStudy01Class01::testRegexMatchBool()
{
	// regex_match 是否全局完全匹配
	const std::regex regex_obj_bool{ R"(\d{3}-\d{5})" };
	const std::string match_str_yes = "123-12345";
	const std::string match_str_no = "123-12345a";
	const bool matched_yes = std::regex_match(match_str_yes, regex_obj_bool);
	const bool matched_no = std::regex_match(match_str_no, regex_obj_bool);
	std::cout << "matched_yes ==> result = " << (matched_yes ? "yes" : "no") << std::endl;
	std::cout << "matched_no ==> result = " << (matched_no ? "yes" : "no") << std::endl;

	// regex_match 全局完全匹配并提取分组
	const std::regex re{ R"(\S+)" };
	const std::string str = "Loremipsumdoorsitametconsectetur";
	const std::sregex_iterator begin{ str.cbegin(), str.cend(), re }, end;
	const auto count = std::distance(begin, end);
	std::cout << count << std::endl;
}


void CStudy01Class01::testRegexSearch()
{
	string file_path = "study_res/regex.txt";
	// ios::in 只读
	//ifstream txt_file(R"(study/regex.txt)", ios::in);
	ifstream txt_file;
	txt_file.open(file_path);
	if (!txt_file.is_open())
	{
		std::cerr << "打开文件失败,file_path = " << file_path << std::endl;
		return;
	}
	istreambuf_iterator<char> begin(txt_file), end;
	string target_str(begin, end);
	txt_file.close();
	// \s 匹配任何空白字符 
	// *  匹配0次或多次
	// \d 匹配数字
	// R vs 2019工具集写法
	//const regex regex_obj{ R"((cy|cx)\s*\=\s*(\d+))" };
	// vs 2012 写法
	string regex_str = "(cy|cx)\\\s*\\\=\\\s*(\\\d+)";
	const regex regex_obj(regex_str);

	smatch search_result;
	string::const_iterator it_start = target_str.begin();
	string::const_iterator it_end = target_str.end();
	vector<string> cx;
	vector<string> cy;
	// regex_search 第一种利用迭代器 方法搜索,-----多组条件符合
	for (; regex_search(it_start, it_end, search_result, regex_obj); it_start = search_result.suffix().first)
	{
	    // search_result.str() 是匹配的全部字符串
	    // search_result.str(1) 是匹配的 第一组数据
	    // search_result.str(2) 是匹配的 第二组数据
	    if (search_result.str(1) == "cx")
	    {
	        cx.push_back(search_result.str(2));
	    }
	    else if (search_result.str(1) == "cy")
	    {
	        cy.push_back(search_result.str(2));
	    };
	    // 还可以这样访问 0是匹配的全部字符串，1是第一组，2是第二组
	    if (search_result[1] == "cx")
	    {
	        //cout << search_result[2] << endl;
	        cx.push_back(search_result[2]);
	    }
	    else if (search_result[1] == "cy")
	    {
	        //cout << search_result[2] << endl;
	        cy.push_back(search_result[2]);
	    };
	    
	}
	// regex_search 第二种利用下标 方法搜索-----搜索到一组就返回
	if (regex_search(target_str, search_result, regex_obj))
	{
		//打印子表达式结果
		if (search_result[1] == "cx")
		{
			cout << search_result[2] << endl;
		}
		else if (search_result[1] == "cy")
		{
			cout << search_result[2] << endl;
		};
		cout << endl;
	}


	// 打印结果
	for (vector<string>::const_iterator itercx = cx.cbegin(); itercx != cx.cend(); itercx++) {
		cout << (*itercx) << endl;
	}
	for (vector<string>::const_iterator itercy = cy.cbegin(); itercy != cy.cend(); itercy++) {
		cout << (*itercy) << endl;
	}

}

void CStudy01Class01::testRegexSearchBool()
{
	// regex_search 是否局部匹配
	// ^ 匹配字符串开始位置
	//		当在方括号中，表示非
	//		匹配 ^ 字符本身，请使用 \^
	// $ 匹配输入字符串结尾的位置
	const std::regex regex_obj_bool{ R"(^.{5,}$)" };
	const std::string regex_search_yes = { R"(012345
											0190
											01234567890123456789
											01234)" };
	const std::string regex_search_no = { R"(012.345
											0190
											01234567890123456789
											01234)" };
	const bool search_yes = std::regex_search(regex_search_yes, regex_obj_bool);
	const bool search_no = std::regex_search(regex_search_no, regex_obj_bool);

	std::cout << "search_yes ==> result = " << (search_yes ? "yes" : "no") << std::endl;
	std::cout << "search_no ==> result = " << (search_no ? "yes" : "no") << std::endl;
}

class A
{
public:
	A() :m_I(0)
	{

	};
	void SetI(int i)
	{
		m_I = i;
	}
	int GetI()
	{
		return m_I;
	}

private:
	int m_I;
	bool m_B;
	bool m_C;

};

// 申请内存
void testreq01()
{
	A* a1 = new A();
	a1->SetI(3);
	cout << a1->GetI() << endl;  // 3
	new(a1)A; // 利用现有的内存  直接执行  a1 的构造函数
	cout << a1->GetI() << endl;  // 0

	char* tempMem = (char*)::operator new(12); // 申请一个 12 字节的内存
	void* tempMem2 = (void*)::malloc(12); // 也可以 用这个 来申请内存
	A* a3 = new(tempMem2)A;  // 用刚申请来的内存执行 A 的构造函数 并用 a3 指针指向它

	//::operator delete(tempMem);
	free(tempMem2);
	delete a3;


	delete a1;
	A* a2 = new A[3];
	delete[]a2;

	cout << sizeof(A) << endl;
}
// 强制转换
void testtransform02()
{
	int num = 0x00636261;//用16进制表示32位int，0x61是字符'a'的ASCII码
	int* pnum = &num;
	char* pstr = reinterpret_cast<char*>(pnum);
	cout << "pnum指针的值: " << pnum << endl;
	cout << "pstr指针的值: " << static_cast<void*>(pstr) << endl;//直接输出pstr会输出其指向的字符串，这里的类型转换是为了保证输出pstr的值
	cout << "pnum指向的内容: " << hex << *pnum << endl;
	cout << "pstr指向的内容: " << pstr << endl;
}
void CStudy01Class01::studyMemory()
{
	testreq01();
	testtransform02();
}

void CStudy01Class01::studyTuple()
{

	tuple<string, vector<double>, int, list<int>> someVal("constants", { 3.14,2.718 }, 42, { 1,2,3,4 });
	auto item = make_tuple("0-999-78234-X", 3, 2000);
	cout << get<0>(item) << endl;  // get 访问成员  输出 0-999-78234-X
	typedef decltype(item) trans;

	size_t sz = tuple_size<trans>::value; // 用辅助类模板 查询成员的数量和类型
	tuple_element<1, trans>::type cnt = get<1>(item);
	cout << cnt << endl;  // 输出 3 
	cout << sz << endl;  // 输出 3 

	// bitset // 定义 bitset 需要声明它包含多少个二进制位 从 0 开始编号，第 0 位是最右边的位

	bitset<32> bitvec(1U);  // 32位  低位为1 ，其他位为0
	0xbeef;

	// 随机数
	// 引擎 生成随机 unsigned 整数序列
	//default_random_engine e; // 使用该引擎类型默认的种子

	//default_random_engine e(1);  // 以整型值作为种子
	//string u;
	//default_random_engine e;
	//e.seed(u);  // 使用种子
	//e.min(); // 此引擎可生成的最小值和最大值
	//e.max();
	//default_random_engine::result_type; // 此引擎生成的 unsigned 整形类型
	//e.discard(u); // 将引擎推进 u 步：u 的类型为 unsigned long long
	//for (unsigned int i = 0; i < 10; ++i)
	//{
	//    cout << e() << endl;
	//}

	// 分布  类型，使用引擎返回服从特定概率分布的随机数
	// 指定范围内的数
	uniform_int_distribution<unsigned> u(0, 19);
	default_random_engine e;
	for (unsigned int i = 0; i < 10; ++i)
	{
		// 将 U 作为随机数源
		// 每个调用返回在指定范围内并服从均匀分布的值
		cout << u(e) << " ";
	}

}

void CStudy01Class01::studyReg()
{
	string key = "";
	HKEY hkey = nullptr;
	LPCWSTR sub_key = L"Software\\datedu edu\\teach";
	LSTATUS res = ::RegOpenKeyEx(HKEY_CURRENT_USER, sub_key, 0, KEY_READ, &hkey);
	if (res != ERROR_SUCCESS) {
	}
	DWORD type = REG_SZ;
	DWORD size = 0;
	res = ::RegQueryValueExA(hkey, key.c_str(), 0, &type, nullptr, &size);
	if (res != ERROR_SUCCESS || size <= 0) {

	}
	vector<BYTE> value_data(size);
	res = ::RegQueryValueExA(hkey, key.c_str(), 0, &type, value_data.data(), &size);
	if (res != ERROR_SUCCESS) {

	}
	string result(value_data.begin(), value_data.end());

	vector<BYTE> by;
	by.push_back('a');
	by.push_back('b');
	by.push_back('c');
	by.push_back('\0');
	by.push_back('\0');
	by.push_back('\0');
	by.push_back('\0');
	string ab = string(by.begin(), by.end());
}


// 类型别名
// iterator  此容器类型的迭代器类型
// const_iterator 可以读取元素，但不能修改元素的迭代器类型
// size_type  无符号整数类型，足够保存此种容器类型最大可能容器的大小
// difference_type  带符号整数类型，足够保存两个迭代器之间的距离
// value_type  元素类型
// reference  元素的左值类型，与 value_type& 含义相同、
// const_reference 元素的 const 左值类型(即 const value_type&)
void CStudy01Class01::studySTL()
{
	// vector
	// 可变大小数组，支持快速随机访问，在尾部之外的位置插入或删除元素可能很慢
	// 构造函数
	vector<int> vc;
	vector<int> vc1(vc);
	vector<int>::iterator beginVc = vc.begin(), endVc = vc.end();
	vector<int> vc2(beginVc, endVc);
	// 列表初始化
	vector<int> vc3{ 1,2,3,4,5 };
	// 赋值与 swap
	vc3 = vc;
	vc3 = { 1,3,5 }; // 不适用 array
	// 交换元素
	vc3.swap(vc1);
	swap(vc3, vc1); // 与上面是等价的
	// 大小
	size_t vec_size = vc.size(); // 不支持forward_list单向链表
	size_t vec_max_size = vc.max_size(); //  可保存的最大元素数目
	bool is_empty = vc.empty(); // 布尔值，判断是否为空
	// 添加和删除元素(不适用于 array )
	// 注：在不同容器中，这些操作的接口都不同


	// 初始化
	vector<int> vd(2);  // 此构造函数是 explicit 的。抑制构造函数定义的隐式转换 string 不适用
	vector<int> ve(3, 2);

	// array
	array<int, 42>;// 定义一个 array,除了要指定元素类型，还要指定容器大小
	//array<int, 10> ial;
	array<int, 10> ia2 = { 0,1,2,3,4,5,6,7,8,9 }; // 列表初始化
	array<int, 10> ia3 = { 42 }; // 剩余元素为0;
	// 不能对内置数组类型进行拷贝或对象赋值操作，但 array 并无此限制
	int digs[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//int cpy[10] = digs; // 错误，内置数组不支持拷贝或赋值
	array<int, 10> digits = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10> copy = digits; // 正确，只要数组类型匹配即合法

	// assign 操作不适用关联容器和 array
	list<string> li{ "aaa","bbb","ccc" };
	list<string> li2{ "aa","bb","cc" };
	list<string>::const_iterator itBegin = li.begin(), itEnd = li.end();
	li2.assign(itBegin, itEnd);
	//for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	//{
	//	cout << *it << endl; // 输出 aaa, bbb, ccc
	//};
	//li2.assign({ "ccc","bbb","aaa" });
	//for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	//{
	//	cout << *it << endl; // 输出 "ccc","bbb","aaa" 
	//};
	//li2.assign(3, "aa");
	//for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	//{
	//	cout << *it << endl; // 输出 "aa","aa","aa"
	//};

	// 使用 assign (仅顺序容器)
	// 用 assign 实现将一个 vector 中的一段 char* 值赋予一个 list 中的 string 
	list<string> names;
	vector<const char*> oldstyle{ "aa","bb","cc" };
	//names = oldstyle; // 错误：容器类型不匹配
	names.assign(oldstyle.begin(), oldstyle.end()); // 正确，可以将 const char* 转换为 string 
	//for (list<string>::iterator it = names.begin(); it != names.end(); it++)
	//{
	//	cout << *it << endl; // 输出 "aa","bb","cc"
	//};
	// 使用 swap 
	// 交换两个容器内容的操作保证会很快，元素本身并未交换，swap 只是交换了两个容器的内部数据结构
	// 对一个 string 使用 swap 会导致迭代器/引用和指针失效
	// 与其他容器不同，swap 两个 array 会真正交换它们的元素，因此交换两个 array 所需的时间与 array 中元素的数目成正比
	// 因此，对于 array 在 swap 操作之后，指针/引用/和迭代器所绑定的元素保持不变，但元素值已经与另一个 array 中对应元素的值进行了交换

	// 顺序容器操作
	// 向顺序容器添加元素，这些操作会改变容器的大小
	// forward_list 有自己专属版本的 insert 和 emplace
	// forward_list 不支持 push_back 和 emplace_back
	// vector 和 string 不支持 push_front 和 emplace_front
	vector<int> test = { 1,2,3 };
	vector<int> test1 = { 5,5,5 };
	test.emplace_back(1); // 问题：emplace_back 和 push_back 有什么不同
	test.insert(test.end() - 1, 2); // c.insert(p,t)
	test.emplace(test.end() - 1, 3); // c.emplace(p,args)
	test.insert(test.begin(), 3, 0); // c.insert(p,n,t)
	test.insert(test.begin(), test1.begin(), test1.end() - 1); // c.insert(p,b,e)
	test.insert(test.begin(), { 8,8,8,8 }); // c.insert(p,il) il==> 初始化列表

	//for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
	//{
	//	cout << *it << endl; // 输出 1
	//};
	// 注意：向一个 vector/string/deque 插入元素会使所有指向容器的迭代器/引用和指针失效。

	// 插入范围内元素
	// 传递给添加元素的目标容器不能指向自己
	vector<string> slist{ "aa","bb","cc" };
	vector<string> v{ "quasi","simba","frollo","scar" };
	// 将 v 的最后两个元素添加到 slist 的开始位置
	slist.insert(slist.begin(), v.end() - 2, v.end()); // 这里犯了迷糊，v.end() 是指向容器最后位置的下一个元素，但 insert 第三个形参是不包括这个，所以最后两个元素 实参是应该这样写 v.end() - 2,v.end();
	slist.insert(slist.begin(), { "three","words","will","go","at","the","end" });
	//for (vector<string>::iterator it = slist.begin(); it != slist.end(); it++)
	//{
	//	cout << *it << endl; // 输出 1
	//};

	// emplace 将参数传递给元素类型的构造函数
	// 适用于自定义类型，比如类，这个时候 push_back 只能 push 类的对象，而 emplace 可以直接写入构造函数

	// 访问元素
	// 包括 array 在内的每个顺序容器都有一个 front 成员函数，而除 forward_list 之外的所有顺序容器都有一个 back 成员函数
	// 这两个操作分别返回首元素和尾元素的引用
	// 确保容器非空，直接方法如上，间接方法通过解引用 begin 返回的迭代器来获得首元素的引用，以及 递减end迭代器解引用获得尾元素
	// at 和 下标操作只适用于 string,vector,deque 和 array
	// 访问成员函数返回的是引用

	// 删除元素
	// forward_list 有特殊版本的 erase
	// forward_list 不支持 pop_back ;vector 和 string 不支持 pop_front
	// c.clear() 删除 c 中的所有元素,返回 void
	// 注意：删除 deque 中除首尾位置之外的任何元素都会使所有迭代器/引用和指针失效/
	// 指向 vector 或 string 中删除点之后位置的迭代器/引用和指针都会失效

	// 从容器内部删除一个元素
	// earse 返回指向删除(最后一个)元素之后位置的迭代器
	// 例如：
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto it = lst.begin();
	while (it != lst.end())
	{
		if (*it % 2) // 若元素为奇数
		{
			it = lst.erase(it); // 删除此元素
		}
		else
		{
			++it;
		};
	};
	//for (list<int>::iterator itBegin = lst.begin(); itBegin != lst.end(); itBegin++)
	//{
	//	cout << *itBegin << endl; // 输出 0,2,4,6,8
	//};

	// 特殊的 forward_list 操作
	// lst.before_begin()
	// lst.insert_after()
	// lst.emplace_after()
	// lst.erase_after()
	forward_list<int> flst{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin(); // 表示 flst 的"首前元素"
	auto curr = flst.begin(); // 表示 flst 中的第一个元素
	while (curr != flst.end())
	{
		if (*curr % 2) //若元素为奇数
			curr = flst.erase_after(prev); // 删除它并移动 curr
		else
		{
			prev = curr; // 移动迭代器 curr,指向下一个元素，prev 指向 curr 之前的元素
			++curr;
		}
	};
	for (forward_list<int>::iterator itBegin = flst.begin(); itBegin != flst.end(); itBegin++)
	{
		cout << *itBegin << endl; // 输出 0,2,4,6,8
	};

	// 改变容器大小
	// array 不支持 resize
	// 如果当前大小小于所要求的大小，容器后部的元素会被删除，如果当前大小小于新大小，会将新元素添加到容器后面
	// 如果 resize 缩小容器，则指向被删除元素的迭代器，引用，和指针都会失效；对 vector,string,deque 进行 resize 可能导致迭代器，指针和引用失效

	// 容器操作可能使迭代器失效
	// 使用失效的指针，引用或迭代器是一种严重的程序设计错误，很可能引起与使用未初始化指针一样的问题


	// 额外的 string 操作

	// 容器适配器
	// 三个顺序容器适配器：stack,queue,priority_queue

}


// 一个单词转换的 map
// 建立转换映射
map<string, string> buildMap(ifstream& map_file)
{
	map<string, string> trans_map;   // 保存转换规则
	string key;						 // 要转换的单词
	string value;					 // 替换后的内容
	// 读取第一个单词存入 key 中，行中剩余内容转入 value
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)  //  检查是否有转换规则
			trans_map[key] = value.substr(1);   // 跳过前导空格
		else
		{
			throw runtime_error("no rule for " + key);
		};
	};
	return trans_map;
};

// 生成抓换文本
const string& transform(const string& s, const map<string, string>& m)
{
	// 实际的转换工作；这部分是程序的核心
	auto map_it = m.find(s);
	// 如果单词在转换规则 map 中
	if (map_it != m.cend())
		return map_it->second;   // 使用替换短语
	else
		return s;				 // 否则返回原 string
}


// 单词转换程序
// transform:
void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);   // 保存转换规则
	string text;						   // 保存输入中的每一行
	while (getline(input, text))		   // 读一行输入
	{
		istringstream stream(text);        // 读取每个单词
		string word;
		bool firstword = true;             // 控制是否打印空格
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
				cout << " ";                // 在单词间打印一个空格
			// transform 返回它的第一个参数或其转换之后的形式
			cout << transform(word, trans_map);  // 打印输出
		};
		cout << endl;						// 完成一行的转换
	}
};
void CStudy01Class01::studyMap()
{
	// 关联容器
	// 
	// 按关键字有序保存元素
	// map  -->  关联数组，保存关键字-值对
	// set  -->  关键字即值,只保存关键字的容器
	// multimap  -->  关键字可重复出现的 map
	// multiset  -->  关键字可重复出现的 set
	// 
	// 无序集合
	// unordered_map  -->  用哈希函数组织的 map
	// unordered_set  -->  用哈希函数组织的 set
	// unordered_multimap  -->  哈希组织的 map:关键字可以重复出现
	// unordered_multimap  -->  哈希组织的 set:关键字可以重复出现

	// 定义
	map<string, size_t> word_count;  // 空容器
	// 列表初始化
	set<string> exclude = { "the","but","and","or","an","a","The","But","And","Or","An","A" };
	// 三个元素,authors 将姓映射为名
	map<string, string> authors = { {"Joyce","James"},{"Austen","Jane"},{"Dickens","Charles"} };

	// pair 类型
	pair<string, string> author{ "James","Joyce" };
	cout << author.first << " " << author.second << endl;  // James Joyce
	// make_pair(v1,v2)
	pair<int, string> stu = make_pair(1, "xdh");
	cout << stu.first << " " << stu.second << endl;

	// 关联容器操作
	// 类型别名
	// key_type  -->  此容器的 关键字 类型
	// mapped_type  -->  每个关键字关联的类型：只适用于 map
	// value_type  -->  对于 set,与 key_type 相同
	//					对于 map,为 pair<const key_type,mapped_type>
	set<string>::value_type v1;  // v1 是一个 string
	set<string>::key_type v2;    // v2 是一个 string

	map<string, int>::value_type v3;  // v3 是一个 pair<const string,int>
	map<string, int>::key_type v4;    // v4 是一个 string
	//map<string, int>::mapped_type v5; // v5 是一个 int

	// 关联容器迭代器
	// set 的迭代器是 const 的
	set<int> iset = { 0,1,2,3,4,5,6,7,8,9 };
	set<int>::iterator set_it = iset.begin();
	if (set_it != iset.end())
	{
		//*set_it = 42;  // 错误: set 中的关键字是只读的
		cout << *set_it << endl;
	};

	// 遍历关联容器
	word_count = { { "one",3 }, {"two",4} };
	// 获得一个指向首元素的迭代器
	auto map_it = word_count.cbegin();
	while (map_it != word_count.cend())
	{
		// 解引用迭代器，打印关键字-值对
		cout << map_it->first << map_it->second << endl;
		map_it++;  // one3  two4
	};

	// 关联容器的 insert 操作
	// 统计每个单词在输入中出现次数的一种更繁琐方法
	//map<string, size_t> word_count;
	//string word;
	//while (cin >> word)
	//{
	//	// 插入一个元素，关键字等于 word,值为1
	//	// 若 word 已在 word_count 中，insert 什么也不做
	//	auto ret = word_count.insert({ word,1 });
	//	if (!ret.second)
	//		++ret.first->second;  // 递增计数器
	//};
	ifstream map_file;
	ifstream input;
	word_transform(map_file, input);

}



//// 运算符重载实现为非类的成员函数（即全局函数）
//class person
//{
//public:
//    int age;
//};
//
//// 左操作数的类型必须被显式指定
//    // 此处指定的类型为person类
//bool operator==(person const& p1, person const& p2)
//{
//    if (p1.age == p2.age)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

////  函数模板
//template <typename T>       //声明使用模板,并定义T是一个模板类型
//
//void Swap(T& a, T& b)           //紧接着使用T
//{
//    T c = a;
//    a = b;
//    b = c;
//}

//// 函数模板排序
//template < typename T >
//void Sort(T a[], int len)
//{
//    for (int i = 1; i < len; i++)
//        for (int j = 0; j < i; j++)
//            if (a[i] < a[j])
//            {
//                T t = a[i];
//                a[i] = a[j];
//                a[j] = t;
//            }
//}

//// 函数模板打印
//template < typename T >
//void Println(T a[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << a[i] << ", ";
//    }
//    cout << endl;
//}

//// 多参数模板
//template<typename T1, typename T2, typename T3>
//T1 Add(T2 a, T3 b)
//{
//    return static_cast<T1>(a + b);
//}

//// 重载函数模板
//template <typename T>
//T Max(T a, T b)
//{
//    cout << "T Max(T a,T b)" << endl;
//    return a > b ? a : b;
//}
//
//template <typename T>
//T Max(T* a, T* b)                    //重载函数模板 
//{
//    cout << "T Max(T* a,T* b)" << endl;
//    return *a > *b ? *a : *b;
//}
//
//int Max(int a, int b)                //重载普通函数 
//{
//    cout << "int Max(int a,int b)" << endl;
//    return a > b ? a : b;
//}

//// 定义类模板
//template < typename T >
//class Operator
//{
//public:
//    T add(T a, T b)
//    {
//        return a + b;
//    }
//
//    T minus(T a, T b)
//    {
//        return a - b;
//    }
//
//    T multiply(T a, T b)
//    {
//        return a * b;
//    }
//
//    T divide(T a, T b)
//    {
//        return a / b;
//    }
//};
//string operator-(string& l, string& r)   //由于string类没有重载减号操作符,所以我们自定义一个
//{
//    return "Minus";
//}

// 值传递冒泡排序
//void swapArr(int* arr, int length)
//{
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j < length - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//
//        }
//    }
//}

// 打印值传递数组
//void sprintArr(int* arr, int length)
//{
//    cout << "指针传递后数组内的元素为：" << endl;
//    for (int i = 0; i < length; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}


// 圆周率
//const double PI = 3.14;
// 类和对象
// 设计一个类，求圆的周长
// 圆求周长的公式：2 * PI * 半径
//class Circle
//{
//    // 访问权限
//public:
//    // 属性
//    // 半径
//    int m_r;
//    // 行为
//    // 获取圆的周长
//    double calculateZC()
//    {
//        return 2 * m_r * PI;
//    };
//};
// 

// 类内对象成员
//class Phone
//{
//public:
//    Phone()
//    {
//        cout << "Phone 默认构造函数调用" << endl;
//    }
//    Phone(string m_PName) :m_PName(m_PName)
//    {
//        cout << "Phone 有参构造函数调用" << endl;
//    }
//    ~Phone()
//    {
//        cout << "Phone 析构函数调用" << endl;
//    }
//    string get_PName()
//    {
//        return m_PName;
//    }
//private:
//    string m_PName;
//};
// 封装-成员属性私有化
//class Person
//{
//public:
//    // 普通构造函数
//    // 无参构造函数-初始化列表
//    Person():m_Age(0), m_Hight(new int(1)), m_Weight(2)
//    {
//
//        cout << "Person 无参构造函数调用" << endl;
//    };
//    // 有参构造函数-初始化列表
//    // Phone m_Phone = d;  // 类内成员隐式转换法拷贝函数调用
//    //Person(int a,int b,int c,string d) : m_Age(a), m_Hight(new int(b)),m_Weight(c),m_Phone(d)
//    //{
//    //    //m_Hight = new int(b);
//    //    //m_Age = a;
//    //    cout << "Person 有参构造函数调用" << endl;
//    //};
//    // 拷贝构造函数-浅
//    //Person(const Person &p)
//    //{
//    //    // 将传入的人身上的所有属性，拷贝到我身上
//    //    m_Age = p.m_Age;
//    //    cout << "Person 拷贝构造函数调用" << endl;
//    //};
//    // 拷贝构造函数-深
//    Person(const Person &p)
//    {
//        // 重新开辟内存空间
//        m_Hight = new int(*p.m_Hight);
//        
//        // 将传入的人身上的所有属性，拷贝到我身上
//        m_Age = p.m_Age;
//        m_Weight = p.m_Weight;
//        //m_Hight = p.m_Hight; // 编译器默认实现就是这行代码
//        cout << "Person 拷贝构造函数调用" << endl;
//    };
//    ~Person()
//    {
//        if (m_Hight != NULL)
//        {
//            // 释放 自己 new 出的堆区的指针
//            delete m_Hight;
//            m_Hight = NULL;
//        }
//        cout << "Person 析构函数调用" << endl;
//    };
//    void setName(string name)
//    {
//        m_Name = name;
//    };
//    string getName()
//    {
//        return m_Name;
//    };
//    int getAge()
//    {
//        return m_Age;
//    }
//    int* getHight()
//    {
//        return m_Hight;
//    }
//    /*Phone getPhone()
//    {
//        return m_Phone;
//    }*/
//    static void func()
//    {
//        cout << "static void func 调用" << endl;
//    };
//
//public:
//    int m_Weight;
//private:
//    // 姓名-可读可写
//    string m_Name;
//    // 年龄-只读
//    int m_Age;
//    // 身高
//    int* m_Hight;
//    //Phone m_Phone;
//};
//
//Person work2()
//{
//    Person p1;
//    cout << (int*)&p1 << endl;
//
//    return p1;
//};
//void work3()
//{
//    Person P = work2();
//    cout << (int*)&P << endl;
//}
//void test01()
//{
//    Person p1;
//    cout << "p1的年龄为：" << p1.getAge() << "身高为：" << *p1.getHight() << "体重为：" << p1.m_Weight << endl;
//    Person p2(10,20,30,"华为mate40_Pro");
//    cout << "p2的年龄为：" << p2.getAge() << "身高为：" << *p2.getHight() << "体重为：" << p2.m_Weight << "手机：" << p2.getPhone().get_PName() << endl;
//}
//class EmptyClass
//{
//public:
//    EmptyClass()
//    {
//
//    };
//    EmptyClass(int coun)
//    {
//        this->coun = coun;
//    };
//    ~EmptyClass()
//    {
//
//    };
//    EmptyClass addCout(EmptyClass &p)
//    {
//        this->coun += p.coun;
//        return *this;
//    }
//    void testNullptr1()
//    {
//        cout << "空指针调用成员函数了" << endl;
//    };
//    void testNullptr2()
//    {
//        // 此处代码等价于 cout << "空指针调用成员函数-获取成员变量值" << this.m_Str << endl;
//        cout << "空指针调用成员函数-获取成员变量值" << m_Str << endl;
//    };
//    int coun;
//    string m_Str;
//};
//void test02()
//{
//    // 1.通过对象调用
//    //Person p;
//    EmptyClass p(1);
//    EmptyClass p2(0);
//    cout << p2.addCout(p).addCout(p).addCout(p).cout << endl;
//
//    //p.func();
//    
//    // 2.通过类名访问
//    //Person::func();
//}
//void test03()
//{
//    EmptyClass* p = NULL;
//    //p->testNullptr1();
//    p->testNullptr2();
//}

// 常对象
//void test04()
//{
//    const testConstFunc test;  // 在对象前加 const 变为常对象
//    //test.m_A = 100;
//    test.m_B = 200;
//    test.showTest();
//    //test.showTest2();
//};
//class testConstFunc
//{
//public:
//    testConstFunc()
//    {
//
//    }
//    // this 指针的本质是指针常量即: testConstFunc* const this; 指针的指向是不可以修改的
//    // 而在成员函数后面加 const ,修饰的是 this 指向，让指针的值也不可以修改
//    // 等价于 const testConstFunc* const this;
//    void showTest() const
//    {
//        // 等价于 this->m-A = 100;
//        //m_A = 100; // 加上 const 后 就会报错
//        this->m_B;
//    }
//    void showTest2()
//    {
//
//    }
//
//public:
//    int m_A;
//    mutable int m_B; // 特殊变量，在常函数中也可以修改这个值
//};

//// 友元
//class Building
//{
//    // goodGay全局函数是 Building 好朋友，可以访问 Building 中私有成员
//    friend void goodGay(Building* building);
//public:
//    Building()
//    {
//        m_SittingRoom = "客厅";
//        m_BedRoom = "卧室";
//    }
//    ~Building()
//    {
//
//    }
//public:
//    string m_SittingRoom; // 客厅
//private:
//    string m_BedRoom; // 卧室
//};
//class Building; // 告诉编辑器一会会写这个类，别报错
//// 全局函数
//void goodGay(Building *building)
//{
//    cout << "好基友的全局函数 正在访问：" << building->m_SittingRoom << endl;
//    cout << "好基友的全局函数 正在访问：" << building->m_BedRoom << endl;
//}
//void test04()
//{
//    Building building;
//    goodGay(&building);
//}
// 友元类
//class GoodGay
//{
//public:
//    GoodGay();
//    void visit(); // 参观函数 访问Building中的属性 让 visit函数可以访问 Building 中私有成员
//    void visit2(); // 让 visit2 函数不可以访问 Building 中私有成员
//    Building* building;
//};
//// 类外写成员函数
//class Building
//{
//    friend void GoodGay::visit();
//public:
//    Building();
//    string m_SittingRoom; // 客厅
//private:
//    string m_BedRoom; // 卧室
//};
//// 如果不写作用域，编辑器不知道谁是属于谁的构造函数
//Building::Building()
//{
//    m_SittingRoom = "客厅";
//    m_BedRoom = "卧室";
//
//};
//GoodGay::GoodGay()
//{
//    // 创建一个建筑物的对象
//    building = new Building;
//}
//void GoodGay::visit()
//{
//    cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
//    cout << "好基友类正在访问：" << building->m_BedRoom << endl;
//}
//void GoodGay::visit2()
//{
//    cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
//    cout << "好基友类正在访问：" << building->m_BedRoom << endl;
//}
//void test05()
//{
//    GoodGay gg;
//    gg.visit(); 
//    gg.visit2();
//}

// 继承
//class Java
//{
//public:
//    Java()
//    {
//
//    };
//    void header()
//    {
//        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//    };
//    void footer()
//    {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    };
//    void left()
//    {
//        cout << "Java、Python、C++...(公共分类列表)" << endl;
//    };
//    void content()
//    {
//        cout << "Java学科视频" << endl;
//    };
//};
//// Python页面
//class Python
//{
//public:
//    Python()
//    {
//
//    };
//    void header()
//    {
//        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//    };
//    void footer()
//    {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    };
//    void left()
//    {
//        cout << "Java、Python、C++...(公共分类列表)" << endl;
//    };
//    void content()
//    {
//        cout << "Python学科视频" << endl;
//    };
//};
//// C++页面
//class CPP
//{
//public:
//    CPP()
//    {
//
//    };
//    void header()
//    {
//        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//    };
//    void footer()
//    {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    };
//    void left()
//    {
//        cout << "Java、Python、C++...(公共分类列表)" << endl;
//    };
//    void content()
//    {
//        cout << "CPP学科视频" << endl;
//    };
//};
// 继承实现页面
//class BasePage
//{
//public:
//    BasePage()
//    {
//        
//    };
//    void header()
//    {
//        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//    };
//    void footer()
//    {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    };
//    void left()
//    {
//        cout << "Java、Python、C++...(公共分类列表)" << endl;
//    };
//};
//class Java : public BasePage
//{
//public:
//    Java()
//    {
//
//    };
//    void content()
//    {
//
//    };
//};
//class Python : public BasePage
//{
//public:
//    Python()
//    {
//
//    };
//    void content()
//    {
//        cout << "Python学科视频" << endl;
//    };
//};
//class CPP : public BasePage
//{
//public:
//    CPP()
//    {
//
//    };
//    void content()
//    {
//        cout << "CPP学科视频" << endl;
//    };
//};
//
//void test06()
//{
//    cout << "Java下载视频页面" << endl;
//    Java ja;
//    ja.header();
//    ja.footer();
//    ja.left();
//    ja.content();
//
//    cout << "------------------------------" << endl;
//    cout << "Python下载视频页面" << endl;
//    Python py;
//    py.header();
//    py.footer();
//    py.left();
//    py.content();
//
//    cout << "------------------------------" << endl;
//    cout << "CPP下载视频页面" << endl;
//    CPP cp;
//    cp.header();
//    cp.footer();
//    cp.left();
//    cp.content();
//}


// 类模板与函数模板区别
//template<class NameType,class AgeType = int>
//class Person
//{
//public:
//    Person(NameType name, AgeType age) : m_Name(name),m_Age(age)
//    {
//        //this->m_Name = name;
//        //this->m_Age = m_Age;
//    }
//    NameType showName()
//    {
//        return this->m_Name;
//    }
//    NameType m_Name;
//    AgeType m_Age;
//};
//void test07()
//{
//    //Person("张三", 18);
//    Person<string, int> p("张三",18);
//    cout << p.showName() << "的年龄为：" << p.m_Age << endl;
//
//    Person<string> p1("李四", 20);
//}


// 类模板对象做函数参数
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name, T2 age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }
//    void showPerson()
//    {
//        cout << "姓名：" << this->m_Name << "年龄：" << this->m_Age << endl;
//    }
//
//    T1 m_Name;
//    T2 m_Age;
//};
//// 1.指定传入类型
//void printPerson1(Person<string, int>&p)
//{
//    p.showPerson();
//}
//// 2.参数模板化
//template<class T1,class T2>
//void printPerson2(Person<T1,T2>&p)
//{
//    p.showPerson();
//    // 利用 typeid 判断模板的类型
//    cout << "T1 的类型为：" << typeid(T1).name() << endl;
//    cout << "T2 的类型为：" << typeid(T2).name() << endl;
//}
//// 3.整个类模板化
//template<class T>
//void printPerson3(T &p)
//{
//    p.showPerson();
//    // 利用 typeid 判断模板的类型
//    cout << "T 的类型为：" << typeid(T).name() << endl;
//}
//void test08()
//{
//    //Person<string, int> p1("孙悟空", 100);
//    //printPerson1(p1);
//    Person<string, int> p2("猪八戒", 90);
//    printPerson2(p2);
//    Person<string, int> p3("唐僧", 1000);
//    printPerson3(p3);
//}


// 类模板与继承
//template<class T1,class T2>
//class Base
//{
//public:
//    Base(T1 name, T2 age);
//    void showName();
//    T1 m_N;
//    T2 m_A;
//    
//};

//class Son:public Base
//class Son:public Base<int> // 告诉父类中的 T 是  int 类型
//{
//public:
//    Son()
//    {
//
//    }
//};
// 如果想灵活指定父类中 T 类型，子类也需要变类模板
// 这个时候就很抽象了，父类模板中成员必须为T指定类型，我们子类在继承的时候传入的参数为T2，所以子类也需要变成类模板
// 子类变成类模板接收参数 T1 T2，T1是成员变量的类型，下面构造实例的时候 Son2<string,int> s2 指定了 T1为string,T2为int,这个T2也传给了父类
//template<class T1,class T2>
//class Son2 :public Base<T2>
//{
//public:
//    Son2(T1 name,T2 age):m_Obj(name), m_Age(age)
//    {
//
//    }
//    T1 m_Obj;
//    T2 m_Age;
//};
//void test09()
//{
//    Son2<string,int> s2("张三",18);
//}
// 构造函数类外实现
//template<class T1, class T2> // 如果不写，编辑器不认识T1,T2
//Base<T1,T2>::Base(T1 name, T2 age) // 类外实现加作用域,还需要加 T1,T2，告诉编辑器这是类模板的类外实现
//{
//    this->m_N = name;
//    this->m_A = age;
//}
//// 成员函数类外实现
//template<class T1, class T2> // 如果不写，编辑器不认识T1,T2
//void Base<T1, T2>::showName()
//{
//    cout << this->m_N << endl;
//}

// 类模板与友元
// 通过全局函数 打印Person信息
template<class T1, class T2> // 还需要让编辑器知道它是一个模板
class Person;// 写在前面，让编辑器知道Person 的存在
// 全局函数类外实现 函数模板的实现，所以声明的时候也要使用函数模板的形式
// 写在前面，让编译器提前知道这个函数的存在
template<class T1, class T2>
void printPersonInfo2(Person<T1, T2> p)
{
	cout << "类外实现的内容 --- 姓名：" << p.m_Name << "年龄:" << p.m_Age << endl;
};
template<class T1, class T2>
class Person
{
	// 全局函数类内实现  参数模板化的方式进行传参
	//friend void printPersonInfo1(Person<T1, T2> p)
	//{
	//    cout << "姓名：" << p.m_Name << "年龄:" << p.m_Age << endl;
	//}
	// 全局函数类外实现
	//friend void printPersonInfo2(Person<T1, T2> p); --错误写法
	// 如果全局函数 是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPersonInfo2<>(Person<T1, T2> p); // 加一个空模板参数列表

public:
	Person(T1 name, T2 age) :m_Name(name), m_Age(age)
	{

	}
	T1 m_Name;
	T2 m_Age;
};


void test10()
{
	Person<string, int> p("Tom", 18);
	//printPersonInfo1(p);
	printPersonInfo2(p);
}
void CStudy01Class01::studyCPlusPlus()
{
	// 类实例化，~ virtual 析构函数 虚函数 一个基类的指针或者引用可以指向或者引用派生类的对象
	//class base
	//{
	//    int a, b;
	//public:
	//    virtual void test() { cout << "基类方法！" << endl; }
	//    virtual ~base() {};
	//};

	//class inheriter :public base
	//{
	//public:
	//    void test() { cout << "派生类方法!" << endl; } // 重写基类方法
	//};

	//base* p1 = new base;
	//base* p2 = new inheriter;
	//p1->test();
	//p2->test();

	// 虚基类
	//class base
	//{
	//    int b;
	//public:
	//    virtual void test() { cout << "基类方法" << endl; };
	//    virtual ~base() {};
	//};
	//class mytest :virtual public base
	//{
	//
	//};
	//class mytest2 :virtual public base
	//{
	//
	//};
	//class mytest3 :public mytest, public mytest2
	//{
	//
	//};
	//
	//cout << sizeof(mytest) << endl;                  //输出12
	//cout << sizeof(mytest2) << endl;                 //输出12
	//cout << sizeof(mytest3) << endl;                 //输出16

	// 重写基类的虚函数
	//class Base
	//{
	//    virtual void f();
	//};
	//class Derived : public Base {
	//    void f() override; // 表示派生类重写基类虚函数f
	//    void F() override;//错误：函数F没有重写基类任何虚函数
	//};

	// 重载运算符实现为类的成员函数
	//class person
	//{
	//private:
	//    int age;
	//public:
	//    person(int nAge)
	//    {
	//        this->age = nAge;
	//    }

	//    bool operator==(const person& ps)
	//    {
	//        if (this->age == ps.age)
	//        {
	//            return true;
	//        }
	//        return false;
	//    }
	//};
	//person p1(10);
	//person p2(10);

	//if (p1 == p2)
	//{
	//    cout << "p1 is equal with p2." << endl;
	//}
	//else
	//{
	//    cout << "p1 is not equal with p2." << endl;
	//};

	/*person p1;
	person p2;
	p1.age = 18;
	p2.age = 18;

	if (p1 == p2)
	{
		cout << "p1 is equal with p2." << endl;
	}
	else
	{
		cout << "p1 is NOT equal with p2." << endl;
	};*/

	//// 函数模板调用
	//int a = 0;
	//int b = 1;

	//Swap(a, b);                   //自动调用,编译器根据a和b的类型来推导
	//cout << a << b << endl;

	//float c = 0;
	//float d = 1;
	//Swap<float>(c, d);           //显示调用,告诉编译器,调用的参数是float类型
	//cout << c << d << endl;
	//// 调用函数模板 排序和打印数组
	//int ww[5] = { 5, 3, 2, 4, 1 };
	//Sort(ww, 5);            //自动调用,编译器根据a和5的类型来推导
	//Println<int>(ww, 5);    //显示调用,告诉编译器,调用的参数是int类型
	//string s[5] = { "Java", "C++", "Pascal", "Ruby", "Basic" };
	//Sort(s, 5);
	//Println(s, 5);

	//// 多参数模板调用
	////int ad = Add(1,1.5);       //该行编译出错,没有指定返回值类型

	//int aa = Add<int>(1, 1.5);
	//cout << aa << endl;                  //2

	//float bb = Add<float, int, float>(1, 1.5);
	//cout << bb << endl;                  //2.5

	//// 重载函数模板
	//int a = 0;
	//int b = 1;
	//cout << "a:b=" << Max(a, b) << endl;        //调用普通函数 Max(int,int)
	//cout << "a:b=" << Max<>(a, b) << endl;        //通过模板参数表 调用 函数模板 Max(int,int)
	//cout << "1.5:2.0=" << Max(1.5, 2.0) << endl;
	////由于两个参数默认都是double,所以无法隐式转换,则调用函数模板 Max(double,double)
	//int* p1 = new int(1);
	//int* p2 = new int(2);
	//cout << "*p1:*p2=" << Max(p1, p2) << endl;  // 调用重载函数模板 Max(int* ,int* )    
	//cout << "'a',100=" << Max('a', 100) << endl;
	////将char类型进行隐式转换,从而调用普通函数 Max(int,int)
	//delete p1;
	//delete p2;

	//// 调用类模板
	//Operator<int>  op1;            //定义对象时,需要指定类模板类型
	//cout << op1.add(1, 2) << endl;
	//Operator<string>  op2;         //定义对象时,需要指定类模板类型
	//cout << op2.add("D.T.", "Software") << endl;
	//cout << op2.minus("D.T", "Software") << endl;


	//int* poingArr = new int[2]{2,1};
	//cout << *poingArr << endl;
	//cout << poingArr[0] << endl;
	//cout << poingArr[1] << endl;
	//cout << typeid(poingArr).name() << endl;


// 逆置数组
// 创建数组
//int arr[6] = { 1,3,2,5,4,6 };
//// 数组长度
//int arrLength = sizeof(arr) / sizeof(arr[0]);
//// 打印数组元素
//cout << "数组逆置前元素为：" << endl;
//for (int i = 0; i < arrLength; i++)
//{
//    cout << arr[i] << endl;
//}
//// 实现逆置
//// 记录起始下标位置
//int start = 0;
//// 记录结束下标位置
//int end = arrLength - 1;
//
//// 实现循环
//while (start < end)
//{
//    // 起始下标与结束下标的元素互换
//    int temp = arr[start];
//    arr[start] = arr[end];
//    arr[end] = temp;
//    // 下标更新
//    start++;
//    end--;
//}
//// 打印逆置后的数组元素
//cout << "数组逆置后元素为：" << endl;
//for (int i = 0; i < arrLength; i++)
//{
//    cout << arr[i] << endl;
//}


// 冒泡排序
//int arr[9] = { 4,2,8,0,5,7,1,3,9 };
//// 数组长度
//int arrLength = sizeof(arr) / sizeof(arr[0]);
//cout << "排序前的数组元素：" << endl;
//for (int i = 0; i < 9; i++)
//{
//    cout << arr[i] << "";
//}
//cout << endl;
//// 开始排序
//// 排序总轮数 = 元素个数 - 1;
//for (int i = 0; i < arrLength - 1; i++)
//{
//    // 内层循环对比
//    // 每轮对比次数 = 元素个数 - 排序轮数 - 1;
//    for (int j = 0; j < arrLength - i - 1; j++)
//    {
//        // 如果第一个数字，比第二个数字大，交换两个数字
//        if (arr[j] > arr[j + 1])
//        {
//            int temp = arr[j];
//            arr[j] = arr[j + 1];
//            arr[j + 1] = temp;
//        }
//    }
//}
//// 打印排序后数组
//cout << "排序后的数组元素：" << endl;
//for (int i = 0; i < 9; i++)
//{
//    cout << arr[i] << "";
//}
//cout << endl;


// 二维数组
// 第一种定义方式
//int arr1[2][3];
//arr[0][0] = 1;
//arr[0][1] = 2;
//arr[0][2] = 3;
//arr[1][0] = 4;
//arr[1][1] = 5;
//arr[1][2] = 6;
// 第二种定义方式
//int arr2[2][3] = 
//{
//    {1,2,3},
//    {4,5,6}
//};
// 第三种定义方式
//int arr3[2][3] = { 1,2,3,4,5,6 };
// 
// 第四种定义方式
//int arr4[][3] = { 1,2,3,4,5,6 };
//// 打印二维数组中的元素
//for (int i = 0;i < 2; i++)
//{
//    for (int j = 0; j < 3; j++)
//    {
//        cout << arr4[i][j] << " ";
//        
//    }
//    cout << endl;
//}


// 二维数组名称用途
//int arr[2][3] =
//{
//    {1,2,3},
//    {4,5,6}
//};
//cout << "二维数组占用内存空间为：" << sizeof(arr) << endl;
//cout << "二维数组第一行占用内存空间为：" << sizeof(arr[0]) << endl;
//cout << "二维数组第一个元素占用内存空间为：" << sizeof(arr[0][0]) << endl;
//cout << "二维数组行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
//cout << "二维数组列数为：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
//cout << "二维数组首地址为：" << (int)arr << endl;
//cout << "二维数第一行首地址为：" << (int)arr[0] << endl;
//cout << "二维数组第一个元素首地址为：" << (int)&arr[0][0] << endl;


//指针
//int a = 3;
//// const 修饰指针
//// 常量指针
//const int* p = &a;
//int b = 4;
//*p = 4; // 错误
//p = &b;
//// 指针常量
//int* const p1 = &a;
//*p1 = 4; 
//p1 = &b; // 错误
//// 常量指针常量
//const int* const p2 = &a;
//*p2 = 4; // 错误
//p2 = &b; // 错误
//// 记忆
//// const 后面是 * p,所以 *P 不能修改
//// const 后面是 p,所以 P 不能修改


// 指针数组
//// 利用指针访问数组中的元素
//int arr[5] = { 1,2,3,4,5 };
//cout << "数组第一个元素为：" << arr[0] << endl;
//int* p = arr;
//cout << "利用指针访问数组第一个元素为：" << *p << endl; // 1
//p++; // 让指针向后偏移 4 个字节，因为指针类型 为 int ;
//cout << "利用指针访问数组第二个元素为：" << *p << endl; // 2
//// 利用指针遍历数组
//int arr2[10] = { 1,2,3,4,5,3,5,6,7,9 };
//int* p2 = arr2;
//for (int i = 0; i < 10; i++)
//{
//    //cout << arr2[i] << endl;
//    cout << *p2 << endl;
//    p2++;
//}


// 值传递
//int arr[5] = { 2,3,4,1,5 };
//int lengthArr = sizeof(arr) / sizeof(arr[0]);
//swapArr(arr, lengthArr);
//sprintArr(arr, lengthArr);


// 结构体
// 自定义数据类型
//struct Student
//{
//    string name;
//    int age;
//    int score;
//}s3;
// 通过学生类型创建具体学生
// 1.struct 结构体 变量名
//struct Student s1;
//s1.name = "zhangsan";
//s1.age = 18;
//s1.score = 98;
// 2.struct 结构体名 变量名 = {成员1值,成员2值};
//struct Student s2 = { "lisi",20,99 };
// 3.定义结构体时顺便创建变量
//s3.name = "wanger";
//s3.age = 24;
//s3.score = 100;

// 结构体数组
//struct Student stuArray[3] =
//{
//    {"张三",18,87},
//    {"李四", 19, 98},
//    {"王二",22,100}
//};
// 结构体指针
//Student s = { "张三",18,80 };
//Student* p = &s;
//p->name = "李四";
//p->age = 25;
//p->score = 98;

// 通过圆类 创建具体的圆(对象) -- 实例化
//Circle c1;
//// 给圆对象的属性进行赋值
//c1.m_r = 10;
//cout << "圆的周长为：" << c1.calculateZC() << endl;

// 构造函数调用
// 1.括号法
// 调用默认构造函数的时候不要加 (),因为编译器会认为这是一个函数的声明
//Person p1; // 默认(无参)构造函数调用
//Person p2(10);
//cout << p2.getAge() << endl;
//Person p3(p2);
//cout << p3.getAge() << endl;
// 2.显示法
//Person p1;
//Person p2 = Person(18); // 有参构造
//Person p3 = Person(p2); // 拷贝构造
// Person(12); // 匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
// 注意：不要利用拷贝构造函数 初始化匿名对象
// Person(p3)  // 编辑器会认为 Person(p3) === Person p3; 是一个对象声明
// 3.隐式转换法
//Person p4 = 10; // 相当于 Person p4 = Person(10);
//Person p5 = p4;

// 拷贝构造函数调用时机
// 2.以值传递的方式 给函数参数传递
// 3.以值方式返回局部对象
//work3();

// 深拷贝和浅拷贝
//test01();
//test02();
//test03();
//test04();
//test05();
//test06();
//test07();
//test08();
//test09();
	test10();
}
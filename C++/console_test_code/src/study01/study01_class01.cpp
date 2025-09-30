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

	Blob() {};  // ���캯��
	Blob(std::initializer_list<T> il) {};

	// Blob �е�Ԫ����Ŀ
	size_type size() const
	{
		return data->size();
	}

	bool empty() const { return data->empty(); }

	// ��Ӻ�ɾ��Ԫ��
	void push_back(const T& t) { data->push_back(t); }
	// �ƶ��汾
	void push_back(T&& t)
	{
		data->push_back(std::move(t));
	}
	void pop_back()
	{
		check(0, "pop_back on empty Blob");
		data->pop_back();
	}


	// Ԫ�ط���
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
	// �� data[i] ��Ч�����׳� msg
	void check(size_type i, const string& msg) const;
};
// �� data[i] ��Ч�����׳� msg
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

	// ����
	/*string ss = "xml";
	regex ip_reg = regex(ss);
	string content = "agjdkflsajdxmljdklflaskjdf";
	if (!std::regex_search(content, ip_reg))
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << endl;
	};*/
	// ����
	//regex reg = regex("@");
	//string cxt = "shade_close@200.png";
	//if (!std::regex_search(cxt, reg))
	//{
	//    cout << "û�ҵ�" << endl;
	//}
	//else
	//{
	//    cout << "�ҵ�" << endl;
	//};
}

void CStudy01Class01::testRegexMatch()
{

}

void CStudy01Class01::testRegexMatchBool()
{
	// regex_match �Ƿ�ȫ����ȫƥ��
	const std::regex regex_obj_bool{ R"(\d{3}-\d{5})" };
	const std::string match_str_yes = "123-12345";
	const std::string match_str_no = "123-12345a";
	const bool matched_yes = std::regex_match(match_str_yes, regex_obj_bool);
	const bool matched_no = std::regex_match(match_str_no, regex_obj_bool);
	std::cout << "matched_yes ==> result = " << (matched_yes ? "yes" : "no") << std::endl;
	std::cout << "matched_no ==> result = " << (matched_no ? "yes" : "no") << std::endl;

	// regex_match ȫ����ȫƥ�䲢��ȡ����
	const std::regex re{ R"(\S+)" };
	const std::string str = "Loremipsumdoorsitametconsectetur";
	const std::sregex_iterator begin{ str.cbegin(), str.cend(), re }, end;
	const auto count = std::distance(begin, end);
	std::cout << count << std::endl;
}


void CStudy01Class01::testRegexSearch()
{
	string file_path = "study_res/regex.txt";
	// ios::in ֻ��
	//ifstream txt_file(R"(study/regex.txt)", ios::in);
	ifstream txt_file;
	txt_file.open(file_path);
	if (!txt_file.is_open())
	{
		std::cerr << "���ļ�ʧ��,file_path = " << file_path << std::endl;
		return;
	}
	istreambuf_iterator<char> begin(txt_file), end;
	string target_str(begin, end);
	txt_file.close();
	// \s ƥ���κοհ��ַ� 
	// *  ƥ��0�λ���
	// \d ƥ������
	// R vs 2019���߼�д��
	//const regex regex_obj{ R"((cy|cx)\s*\=\s*(\d+))" };
	// vs 2012 д��
	string regex_str = "(cy|cx)\\\s*\\\=\\\s*(\\\d+)";
	const regex regex_obj(regex_str);

	smatch search_result;
	string::const_iterator it_start = target_str.begin();
	string::const_iterator it_end = target_str.end();
	vector<string> cx;
	vector<string> cy;
	// regex_search ��һ�����õ����� ��������,-----������������
	for (; regex_search(it_start, it_end, search_result, regex_obj); it_start = search_result.suffix().first)
	{
	    // search_result.str() ��ƥ���ȫ���ַ���
	    // search_result.str(1) ��ƥ��� ��һ������
	    // search_result.str(2) ��ƥ��� �ڶ�������
	    if (search_result.str(1) == "cx")
	    {
	        cx.push_back(search_result.str(2));
	    }
	    else if (search_result.str(1) == "cy")
	    {
	        cy.push_back(search_result.str(2));
	    };
	    // �������������� 0��ƥ���ȫ���ַ�����1�ǵ�һ�飬2�ǵڶ���
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
	// regex_search �ڶ��������±� ��������-----������һ��ͷ���
	if (regex_search(target_str, search_result, regex_obj))
	{
		//��ӡ�ӱ��ʽ���
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


	// ��ӡ���
	for (vector<string>::const_iterator itercx = cx.cbegin(); itercx != cx.cend(); itercx++) {
		cout << (*itercx) << endl;
	}
	for (vector<string>::const_iterator itercy = cy.cbegin(); itercy != cy.cend(); itercy++) {
		cout << (*itercy) << endl;
	}

}

void CStudy01Class01::testRegexSearchBool()
{
	// regex_search �Ƿ�ֲ�ƥ��
	// ^ ƥ���ַ�����ʼλ��
	//		���ڷ������У���ʾ��
	//		ƥ�� ^ �ַ�������ʹ�� \^
	// $ ƥ�������ַ�����β��λ��
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

// �����ڴ�
void testreq01()
{
	A* a1 = new A();
	a1->SetI(3);
	cout << a1->GetI() << endl;  // 3
	new(a1)A; // �������е��ڴ�  ֱ��ִ��  a1 �Ĺ��캯��
	cout << a1->GetI() << endl;  // 0

	char* tempMem = (char*)::operator new(12); // ����һ�� 12 �ֽڵ��ڴ�
	void* tempMem2 = (void*)::malloc(12); // Ҳ���� ����� �������ڴ�
	A* a3 = new(tempMem2)A;  // �ø����������ڴ�ִ�� A �Ĺ��캯�� ���� a3 ָ��ָ����

	//::operator delete(tempMem);
	free(tempMem2);
	delete a3;


	delete a1;
	A* a2 = new A[3];
	delete[]a2;

	cout << sizeof(A) << endl;
}
// ǿ��ת��
void testtransform02()
{
	int num = 0x00636261;//��16���Ʊ�ʾ32λint��0x61���ַ�'a'��ASCII��
	int* pnum = &num;
	char* pstr = reinterpret_cast<char*>(pnum);
	cout << "pnumָ���ֵ: " << pnum << endl;
	cout << "pstrָ���ֵ: " << static_cast<void*>(pstr) << endl;//ֱ�����pstr�������ָ����ַ��������������ת����Ϊ�˱�֤���pstr��ֵ
	cout << "pnumָ�������: " << hex << *pnum << endl;
	cout << "pstrָ�������: " << pstr << endl;
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
	cout << get<0>(item) << endl;  // get ���ʳ�Ա  ��� 0-999-78234-X
	typedef decltype(item) trans;

	size_t sz = tuple_size<trans>::value; // �ø�����ģ�� ��ѯ��Ա������������
	tuple_element<1, trans>::type cnt = get<1>(item);
	cout << cnt << endl;  // ��� 3 
	cout << sz << endl;  // ��� 3 

	// bitset // ���� bitset ��Ҫ�������������ٸ�������λ �� 0 ��ʼ��ţ��� 0 λ�����ұߵ�λ

	bitset<32> bitvec(1U);  // 32λ  ��λΪ1 ������λΪ0
	0xbeef;

	// �����
	// ���� ������� unsigned ��������
	//default_random_engine e; // ʹ�ø���������Ĭ�ϵ�����

	//default_random_engine e(1);  // ������ֵ��Ϊ����
	//string u;
	//default_random_engine e;
	//e.seed(u);  // ʹ������
	//e.min(); // ����������ɵ���Сֵ�����ֵ
	//e.max();
	//default_random_engine::result_type; // ���������ɵ� unsigned ��������
	//e.discard(u); // �������ƽ� u ����u ������Ϊ unsigned long long
	//for (unsigned int i = 0; i < 10; ++i)
	//{
	//    cout << e() << endl;
	//}

	// �ֲ�  ���ͣ�ʹ�����淵�ط����ض����ʷֲ��������
	// ָ����Χ�ڵ���
	uniform_int_distribution<unsigned> u(0, 19);
	default_random_engine e;
	for (unsigned int i = 0; i < 10; ++i)
	{
		// �� U ��Ϊ�����Դ
		// ÿ�����÷�����ָ����Χ�ڲ����Ӿ��ȷֲ���ֵ
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


// ���ͱ���
// iterator  ���������͵ĵ���������
// const_iterator ���Զ�ȡԪ�أ��������޸�Ԫ�صĵ���������
// size_type  �޷����������ͣ��㹻��������������������������Ĵ�С
// difference_type  �������������ͣ��㹻��������������֮��ľ���
// value_type  Ԫ������
// reference  Ԫ�ص���ֵ���ͣ��� value_type& ������ͬ��
// const_reference Ԫ�ص� const ��ֵ����(�� const value_type&)
void CStudy01Class01::studySTL()
{
	// vector
	// �ɱ��С���飬֧�ֿ���������ʣ���β��֮���λ�ò����ɾ��Ԫ�ؿ��ܺ���
	// ���캯��
	vector<int> vc;
	vector<int> vc1(vc);
	vector<int>::iterator beginVc = vc.begin(), endVc = vc.end();
	vector<int> vc2(beginVc, endVc);
	// �б��ʼ��
	vector<int> vc3{ 1,2,3,4,5 };
	// ��ֵ�� swap
	vc3 = vc;
	vc3 = { 1,3,5 }; // ������ array
	// ����Ԫ��
	vc3.swap(vc1);
	swap(vc3, vc1); // �������ǵȼ۵�
	// ��С
	size_t vec_size = vc.size(); // ��֧��forward_list��������
	size_t vec_max_size = vc.max_size(); //  �ɱ�������Ԫ����Ŀ
	bool is_empty = vc.empty(); // ����ֵ���ж��Ƿ�Ϊ��
	// ��Ӻ�ɾ��Ԫ��(�������� array )
	// ע���ڲ�ͬ�����У���Щ�����Ľӿڶ���ͬ


	// ��ʼ��
	vector<int> vd(2);  // �˹��캯���� explicit �ġ����ƹ��캯���������ʽת�� string ������
	vector<int> ve(3, 2);

	// array
	array<int, 42>;// ����һ�� array,����Ҫָ��Ԫ�����ͣ���Ҫָ��������С
	//array<int, 10> ial;
	array<int, 10> ia2 = { 0,1,2,3,4,5,6,7,8,9 }; // �б��ʼ��
	array<int, 10> ia3 = { 42 }; // ʣ��Ԫ��Ϊ0;
	// ���ܶ������������ͽ��п��������ֵ�������� array ���޴�����
	int digs[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//int cpy[10] = digs; // �����������鲻֧�ֿ�����ֵ
	array<int, 10> digits = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10> copy = digits; // ��ȷ��ֻҪ��������ƥ�伴�Ϸ�

	// assign ���������ù��������� array
	list<string> li{ "aaa","bbb","ccc" };
	list<string> li2{ "aa","bb","cc" };
	list<string>::const_iterator itBegin = li.begin(), itEnd = li.end();
	li2.assign(itBegin, itEnd);
	//for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	//{
	//	cout << *it << endl; // ��� aaa, bbb, ccc
	//};
	//li2.assign({ "ccc","bbb","aaa" });
	//for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	//{
	//	cout << *it << endl; // ��� "ccc","bbb","aaa" 
	//};
	//li2.assign(3, "aa");
	//for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	//{
	//	cout << *it << endl; // ��� "aa","aa","aa"
	//};

	// ʹ�� assign (��˳������)
	// �� assign ʵ�ֽ�һ�� vector �е�һ�� char* ֵ����һ�� list �е� string 
	list<string> names;
	vector<const char*> oldstyle{ "aa","bb","cc" };
	//names = oldstyle; // �����������Ͳ�ƥ��
	names.assign(oldstyle.begin(), oldstyle.end()); // ��ȷ�����Խ� const char* ת��Ϊ string 
	//for (list<string>::iterator it = names.begin(); it != names.end(); it++)
	//{
	//	cout << *it << endl; // ��� "aa","bb","cc"
	//};
	// ʹ�� swap 
	// ���������������ݵĲ�����֤��ܿ죬Ԫ�ر���δ������swap ֻ�ǽ����������������ڲ����ݽṹ
	// ��һ�� string ʹ�� swap �ᵼ�µ�����/���ú�ָ��ʧЧ
	// ������������ͬ��swap ���� array �������������ǵ�Ԫ�أ���˽������� array �����ʱ���� array ��Ԫ�ص���Ŀ������
	// ��ˣ����� array �� swap ����֮��ָ��/����/�͵��������󶨵�Ԫ�ر��ֲ��䣬��Ԫ��ֵ�Ѿ�����һ�� array �ж�ӦԪ�ص�ֵ�����˽���

	// ˳����������
	// ��˳���������Ԫ�أ���Щ������ı������Ĵ�С
	// forward_list ���Լ�ר���汾�� insert �� emplace
	// forward_list ��֧�� push_back �� emplace_back
	// vector �� string ��֧�� push_front �� emplace_front
	vector<int> test = { 1,2,3 };
	vector<int> test1 = { 5,5,5 };
	test.emplace_back(1); // ���⣺emplace_back �� push_back ��ʲô��ͬ
	test.insert(test.end() - 1, 2); // c.insert(p,t)
	test.emplace(test.end() - 1, 3); // c.emplace(p,args)
	test.insert(test.begin(), 3, 0); // c.insert(p,n,t)
	test.insert(test.begin(), test1.begin(), test1.end() - 1); // c.insert(p,b,e)
	test.insert(test.begin(), { 8,8,8,8 }); // c.insert(p,il) il==> ��ʼ���б�

	//for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
	//{
	//	cout << *it << endl; // ��� 1
	//};
	// ע�⣺��һ�� vector/string/deque ����Ԫ�ػ�ʹ����ָ�������ĵ�����/���ú�ָ��ʧЧ��

	// ���뷶Χ��Ԫ��
	// ���ݸ����Ԫ�ص�Ŀ����������ָ���Լ�
	vector<string> slist{ "aa","bb","cc" };
	vector<string> v{ "quasi","simba","frollo","scar" };
	// �� v ���������Ԫ����ӵ� slist �Ŀ�ʼλ��
	slist.insert(slist.begin(), v.end() - 2, v.end()); // ���ﷸ���Ժ���v.end() ��ָ���������λ�õ���һ��Ԫ�أ��� insert �������β��ǲ���������������������Ԫ�� ʵ����Ӧ������д v.end() - 2,v.end();
	slist.insert(slist.begin(), { "three","words","will","go","at","the","end" });
	//for (vector<string>::iterator it = slist.begin(); it != slist.end(); it++)
	//{
	//	cout << *it << endl; // ��� 1
	//};

	// emplace ���������ݸ�Ԫ�����͵Ĺ��캯��
	// �������Զ������ͣ������࣬���ʱ�� push_back ֻ�� push ��Ķ��󣬶� emplace ����ֱ��д�빹�캯��

	// ����Ԫ��
	// ���� array ���ڵ�ÿ��˳����������һ�� front ��Ա���������� forward_list ֮�������˳����������һ�� back ��Ա����
	// �����������ֱ𷵻���Ԫ�غ�βԪ�ص�����
	// ȷ�������ǿգ�ֱ�ӷ������ϣ���ӷ���ͨ�������� begin ���صĵ������������Ԫ�ص����ã��Լ� �ݼ�end�����������û��βԪ��
	// at �� �±����ֻ������ string,vector,deque �� array
	// ���ʳ�Ա�������ص�������

	// ɾ��Ԫ��
	// forward_list ������汾�� erase
	// forward_list ��֧�� pop_back ;vector �� string ��֧�� pop_front
	// c.clear() ɾ�� c �е�����Ԫ��,���� void
	// ע�⣺ɾ�� deque �г���βλ��֮����κ�Ԫ�ض���ʹ���е�����/���ú�ָ��ʧЧ/
	// ָ�� vector �� string ��ɾ����֮��λ�õĵ�����/���ú�ָ�붼��ʧЧ

	// �������ڲ�ɾ��һ��Ԫ��
	// earse ����ָ��ɾ��(���һ��)Ԫ��֮��λ�õĵ�����
	// ���磺
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto it = lst.begin();
	while (it != lst.end())
	{
		if (*it % 2) // ��Ԫ��Ϊ����
		{
			it = lst.erase(it); // ɾ����Ԫ��
		}
		else
		{
			++it;
		};
	};
	//for (list<int>::iterator itBegin = lst.begin(); itBegin != lst.end(); itBegin++)
	//{
	//	cout << *itBegin << endl; // ��� 0,2,4,6,8
	//};

	// ����� forward_list ����
	// lst.before_begin()
	// lst.insert_after()
	// lst.emplace_after()
	// lst.erase_after()
	forward_list<int> flst{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin(); // ��ʾ flst ��"��ǰԪ��"
	auto curr = flst.begin(); // ��ʾ flst �еĵ�һ��Ԫ��
	while (curr != flst.end())
	{
		if (*curr % 2) //��Ԫ��Ϊ����
			curr = flst.erase_after(prev); // ɾ�������ƶ� curr
		else
		{
			prev = curr; // �ƶ������� curr,ָ����һ��Ԫ�أ�prev ָ�� curr ֮ǰ��Ԫ��
			++curr;
		}
	};
	for (forward_list<int>::iterator itBegin = flst.begin(); itBegin != flst.end(); itBegin++)
	{
		cout << *itBegin << endl; // ��� 0,2,4,6,8
	};

	// �ı�������С
	// array ��֧�� resize
	// �����ǰ��СС����Ҫ��Ĵ�С�������󲿵�Ԫ�ػᱻɾ���������ǰ��СС���´�С���Ὣ��Ԫ����ӵ���������
	// ��� resize ��С��������ָ��ɾ��Ԫ�صĵ����������ã���ָ�붼��ʧЧ���� vector,string,deque ���� resize ���ܵ��µ�������ָ�������ʧЧ

	// ������������ʹ������ʧЧ
	// ʹ��ʧЧ��ָ�룬���û��������һ�����صĳ�����ƴ��󣬺ܿ���������ʹ��δ��ʼ��ָ��һ��������


	// ����� string ����

	// ����������
	// ����˳��������������stack,queue,priority_queue

}


// һ������ת���� map
// ����ת��ӳ��
map<string, string> buildMap(ifstream& map_file)
{
	map<string, string> trans_map;   // ����ת������
	string key;						 // Ҫת���ĵ���
	string value;					 // �滻�������
	// ��ȡ��һ�����ʴ��� key �У�����ʣ������ת�� value
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)  //  ����Ƿ���ת������
			trans_map[key] = value.substr(1);   // ����ǰ���ո�
		else
		{
			throw runtime_error("no rule for " + key);
		};
	};
	return trans_map;
};

// ����ץ���ı�
const string& transform(const string& s, const map<string, string>& m)
{
	// ʵ�ʵ�ת���������ⲿ���ǳ���ĺ���
	auto map_it = m.find(s);
	// ���������ת������ map ��
	if (map_it != m.cend())
		return map_it->second;   // ʹ���滻����
	else
		return s;				 // ���򷵻�ԭ string
}


// ����ת������
// transform:
void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);   // ����ת������
	string text;						   // ���������е�ÿһ��
	while (getline(input, text))		   // ��һ������
	{
		istringstream stream(text);        // ��ȡÿ������
		string word;
		bool firstword = true;             // �����Ƿ��ӡ�ո�
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
				cout << " ";                // �ڵ��ʼ��ӡһ���ո�
			// transform �������ĵ�һ����������ת��֮�����ʽ
			cout << transform(word, trans_map);  // ��ӡ���
		};
		cout << endl;						// ���һ�е�ת��
	}
};
void CStudy01Class01::studyMap()
{
	// ��������
	// 
	// ���ؼ������򱣴�Ԫ��
	// map  -->  �������飬����ؼ���-ֵ��
	// set  -->  �ؼ��ּ�ֵ,ֻ����ؼ��ֵ�����
	// multimap  -->  �ؼ��ֿ��ظ����ֵ� map
	// multiset  -->  �ؼ��ֿ��ظ����ֵ� set
	// 
	// ���򼯺�
	// unordered_map  -->  �ù�ϣ������֯�� map
	// unordered_set  -->  �ù�ϣ������֯�� set
	// unordered_multimap  -->  ��ϣ��֯�� map:�ؼ��ֿ����ظ�����
	// unordered_multimap  -->  ��ϣ��֯�� set:�ؼ��ֿ����ظ�����

	// ����
	map<string, size_t> word_count;  // ������
	// �б��ʼ��
	set<string> exclude = { "the","but","and","or","an","a","The","But","And","Or","An","A" };
	// ����Ԫ��,authors ����ӳ��Ϊ��
	map<string, string> authors = { {"Joyce","James"},{"Austen","Jane"},{"Dickens","Charles"} };

	// pair ����
	pair<string, string> author{ "James","Joyce" };
	cout << author.first << " " << author.second << endl;  // James Joyce
	// make_pair(v1,v2)
	pair<int, string> stu = make_pair(1, "xdh");
	cout << stu.first << " " << stu.second << endl;

	// ������������
	// ���ͱ���
	// key_type  -->  �������� �ؼ��� ����
	// mapped_type  -->  ÿ���ؼ��ֹ��������ͣ�ֻ������ map
	// value_type  -->  ���� set,�� key_type ��ͬ
	//					���� map,Ϊ pair<const key_type,mapped_type>
	set<string>::value_type v1;  // v1 ��һ�� string
	set<string>::key_type v2;    // v2 ��һ�� string

	map<string, int>::value_type v3;  // v3 ��һ�� pair<const string,int>
	map<string, int>::key_type v4;    // v4 ��һ�� string
	//map<string, int>::mapped_type v5; // v5 ��һ�� int

	// ��������������
	// set �ĵ������� const ��
	set<int> iset = { 0,1,2,3,4,5,6,7,8,9 };
	set<int>::iterator set_it = iset.begin();
	if (set_it != iset.end())
	{
		//*set_it = 42;  // ����: set �еĹؼ�����ֻ����
		cout << *set_it << endl;
	};

	// ������������
	word_count = { { "one",3 }, {"two",4} };
	// ���һ��ָ����Ԫ�صĵ�����
	auto map_it = word_count.cbegin();
	while (map_it != word_count.cend())
	{
		// �����õ���������ӡ�ؼ���-ֵ��
		cout << map_it->first << map_it->second << endl;
		map_it++;  // one3  two4
	};

	// ���������� insert ����
	// ͳ��ÿ�������������г��ִ�����һ�ָ���������
	//map<string, size_t> word_count;
	//string word;
	//while (cin >> word)
	//{
	//	// ����һ��Ԫ�أ��ؼ��ֵ��� word,ֵΪ1
	//	// �� word ���� word_count �У�insert ʲôҲ����
	//	auto ret = word_count.insert({ word,1 });
	//	if (!ret.second)
	//		++ret.first->second;  // ����������
	//};
	ifstream map_file;
	ifstream input;
	word_transform(map_file, input);

}



//// ���������ʵ��Ϊ����ĳ�Ա��������ȫ�ֺ�����
//class person
//{
//public:
//    int age;
//};
//
//// ������������ͱ��뱻��ʽָ��
//    // �˴�ָ��������Ϊperson��
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

////  ����ģ��
//template <typename T>       //����ʹ��ģ��,������T��һ��ģ������
//
//void Swap(T& a, T& b)           //������ʹ��T
//{
//    T c = a;
//    a = b;
//    b = c;
//}

//// ����ģ������
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

//// ����ģ���ӡ
//template < typename T >
//void Println(T a[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << a[i] << ", ";
//    }
//    cout << endl;
//}

//// �����ģ��
//template<typename T1, typename T2, typename T3>
//T1 Add(T2 a, T3 b)
//{
//    return static_cast<T1>(a + b);
//}

//// ���غ���ģ��
//template <typename T>
//T Max(T a, T b)
//{
//    cout << "T Max(T a,T b)" << endl;
//    return a > b ? a : b;
//}
//
//template <typename T>
//T Max(T* a, T* b)                    //���غ���ģ�� 
//{
//    cout << "T Max(T* a,T* b)" << endl;
//    return *a > *b ? *a : *b;
//}
//
//int Max(int a, int b)                //������ͨ���� 
//{
//    cout << "int Max(int a,int b)" << endl;
//    return a > b ? a : b;
//}

//// ������ģ��
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
//string operator-(string& l, string& r)   //����string��û�����ؼ��Ų�����,���������Զ���һ��
//{
//    return "Minus";
//}

// ֵ����ð������
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

// ��ӡֵ��������
//void sprintArr(int* arr, int length)
//{
//    cout << "ָ�봫�ݺ������ڵ�Ԫ��Ϊ��" << endl;
//    for (int i = 0; i < length; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}


// Բ����
//const double PI = 3.14;
// ��Ͷ���
// ���һ���࣬��Բ���ܳ�
// Բ���ܳ��Ĺ�ʽ��2 * PI * �뾶
//class Circle
//{
//    // ����Ȩ��
//public:
//    // ����
//    // �뾶
//    int m_r;
//    // ��Ϊ
//    // ��ȡԲ���ܳ�
//    double calculateZC()
//    {
//        return 2 * m_r * PI;
//    };
//};
// 

// ���ڶ����Ա
//class Phone
//{
//public:
//    Phone()
//    {
//        cout << "Phone Ĭ�Ϲ��캯������" << endl;
//    }
//    Phone(string m_PName) :m_PName(m_PName)
//    {
//        cout << "Phone �вι��캯������" << endl;
//    }
//    ~Phone()
//    {
//        cout << "Phone ������������" << endl;
//    }
//    string get_PName()
//    {
//        return m_PName;
//    }
//private:
//    string m_PName;
//};
// ��װ-��Ա����˽�л�
//class Person
//{
//public:
//    // ��ͨ���캯��
//    // �޲ι��캯��-��ʼ���б�
//    Person():m_Age(0), m_Hight(new int(1)), m_Weight(2)
//    {
//
//        cout << "Person �޲ι��캯������" << endl;
//    };
//    // �вι��캯��-��ʼ���б�
//    // Phone m_Phone = d;  // ���ڳ�Ա��ʽת����������������
//    //Person(int a,int b,int c,string d) : m_Age(a), m_Hight(new int(b)),m_Weight(c),m_Phone(d)
//    //{
//    //    //m_Hight = new int(b);
//    //    //m_Age = a;
//    //    cout << "Person �вι��캯������" << endl;
//    //};
//    // �������캯��-ǳ
//    //Person(const Person &p)
//    //{
//    //    // ������������ϵ��������ԣ�������������
//    //    m_Age = p.m_Age;
//    //    cout << "Person �������캯������" << endl;
//    //};
//    // �������캯��-��
//    Person(const Person &p)
//    {
//        // ���¿����ڴ�ռ�
//        m_Hight = new int(*p.m_Hight);
//        
//        // ������������ϵ��������ԣ�������������
//        m_Age = p.m_Age;
//        m_Weight = p.m_Weight;
//        //m_Hight = p.m_Hight; // ������Ĭ��ʵ�־������д���
//        cout << "Person �������캯������" << endl;
//    };
//    ~Person()
//    {
//        if (m_Hight != NULL)
//        {
//            // �ͷ� �Լ� new ���Ķ�����ָ��
//            delete m_Hight;
//            m_Hight = NULL;
//        }
//        cout << "Person ������������" << endl;
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
//        cout << "static void func ����" << endl;
//    };
//
//public:
//    int m_Weight;
//private:
//    // ����-�ɶ���д
//    string m_Name;
//    // ����-ֻ��
//    int m_Age;
//    // ���
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
//    cout << "p1������Ϊ��" << p1.getAge() << "���Ϊ��" << *p1.getHight() << "����Ϊ��" << p1.m_Weight << endl;
//    Person p2(10,20,30,"��Ϊmate40_Pro");
//    cout << "p2������Ϊ��" << p2.getAge() << "���Ϊ��" << *p2.getHight() << "����Ϊ��" << p2.m_Weight << "�ֻ���" << p2.getPhone().get_PName() << endl;
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
//        cout << "��ָ����ó�Ա������" << endl;
//    };
//    void testNullptr2()
//    {
//        // �˴�����ȼ��� cout << "��ָ����ó�Ա����-��ȡ��Ա����ֵ" << this.m_Str << endl;
//        cout << "��ָ����ó�Ա����-��ȡ��Ա����ֵ" << m_Str << endl;
//    };
//    int coun;
//    string m_Str;
//};
//void test02()
//{
//    // 1.ͨ���������
//    //Person p;
//    EmptyClass p(1);
//    EmptyClass p2(0);
//    cout << p2.addCout(p).addCout(p).addCout(p).cout << endl;
//
//    //p.func();
//    
//    // 2.ͨ����������
//    //Person::func();
//}
//void test03()
//{
//    EmptyClass* p = NULL;
//    //p->testNullptr1();
//    p->testNullptr2();
//}

// ������
//void test04()
//{
//    const testConstFunc test;  // �ڶ���ǰ�� const ��Ϊ������
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
//    // this ָ��ı�����ָ�볣����: testConstFunc* const this; ָ���ָ���ǲ������޸ĵ�
//    // ���ڳ�Ա��������� const ,���ε��� this ָ����ָ���ֵҲ�������޸�
//    // �ȼ��� const testConstFunc* const this;
//    void showTest() const
//    {
//        // �ȼ��� this->m-A = 100;
//        //m_A = 100; // ���� const �� �ͻᱨ��
//        this->m_B;
//    }
//    void showTest2()
//    {
//
//    }
//
//public:
//    int m_A;
//    mutable int m_B; // ����������ڳ�������Ҳ�����޸����ֵ
//};

//// ��Ԫ
//class Building
//{
//    // goodGayȫ�ֺ����� Building �����ѣ����Է��� Building ��˽�г�Ա
//    friend void goodGay(Building* building);
//public:
//    Building()
//    {
//        m_SittingRoom = "����";
//        m_BedRoom = "����";
//    }
//    ~Building()
//    {
//
//    }
//public:
//    string m_SittingRoom; // ����
//private:
//    string m_BedRoom; // ����
//};
//class Building; // ���߱༭��һ���д����࣬�𱨴�
//// ȫ�ֺ���
//void goodGay(Building *building)
//{
//    cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
//    cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//void test04()
//{
//    Building building;
//    goodGay(&building);
//}
// ��Ԫ��
//class GoodGay
//{
//public:
//    GoodGay();
//    void visit(); // �ιۺ��� ����Building�е����� �� visit�������Է��� Building ��˽�г�Ա
//    void visit2(); // �� visit2 ���������Է��� Building ��˽�г�Ա
//    Building* building;
//};
//// ����д��Ա����
//class Building
//{
//    friend void GoodGay::visit();
//public:
//    Building();
//    string m_SittingRoom; // ����
//private:
//    string m_BedRoom; // ����
//};
//// �����д�����򣬱༭����֪��˭������˭�Ĺ��캯��
//Building::Building()
//{
//    m_SittingRoom = "����";
//    m_BedRoom = "����";
//
//};
//GoodGay::GoodGay()
//{
//    // ����һ��������Ķ���
//    building = new Building;
//}
//void GoodGay::visit()
//{
//    cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//    cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//void GoodGay::visit2()
//{
//    cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//    cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//void test05()
//{
//    GoodGay gg;
//    gg.visit(); 
//    gg.visit2();
//}

// �̳�
//class Java
//{
//public:
//    Java()
//    {
//
//    };
//    void header()
//    {
//        cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//    };
//    void footer()
//    {
//        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//    };
//    void left()
//    {
//        cout << "Java��Python��C++...(���������б�)" << endl;
//    };
//    void content()
//    {
//        cout << "Javaѧ����Ƶ" << endl;
//    };
//};
//// Pythonҳ��
//class Python
//{
//public:
//    Python()
//    {
//
//    };
//    void header()
//    {
//        cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//    };
//    void footer()
//    {
//        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//    };
//    void left()
//    {
//        cout << "Java��Python��C++...(���������б�)" << endl;
//    };
//    void content()
//    {
//        cout << "Pythonѧ����Ƶ" << endl;
//    };
//};
//// C++ҳ��
//class CPP
//{
//public:
//    CPP()
//    {
//
//    };
//    void header()
//    {
//        cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//    };
//    void footer()
//    {
//        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//    };
//    void left()
//    {
//        cout << "Java��Python��C++...(���������б�)" << endl;
//    };
//    void content()
//    {
//        cout << "CPPѧ����Ƶ" << endl;
//    };
//};
// �̳�ʵ��ҳ��
//class BasePage
//{
//public:
//    BasePage()
//    {
//        
//    };
//    void header()
//    {
//        cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//    };
//    void footer()
//    {
//        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//    };
//    void left()
//    {
//        cout << "Java��Python��C++...(���������б�)" << endl;
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
//        cout << "Pythonѧ����Ƶ" << endl;
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
//        cout << "CPPѧ����Ƶ" << endl;
//    };
//};
//
//void test06()
//{
//    cout << "Java������Ƶҳ��" << endl;
//    Java ja;
//    ja.header();
//    ja.footer();
//    ja.left();
//    ja.content();
//
//    cout << "------------------------------" << endl;
//    cout << "Python������Ƶҳ��" << endl;
//    Python py;
//    py.header();
//    py.footer();
//    py.left();
//    py.content();
//
//    cout << "------------------------------" << endl;
//    cout << "CPP������Ƶҳ��" << endl;
//    CPP cp;
//    cp.header();
//    cp.footer();
//    cp.left();
//    cp.content();
//}


// ��ģ���뺯��ģ������
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
//    //Person("����", 18);
//    Person<string, int> p("����",18);
//    cout << p.showName() << "������Ϊ��" << p.m_Age << endl;
//
//    Person<string> p1("����", 20);
//}


// ��ģ���������������
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
//        cout << "������" << this->m_Name << "���䣺" << this->m_Age << endl;
//    }
//
//    T1 m_Name;
//    T2 m_Age;
//};
//// 1.ָ����������
//void printPerson1(Person<string, int>&p)
//{
//    p.showPerson();
//}
//// 2.����ģ�廯
//template<class T1,class T2>
//void printPerson2(Person<T1,T2>&p)
//{
//    p.showPerson();
//    // ���� typeid �ж�ģ�������
//    cout << "T1 ������Ϊ��" << typeid(T1).name() << endl;
//    cout << "T2 ������Ϊ��" << typeid(T2).name() << endl;
//}
//// 3.������ģ�廯
//template<class T>
//void printPerson3(T &p)
//{
//    p.showPerson();
//    // ���� typeid �ж�ģ�������
//    cout << "T ������Ϊ��" << typeid(T).name() << endl;
//}
//void test08()
//{
//    //Person<string, int> p1("�����", 100);
//    //printPerson1(p1);
//    Person<string, int> p2("��˽�", 90);
//    printPerson2(p2);
//    Person<string, int> p3("��ɮ", 1000);
//    printPerson3(p3);
//}


// ��ģ����̳�
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
//class Son:public Base<int> // ���߸����е� T ��  int ����
//{
//public:
//    Son()
//    {
//
//    }
//};
// ��������ָ�������� T ���ͣ�����Ҳ��Ҫ����ģ��
// ���ʱ��ͺܳ����ˣ�����ģ���г�Ա����ΪTָ�����ͣ����������ڼ̳е�ʱ����Ĳ���ΪT2����������Ҳ��Ҫ�����ģ��
// ��������ģ����ղ��� T1 T2��T1�ǳ�Ա���������ͣ����湹��ʵ����ʱ�� Son2<string,int> s2 ָ���� T1Ϊstring,T2Ϊint,���T2Ҳ�����˸���
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
//    Son2<string,int> s2("����",18);
//}
// ���캯������ʵ��
//template<class T1, class T2> // �����д���༭������ʶT1,T2
//Base<T1,T2>::Base(T1 name, T2 age) // ����ʵ�ּ�������,����Ҫ�� T1,T2�����߱༭��������ģ�������ʵ��
//{
//    this->m_N = name;
//    this->m_A = age;
//}
//// ��Ա��������ʵ��
//template<class T1, class T2> // �����д���༭������ʶT1,T2
//void Base<T1, T2>::showName()
//{
//    cout << this->m_N << endl;
//}

// ��ģ������Ԫ
// ͨ��ȫ�ֺ��� ��ӡPerson��Ϣ
template<class T1, class T2> // ����Ҫ�ñ༭��֪������һ��ģ��
class Person;// д��ǰ�棬�ñ༭��֪��Person �Ĵ���
// ȫ�ֺ�������ʵ�� ����ģ���ʵ�֣�����������ʱ��ҲҪʹ�ú���ģ�����ʽ
// д��ǰ�棬�ñ�������ǰ֪����������Ĵ���
template<class T1, class T2>
void printPersonInfo2(Person<T1, T2> p)
{
	cout << "����ʵ�ֵ����� --- ������" << p.m_Name << "����:" << p.m_Age << endl;
};
template<class T1, class T2>
class Person
{
	// ȫ�ֺ�������ʵ��  ����ģ�廯�ķ�ʽ���д���
	//friend void printPersonInfo1(Person<T1, T2> p)
	//{
	//    cout << "������" << p.m_Name << "����:" << p.m_Age << endl;
	//}
	// ȫ�ֺ�������ʵ��
	//friend void printPersonInfo2(Person<T1, T2> p); --����д��
	// ���ȫ�ֺ��� ������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void printPersonInfo2<>(Person<T1, T2> p); // ��һ����ģ������б�

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
	// ��ʵ������~ virtual �������� �麯�� һ�������ָ��������ÿ���ָ���������������Ķ���
	//class base
	//{
	//    int a, b;
	//public:
	//    virtual void test() { cout << "���෽����" << endl; }
	//    virtual ~base() {};
	//};

	//class inheriter :public base
	//{
	//public:
	//    void test() { cout << "�����෽��!" << endl; } // ��д���෽��
	//};

	//base* p1 = new base;
	//base* p2 = new inheriter;
	//p1->test();
	//p2->test();

	// �����
	//class base
	//{
	//    int b;
	//public:
	//    virtual void test() { cout << "���෽��" << endl; };
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
	//cout << sizeof(mytest) << endl;                  //���12
	//cout << sizeof(mytest2) << endl;                 //���12
	//cout << sizeof(mytest3) << endl;                 //���16

	// ��д������麯��
	//class Base
	//{
	//    virtual void f();
	//};
	//class Derived : public Base {
	//    void f() override; // ��ʾ��������д�����麯��f
	//    void F() override;//���󣺺���Fû����д�����κ��麯��
	//};

	// ���������ʵ��Ϊ��ĳ�Ա����
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

	//// ����ģ�����
	//int a = 0;
	//int b = 1;

	//Swap(a, b);                   //�Զ�����,����������a��b���������Ƶ�
	//cout << a << b << endl;

	//float c = 0;
	//float d = 1;
	//Swap<float>(c, d);           //��ʾ����,���߱�����,���õĲ�����float����
	//cout << c << d << endl;
	//// ���ú���ģ�� ����ʹ�ӡ����
	//int ww[5] = { 5, 3, 2, 4, 1 };
	//Sort(ww, 5);            //�Զ�����,����������a��5���������Ƶ�
	//Println<int>(ww, 5);    //��ʾ����,���߱�����,���õĲ�����int����
	//string s[5] = { "Java", "C++", "Pascal", "Ruby", "Basic" };
	//Sort(s, 5);
	//Println(s, 5);

	//// �����ģ�����
	////int ad = Add(1,1.5);       //���б������,û��ָ������ֵ����

	//int aa = Add<int>(1, 1.5);
	//cout << aa << endl;                  //2

	//float bb = Add<float, int, float>(1, 1.5);
	//cout << bb << endl;                  //2.5

	//// ���غ���ģ��
	//int a = 0;
	//int b = 1;
	//cout << "a:b=" << Max(a, b) << endl;        //������ͨ���� Max(int,int)
	//cout << "a:b=" << Max<>(a, b) << endl;        //ͨ��ģ������� ���� ����ģ�� Max(int,int)
	//cout << "1.5:2.0=" << Max(1.5, 2.0) << endl;
	////������������Ĭ�϶���double,�����޷���ʽת��,����ú���ģ�� Max(double,double)
	//int* p1 = new int(1);
	//int* p2 = new int(2);
	//cout << "*p1:*p2=" << Max(p1, p2) << endl;  // �������غ���ģ�� Max(int* ,int* )    
	//cout << "'a',100=" << Max('a', 100) << endl;
	////��char���ͽ�����ʽת��,�Ӷ�������ͨ���� Max(int,int)
	//delete p1;
	//delete p2;

	//// ������ģ��
	//Operator<int>  op1;            //�������ʱ,��Ҫָ����ģ������
	//cout << op1.add(1, 2) << endl;
	//Operator<string>  op2;         //�������ʱ,��Ҫָ����ģ������
	//cout << op2.add("D.T.", "Software") << endl;
	//cout << op2.minus("D.T", "Software") << endl;


	//int* poingArr = new int[2]{2,1};
	//cout << *poingArr << endl;
	//cout << poingArr[0] << endl;
	//cout << poingArr[1] << endl;
	//cout << typeid(poingArr).name() << endl;


// ��������
// ��������
//int arr[6] = { 1,3,2,5,4,6 };
//// ���鳤��
//int arrLength = sizeof(arr) / sizeof(arr[0]);
//// ��ӡ����Ԫ��
//cout << "��������ǰԪ��Ϊ��" << endl;
//for (int i = 0; i < arrLength; i++)
//{
//    cout << arr[i] << endl;
//}
//// ʵ������
//// ��¼��ʼ�±�λ��
//int start = 0;
//// ��¼�����±�λ��
//int end = arrLength - 1;
//
//// ʵ��ѭ��
//while (start < end)
//{
//    // ��ʼ�±�������±��Ԫ�ػ���
//    int temp = arr[start];
//    arr[start] = arr[end];
//    arr[end] = temp;
//    // �±����
//    start++;
//    end--;
//}
//// ��ӡ���ú������Ԫ��
//cout << "�������ú�Ԫ��Ϊ��" << endl;
//for (int i = 0; i < arrLength; i++)
//{
//    cout << arr[i] << endl;
//}


// ð������
//int arr[9] = { 4,2,8,0,5,7,1,3,9 };
//// ���鳤��
//int arrLength = sizeof(arr) / sizeof(arr[0]);
//cout << "����ǰ������Ԫ�أ�" << endl;
//for (int i = 0; i < 9; i++)
//{
//    cout << arr[i] << "";
//}
//cout << endl;
//// ��ʼ����
//// ���������� = Ԫ�ظ��� - 1;
//for (int i = 0; i < arrLength - 1; i++)
//{
//    // �ڲ�ѭ���Ա�
//    // ÿ�ֶԱȴ��� = Ԫ�ظ��� - �������� - 1;
//    for (int j = 0; j < arrLength - i - 1; j++)
//    {
//        // �����һ�����֣��ȵڶ������ִ󣬽�����������
//        if (arr[j] > arr[j + 1])
//        {
//            int temp = arr[j];
//            arr[j] = arr[j + 1];
//            arr[j + 1] = temp;
//        }
//    }
//}
//// ��ӡ���������
//cout << "����������Ԫ�أ�" << endl;
//for (int i = 0; i < 9; i++)
//{
//    cout << arr[i] << "";
//}
//cout << endl;


// ��ά����
// ��һ�ֶ��巽ʽ
//int arr1[2][3];
//arr[0][0] = 1;
//arr[0][1] = 2;
//arr[0][2] = 3;
//arr[1][0] = 4;
//arr[1][1] = 5;
//arr[1][2] = 6;
// �ڶ��ֶ��巽ʽ
//int arr2[2][3] = 
//{
//    {1,2,3},
//    {4,5,6}
//};
// �����ֶ��巽ʽ
//int arr3[2][3] = { 1,2,3,4,5,6 };
// 
// �����ֶ��巽ʽ
//int arr4[][3] = { 1,2,3,4,5,6 };
//// ��ӡ��ά�����е�Ԫ��
//for (int i = 0;i < 2; i++)
//{
//    for (int j = 0; j < 3; j++)
//    {
//        cout << arr4[i][j] << " ";
//        
//    }
//    cout << endl;
//}


// ��ά����������;
//int arr[2][3] =
//{
//    {1,2,3},
//    {4,5,6}
//};
//cout << "��ά����ռ���ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
//cout << "��ά�����һ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr[0]) << endl;
//cout << "��ά�����һ��Ԫ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr[0][0]) << endl;
//cout << "��ά��������Ϊ��" << sizeof(arr) / sizeof(arr[0]) << endl;
//cout << "��ά��������Ϊ��" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
//cout << "��ά�����׵�ַΪ��" << (int)arr << endl;
//cout << "��ά����һ���׵�ַΪ��" << (int)arr[0] << endl;
//cout << "��ά�����һ��Ԫ���׵�ַΪ��" << (int)&arr[0][0] << endl;


//ָ��
//int a = 3;
//// const ����ָ��
//// ����ָ��
//const int* p = &a;
//int b = 4;
//*p = 4; // ����
//p = &b;
//// ָ�볣��
//int* const p1 = &a;
//*p1 = 4; 
//p1 = &b; // ����
//// ����ָ�볣��
//const int* const p2 = &a;
//*p2 = 4; // ����
//p2 = &b; // ����
//// ����
//// const ������ * p,���� *P �����޸�
//// const ������ p,���� P �����޸�


// ָ������
//// ����ָ����������е�Ԫ��
//int arr[5] = { 1,2,3,4,5 };
//cout << "�����һ��Ԫ��Ϊ��" << arr[0] << endl;
//int* p = arr;
//cout << "����ָ����������һ��Ԫ��Ϊ��" << *p << endl; // 1
//p++; // ��ָ�����ƫ�� 4 ���ֽڣ���Ϊָ������ Ϊ int ;
//cout << "����ָ���������ڶ���Ԫ��Ϊ��" << *p << endl; // 2
//// ����ָ���������
//int arr2[10] = { 1,2,3,4,5,3,5,6,7,9 };
//int* p2 = arr2;
//for (int i = 0; i < 10; i++)
//{
//    //cout << arr2[i] << endl;
//    cout << *p2 << endl;
//    p2++;
//}


// ֵ����
//int arr[5] = { 2,3,4,1,5 };
//int lengthArr = sizeof(arr) / sizeof(arr[0]);
//swapArr(arr, lengthArr);
//sprintArr(arr, lengthArr);


// �ṹ��
// �Զ�����������
//struct Student
//{
//    string name;
//    int age;
//    int score;
//}s3;
// ͨ��ѧ�����ʹ�������ѧ��
// 1.struct �ṹ�� ������
//struct Student s1;
//s1.name = "zhangsan";
//s1.age = 18;
//s1.score = 98;
// 2.struct �ṹ���� ������ = {��Ա1ֵ,��Ա2ֵ};
//struct Student s2 = { "lisi",20,99 };
// 3.����ṹ��ʱ˳�㴴������
//s3.name = "wanger";
//s3.age = 24;
//s3.score = 100;

// �ṹ������
//struct Student stuArray[3] =
//{
//    {"����",18,87},
//    {"����", 19, 98},
//    {"����",22,100}
//};
// �ṹ��ָ��
//Student s = { "����",18,80 };
//Student* p = &s;
//p->name = "����";
//p->age = 25;
//p->score = 98;

// ͨ��Բ�� ���������Բ(����) -- ʵ����
//Circle c1;
//// ��Բ��������Խ��и�ֵ
//c1.m_r = 10;
//cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;

// ���캯������
// 1.���ŷ�
// ����Ĭ�Ϲ��캯����ʱ��Ҫ�� (),��Ϊ����������Ϊ����һ������������
//Person p1; // Ĭ��(�޲�)���캯������
//Person p2(10);
//cout << p2.getAge() << endl;
//Person p3(p2);
//cout << p3.getAge() << endl;
// 2.��ʾ��
//Person p1;
//Person p2 = Person(18); // �вι���
//Person p3 = Person(p2); // ��������
// Person(12); // ���������ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
// ע�⣺��Ҫ���ÿ������캯�� ��ʼ����������
// Person(p3)  // �༭������Ϊ Person(p3) === Person p3; ��һ����������
// 3.��ʽת����
//Person p4 = 10; // �൱�� Person p4 = Person(10);
//Person p5 = p4;

// �������캯������ʱ��
// 2.��ֵ���ݵķ�ʽ ��������������
// 3.��ֵ��ʽ���ؾֲ�����
//work3();

// �����ǳ����
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
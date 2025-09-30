#include "test_module\stl\stl01_class01.h"

#include <vector>
#include <iostream>
#include <map>

void STL01_Class01::testVectorChar()
{
	vector<unsigned char> rxbuf;
	int N = rxbuf.size();
	rxbuf.resize(N + 10);
	memset((char*)&rxbuf[0] + N, 'a', 10);
	for (int i = 0; i < rxbuf.size(); i++)
	{
		cout << rxbuf[i] << endl;
	}

}

void STL01_Class01::testMap()
{
	vector<int> temp;
	std::map<string, vector<int>> mm;
	mm.insert(make_pair("1", temp));
	auto& itmm = mm.at("1");
	itmm.push_back(1);
	for (auto& it : itmm)
	{
		cout << it << endl;
	}



}

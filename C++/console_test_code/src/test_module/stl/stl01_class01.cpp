#include "test_module\stl\stl01_class01.h"

#include <vector>
#include <iostream>

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

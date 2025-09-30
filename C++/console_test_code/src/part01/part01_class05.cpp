#include "part01/part01_class05.h"
#include <iostream>

#include "tools/Rijndael.h"
#include "tools/base64.h"
#include "tools/CStringUtils.h"

using namespace std;


class base1
{
public:
	base1()
		: n2(0)
		, n1(n2 + 2)
		, n3(1)
	{
		cout << "base1 构造函数执行" << endl;
	};

	~base1()
	{
		cout << "~base1 析构函数执行" << endl;
	};

	void print()
	{
		cout << "n1 " << n1 << ",n2 " << n2 << endl;
	}
private:
	int n1;
	int n2;
	const int n3;
	static int n4;
};
int base1::n4 = 1;

class base2
{
public:
	base2()
		: b1(1)
		, b2(2)
	{
		cout << "base2 构造函数执行" << endl;
	};

	~base2()
	{
		cout << "~base2 析构函数执行" << endl;
	};
	int b1;
	int b2;
};

class base3 : public base2
{
public:
	base3()
		: b1(1)
		, b2(2)
	{
		cout << "base3 构造函数执行" << endl;
	};

	~base3()
	{
		cout << "~base3 析构函数执行" << endl;
	};
private:
	int b1;
	int b2;
	base1 base1;

};


class vtest
{
public:
	vtest()
		: t1(1)
		, t2(2)
	{
		cout << "vtest 构造函数执行" << endl;
	};

	~vtest()
	{
		cout << "~vtest 析构函数执行" << endl;
	};
private:

	int t1;
	int t2;
};

class test1 : public base3 ,public virtual vtest
{
public:
	test1()
		: t1(1)
		, t2(2)
	{
		cout << "test1 构造函数执行" << endl;
	};

	~test1()
	{
		cout << "~test1 析构函数执行" << endl;
	};
private:

	int t1;
	int t2;
};


void CPart01Class05::testConstructInitOrder()
{
	// 测试变量初始化顺序
	// 1.成员变量初始化根据定义的顺序进行初始化
	// 2.const 成员变量必须初始化列表进行初始化

	base1 base1;
	base1.print();
	test1 test1;

}

void CPart01Class05::testAES16pck7()
{
	//string aes_str = "3l3Bb13hnCwk5+d0j4fuqCxAYca6Ujo+J+cGyFqUZAUsQGHGulI6PifnBshalGQFLEBhxrpSOj4n5wbIWpRkBeWnM8bI2Qi5JaHK1gTx3tBfLdjhiqq2uoQtB6BDI4iv";
	// 128 pkcs7 
	string aes_str = "iwVY3f0zezpFBprxvRDl8pwUEcOGlcOp68CpF29fGz6cFBHDhpXDqevAqRdvXxs+nBQRw4aVw6nrwKkXb18bPqHToYczGZm/NKnFLMDYVOenUzwHRTQeovjV0mXU6ExD";
	string strData = base64Decode(aes_str);
	//string strData = aes_str;
	size_t length = strData.length();
	//密文
	char* szDataIn = new char[length + 1];
	memcpy(szDataIn, strData.c_str(), length + 1);
	//明文
	char* szDataOut = new char[length + 1];
	memcpy(szDataOut, strData.c_str(), length + 1);
	//进行AES的ECB模式解密
	CRijndael aes;
	aes.MakeKey("e3b0c44298fc1c14", "", 16, 16);
	aes.Decrypt(szDataIn, szDataOut, length, CRijndael::ECB);

	//去PKCS7Padding填充
	if (0x00 < szDataOut[length - 1] <= 0x16)
	{
		int tmp = szDataOut[length - 1];
		for (int i = length - 1; i >= length - tmp; i--)
		{
			if (szDataOut[i] != tmp)
			{
				memset(szDataOut, 0, length);
				break;
			}
			else
				szDataOut[i] = 0;
		}
	}
	string strDest(szDataOut);
	delete[] szDataIn;
	delete[] szDataOut;

	wstring wstr = CStringConvet::stringToWString(strDest);
}

void CPart01Class05::testAES16pck5()
{
	string aes_str = "iwVY3f0zezpFBprxvRDl8pwUEcOGlcOp68CpF29fGz6cFBHDhpXDqevAqRdvXxs+aHyioVHJhUzQ2k0LCGDdeQ==";
	string strData = base64Decode(aes_str);
	size_t length = strData.length();
	//密文
	char* szDataIn = new char[length + 1];
	memcpy(szDataIn, strData.c_str(), length + 1);
	//明文
	char* szDataOut = new char[length + 1];
	memcpy(szDataOut, strData.c_str(), length + 1);
	//进行AES的ECB模式解密
	CRijndael aes;
	aes.MakeKey("e3b0c44298fc1c14", "", 16, 16);
	aes.Decrypt(szDataIn, szDataOut, length, CRijndael::ECB);

	string strDest(szDataOut);
	delete[] szDataIn;
	delete[] szDataOut;

	wstring wstr = CStringConvet::stringToWString(strDest);
}

void CPart01Class05::testAES32pck7()
{
	string aes_str = "vzric+68InQQIVelKL/M9NXd3hIXH7HwudXJuvKSgdDV3d4SFx+x8LnVybrykoHQm7gYYuyIVM5dxvJEF0pxFg==";
	string strData = base64Decode(aes_str);
	size_t length = strData.length();
	//密文
	char* szDataIn = new char[length + 1];
	memcpy(szDataIn, strData.c_str(), length + 1);
	//明文
	char* szDataOut = new char[length + 1];
	memcpy(szDataOut, strData.c_str(), length + 1);
	//进行AES的ECB模式解密
	CRijndael aes;
	aes.MakeKey("e3b0c44298fc1c14e3b0c44298fc1c14", "", 32, 16);
	aes.Decrypt(szDataIn, szDataOut, length, CRijndael::ECB);

	string strDest(szDataOut);
	delete[] szDataIn;
	delete[] szDataOut;

	wstring wstr = CStringConvet::stringToWString(strDest);
}

void CPart01Class05::testAES32pck5()
{
	string aes_str = "vzric+68InQQIVelKL/M9NXd3hIXH7HwudXJuvKSgdDV3d4SFx+x8LnVybrykoHQm7gYYuyIVM5dxvJEF0pxFg==";
	string strData = base64Decode(aes_str);
	size_t length = strData.length();
	//密文
	char* szDataIn = new char[length + 1];
	memcpy(szDataIn, strData.c_str(), length + 1);
	//明文
	char* szDataOut = new char[length + 1];
	memcpy(szDataOut, strData.c_str(), length + 1);
	//进行AES的ECB模式解密
	CRijndael aes;
	aes.MakeKey("e3b0c44298fc1c14e3b0c44298fc1c14", "", 32, 16);
	aes.Decrypt(szDataIn, szDataOut, length, CRijndael::ECB);

	string strDest(szDataOut);
	delete[] szDataIn;
	delete[] szDataOut;

	wstring wstr = CStringConvet::stringToWString(strDest);
}
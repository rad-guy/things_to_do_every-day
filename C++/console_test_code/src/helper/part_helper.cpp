#include "helper/part_helper.h"

#include "part01/part01_class01.h"
#include "part01/part01_class02.h"
#include "part01/part01_class03.h"
#include "part01/part01_class04.h"
#include "part01/part01_class05.h"
#include "part01/part01_class06.h"

void CPartHelper::excuteClass01()
{

}

void CPartHelper::excuteClass02()
{
	CPart01Class02 test_main;
	test_main.prove01();
	SScreenPhysicsSize master;
	SScreenPhysicsSize slave;
	test_main.getScreenScreenPhysicsSize(master, slave);
	test_main.getIntArrByteNum();
	test_main.removeDirAllFile(L"D:/res");

	bool ret = test_main.CopyFolder(L"D:/test_utils4/", L"D:/test_log/");
	test_main.testMonitorFromWindow();
	test_main.testLPCSTR2String();
	string res = "";

}

void CPartHelper::excuteClass03()
{
	CPart01Class03 test_main;
	test_main.testGetIpStrHeader();
	test_main.testTempVarNewPoint();
	test_main.testTempVariableReturn();
	test_main.testReadFile();
	test_main.testWriteClassInStream();
	test_main.testStrcpm();
}

void CPartHelper::excuteClass04()
{
	CPart01Class04 test_main;
	test_main.testBitwise();
	test_main.testStdThread();
	test_main.testStdSubstr();
	test_main.testReleaseOccupyedFile();
	test_main.testSpeSpecialCharacter();
	test_main.testLongShortPath();
	test_main.testWOpen();
	test_main.testSubtractRect();
}

void CPartHelper::excuteClass05()
{
	CPart01Class05 test_main;
	test_main.testConstructInitOrder();
	test_main.testAES16pck7();
	test_main.testAES16pck5();
	test_main.testAES32pck7();
	test_main.testAES32pck5();
}

void CPartHelper::excuteClass06()
{
	CPart01Class06 test_main;
	//test_main.testClass();
	//test_main.testDeepCopy();

	//// 顺序初始化
	//test_main.testStruct(Struct1{ "hello",11 });
	test_main.testEndWith();
	test_main.testStdBindFunc();
	// 指定初始化 vs 不支持
	//Struct1 s = { .name_ = "hello",.age_ = 11 };
	//Struct1 ss = { name_:"hello",age_ : 11 };
}

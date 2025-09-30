#include "helper/module_helper.h"

#include "test_module/stl/stl01_class01.h"
#include "test_module/socket/multi_cast.h"


void CModuleHelper::executSTL()
{
	STL01_Class01 class01;
	class01.testVectorChar();
	class01.testMap();
};

void CModuleHelper::executeMultiCast()
{
	//return;
	//CMultiCast multiCast;
	//multiCast.testBroadCast();
}
void CModuleHelper::test()
{
	int i = 0;
	i += 1;
}
;

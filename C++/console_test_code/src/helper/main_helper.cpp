#include "helper/main_helper.h"

#include "helper/module_helper.h"
#include "helper/part_helper.h"
#include "helper/study_helper.h"
#include "test/test-memory.h"


void CMainHelper::executePart()
{
	CPartHelper::excuteClass01();
	CPartHelper::excuteClass02();
	CPartHelper::excuteClass03();
	CPartHelper::excuteClass04();
	CPartHelper::excuteClass05();
	CPartHelper::excuteClass06();
}

void CMainHelper::executeStudy()
{
	CStudyHelper::excuteClass01();
	CStudyHelper::excuteClass02();
	CStudyHelper::excuteClass03();
	CStudyHelper::excuteClass04();
}

void CMainHelper::executeModule()
{
	CModuleHelper::executeMultiCast();
	CModuleHelper::executSTL();
}

void CMainHelper::executeMemory()
{
	CMemory01::testMemory();
}
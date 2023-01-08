#include "part01/part01_class02.h"
#include <iostream>


int  CPart01Class02::m_iTestVariable = 0;
CPart01Class02::CPart01Class02()
{

}

CPart01Class02::~CPart01Class02()
{
}

void CPart01Class02::setStaticVariable(int val)
{
	m_iTestVariable = val;
}

int CPart01Class02::getStaticVariable()
{
	return m_iTestVariable;
}

void CPart01Class02::setName(string name)
{
	m_sName = name;
}

void CPart01Class02Test::prove01()
{
	m_cTest01.setName("test01");
	int ret_num = m_cTest01.getStaticVariable();
	CPart01Class02::setStaticVariable(10);
	m_cTest02.setName("test02");
	int ret_num1 = m_cTest01.getStaticVariable();
	int ret_num2 = m_cTest02.getStaticVariable();
	cout << "ret_num1 = " << ret_num1 << ",ret_num2=" << ret_num2 << ",结论：静态变量为 所有类实例公共变量";
}

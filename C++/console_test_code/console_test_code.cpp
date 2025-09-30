#include <iostream>
#include "helper/main_helper.h"


int main()
{
    std::cout << "Hello World!\n";

    CMainHelper::executePart();
    CMainHelper::executeStudy();
    CMainHelper::executeModule();
    CMainHelper::executeMemory();
    system("pause");
}
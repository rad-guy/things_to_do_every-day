#pragma once


#ifdef MULTI_MODULE_DLL
#define MULTI_MODULE_DLL_EXPORTS __declspec(dllexport)
#else
#define MULTI_MODULE_DLL_EXPORTS
#endif
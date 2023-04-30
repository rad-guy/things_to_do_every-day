#pragma once

#include <string>
#include <WinSock2.h>
#include <Ws2tcpip.h>

#include "multi_module_dll_global.h"

using namespace std;

const unsigned int SOCKET_BUF_SIZE = 1024 * 50;

const int MAX_CLIENT_NUMBER = 10;
#define   CHAT_SERVER_SOCKET_IP			"192.168.1.104"

const int CHAT_SERVER_SOCKET_PROT = 12248;


//typedef struct tagSChatInfo
//{
//	string name;
//	SOCKET h
//
//
//};

class IChatSocketServer
{
public:
	virtual ~IChatSocketServer() {};

	virtual void setLocalProt(int port) = 0;

	virtual void init() = 0;
    virtual void close() = 0;
	virtual void start() = 0;
};

class IChatSocketClient
{
public:
	virtual ~IChatSocketClient() {};

	virtual void setLocalProt(int port) = 0;

	virtual void init() = 0;
	virtual void close() = 0;
	virtual void start() = 0;
};



#ifdef __cplusplus
extern "C"
{
#endif

	MULTI_MODULE_DLL_EXPORTS bool DT_Start_WinSocket_Dll();
	MULTI_MODULE_DLL_EXPORTS bool DT_Clean_WinSocket_Dll();
	MULTI_MODULE_DLL_EXPORTS IChatSocketServer* DT_CreateChatSocketServer();
	MULTI_MODULE_DLL_EXPORTS IChatSocketClient* DT_CreateChatSocketClient();

#ifdef __cplusplus
};
#endif // __cplusplus

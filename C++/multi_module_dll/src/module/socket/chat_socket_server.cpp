#include "pch.h"
#include "base_socket.h"
#include "chat_socket_server.h"


bool DT_Start_WinSocket_Dll()
{
	WSADATA wsaData;
	int iResult = 0;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		return false;
	}
	return true;
}

bool DT_Clean_WinSocket_Dll()
{
	int iResult = 0;
	iResult = WSACleanup();
	if (iResult != NO_ERROR) {
		return false;
	}
	return true;
}
IChatSocketServer* g_pChatSocketServer = NULL;
IChatSocketServer* DT_CreateChatSocketServer()
{
	if (!g_pChatSocketServer)
	{
		g_pChatSocketServer = new CChatSocketServer();
	}
	return g_pChatSocketServer;
}

std::string getLocalIp()
{
	if (!DT_Start_WinSocket_Dll()) return "";
	//获取主机名  
	char hostname[256];
	int ret = gethostname(hostname, sizeof(hostname));
	if (ret == SOCKET_ERROR)
	{
		return "";
	}
	//获取主机ip  
	HOSTENT* host = gethostbyname(hostname);
	if (host == NULL)
	{
		return "";
	}
	//转化为char*并拷贝返回  
	char ip[128];
	strcpy(ip, inet_ntoa(*(in_addr*)*host->h_addr_list));
	return string(ip);
}



CChatSocketServer::CChatSocketServer()
	: m_iLocalPort(0)
	, m_hSocketSer(INVALID_SOCKET)
{
}

CChatSocketServer::~CChatSocketServer()
{
}

void CChatSocketServer::setLocalProt(int port)
{
	m_iLocalPort = port;
}

void CChatSocketServer::init()
{
	if (m_hSocketSer) close();

	m_hSocketSer = socket(AF_INET, SOCK_STREAM, 0);
	if (m_hSocketSer == INVALID_SOCKET)
	{
		wprintf(L"socket function failed with error: %u\n", WSAGetLastError());
		return;
	}
	//string ip = getLocalIp();
	m_addrSer.sin_addr.s_addr = inet_addr(CHAT_SERVER_SOCKET_IP);
	m_addrSer.sin_family = AF_INET;
	m_addrSer.sin_port = htons(CHAT_SERVER_SOCKET_PROT);

	int ret = bind(m_hSocketSer, (sockaddr*)&m_addrSer, sizeof(m_addrSer));
	if (ret == SOCKET_ERROR)
	{
		wprintf(L"bind failed with error %u\n", WSAGetLastError());
		close();
		WSACleanup();
		return;
	}

}

void CChatSocketServer::close()
{
	closesocket(m_hSocketSer);
	m_hSocketSer = INVALID_SOCKET;
}

void CChatSocketServer::start()
{
	printf("=============Server start================\n");
	while (true)
	{
		char sendBuf[SOCKET_BUF_SIZE];
		memset(sendBuf, 0, sizeof(sendBuf));
		listen(m_hSocketSer, MAX_CLIENT_NUMBER);

		sockaddr_in addrCli;
		int sockAddrSize = sizeof(sockaddr_in);
		SOCKET hSocketClient = accept(m_hSocketSer, (sockaddr*)&addrCli, &sockAddrSize);
		if (hSocketClient != INVALID_SOCKET)
		{
			printf("连接成功!\n");
			
			strcpy(sendBuf, "hello!");
			send(hSocketClient, sendBuf, sizeof(sendBuf), 0);
		}
	}

}

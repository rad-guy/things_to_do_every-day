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
	, m_pChatSink(NULL)
{
}

CChatSocketServer::~CChatSocketServer()
{
}

void CChatSocketServer::setLocalProt(int port)
{
	m_iLocalPort = port;
}

void CChatSocketServer::setSink(IChatServerSink* sink)
{
	m_pChatSink = sink;
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

	// socket 默认是阻塞式的。 accept 和 recv 都是阻塞式的。
	u_long on = 1;
	ioctlsocket(m_hSocketSer, FIONBIO, &on);

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
		startMsgPolling();
		listen(m_hSocketSer, MAX_CLIENT_NUMBER);

		sockaddr_in addr;
		int sockAddrSize = sizeof(sockaddr_in);
		SOCKET hSocketClient = accept(m_hSocketSer, (sockaddr*)&addr, &sockAddrSize);

		if (hSocketClient != INVALID_SOCKET)
		{
			onConnectSuccess(hSocketClient, addr);
			string sendData = "{\"sortid\":\"connect\",\"result\":\"sucess\"}";
			
		}
	}

}

void CChatSocketServer::massMsg(const string& msg)
{
	for (auto item : m_vecClient)
	{
		sendMsgToClient(item,msg);
	}
}

int CChatSocketServer::onConnectSuccess(const SOCKET& socket , const sockaddr_in& addr)
{
	SChatClientInfo* clientInfo = new SChatClientInfo();
	// net_ntoa 函数将 (Ipv4) Internet 网络地址转换为 Internet 标准点分十进制格式的ASCII 字符串
	clientInfo->ip = inet_ntoa(addr.sin_addr);
	clientInfo->port = ntohs(addr.sin_port);
	clientInfo->socket = socket;
	m_vecClient.push_back(clientInfo);
}

void CChatSocketServer::sendMsgToClient(int id, const string& msg)
{
	SChatClientInfo* client = getClientInfo(id);
	sendMsgToClient(client, msg);
}

void CChatSocketServer::sendMsgToClient(SChatClientInfo* client, const string& msg)
{
	if (!client) return;

	char sendBuf[SOCKET_BUF_SIZE];
	memset(sendBuf, 0, sizeof(sendBuf));
	send(client->socket, sendBuf, sizeof(sendBuf), 0);
}

void CChatSocketServer::startMsgPolling()
{
	char recvBuf[SOCKET_BUF_SIZE];
	for (auto item : m_vecClient)
	{
		int ret = recv(item->socket, recvBuf, sizeof(recvBuf), 0);
		if (ret > 0)
		{
			if (m_pChatSink) m_pChatSink->onReceiveMsg();
		}
	}
}

void CChatSocketServer::registerClient(SChatClientInfo* client)
{
	if (getClientInfo(client->id))
		return;
	m_vecClient.push_back(client);
}

void CChatSocketServer::unregisterClient(SChatClientInfo* client)
{
	VecClientGroup::iterator it = m_vecClient.begin();
	for (; it != m_vecClient.end(); it++)
	{
		if (client->id == (*it)->id)
		{
			m_vecClient.erase(it);
			return;
		}
	}
}

SChatClientInfo* CChatSocketServer::getClientInfo(int id)
{
	for (auto item : m_vecClient)
	{
		if (item->id == id)
			return item;
	}
	return nullptr;
}

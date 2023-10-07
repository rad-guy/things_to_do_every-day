#include "pch.h"
#include "base_socket.h"
#include "chat_socket_client.h"
#include "jsoncpp/include/json/json.h"
#include <iostream>


IChatSocketClient* DT_CreateChatSocketClient()
{
	IChatSocketClient* socketClient = new CChatSocketClient();
	return socketClient;
}


CChatSocketClient::CChatSocketClient()
	: m_iLocalPort(0)
	, m_hSocketCli(INVALID_SOCKET)
	, m_bIsConnected(false)
{
}

CChatSocketClient::~CChatSocketClient()
{

}

void CChatSocketClient::setLocalProt(int port)
{
	srand((unsigned int)time(NULL));
	m_iLocalPort = port + rand() % 101;
}

void CChatSocketClient::init()
{
	if (m_hSocketCli) close();

	m_hSocketCli = socket(AF_INET, SOCK_STREAM, 0);
	if (m_hSocketCli == INVALID_SOCKET)
	{
		wprintf(L"socket function failed with error: %u\n", WSAGetLastError());

		return;
	}

	m_addrCli.sin_addr.s_addr = INADDR_ANY;
	m_addrCli.sin_family = AF_INET;
	printf("当前端口号 =====  %d\n", m_iLocalPort);
	m_addrCli.sin_port = htons(m_iLocalPort);

	m_addrSer.sin_addr.s_addr = inet_addr(CHAT_SERVER_SOCKET_IP);
	m_addrSer.sin_family = AF_INET;
	m_addrSer.sin_port = htons(CHAT_SERVER_SOCKET_PROT);

	int ret = bind(m_hSocketCli, (sockaddr*)&m_addrCli, sizeof(m_addrCli));
	if (ret == SOCKET_ERROR)
	{
		wprintf(L"bind failed with error %u\n", WSAGetLastError());
		close();
		return;
	}

	// socket 默认是阻塞式的。 accept 和 recv 都是阻塞式的。
	u_long on = 1;
	ioctlsocket(m_hSocketCli, FIONBIO, &on);
}

void CChatSocketClient::close()
{
	closesocket(m_hSocketCli);
	m_hSocketCli = INVALID_SOCKET;
}

void CChatSocketClient::start()
{
	if (startRunning())
		printf("==================welcome. start================\n");
	else return;
	while (true)
	{
		char recvBuf[SOCKET_BUF_SIZE];
		memset(recvBuf, 0, sizeof(recvBuf));
		int ret = connect(m_hSocketCli, (sockaddr*)&m_addrSer, sizeof(m_addrSer));

		if (ret == SOCKET_ERROR)
		{
			int r = WSAGetLastError();
			if (r == WSAEWOULDBLOCK || r == WSAEINVAL)
			{
				Sleep(20);
				continue;
			}
			else if (r == WSAEISCONN)//套接字原来已经连接！！
			{
				break;
			}
			else
			{
				std::cout << "发生错误" << std::endl;
				return;
			}
		}

		if (ret != SOCKET_ERROR)
		{
			printf("连接成功\n");
			break;
			//ret = recv(m_hSocketCli, recvBuf, sizeof(recvBuf), 0);
			//if (ret > 0) onReceiveMsg(recvBuf);
		}

	}
	m_bIsConnected = true;
}

bool CChatSocketClient::isConnected()
{
	return m_bIsConnected;
}

bool CChatSocketClient::disconnect()
{
	m_bIsConnected = false;
	return true;
}

void CChatSocketClient::onReceiveMsg(const string& msg)
{
	printf("接收信息：msg = %s\n", msg.data());
	Json::Reader reader(Json::Features::strictMode());
	Json::Value root;
	// reader将Json字符串解析到root，root将包含Json里所有子元素
	if (reader.parse(msg, root))
	{
		if (!root["sortid"].isNull())
		{
			std::string sortid = root["sortid"].asString();
			if (sortid == "connect")
			{
				if (!root["result"].isNull())
				{
					std::string method = root["result"].asString();
					if (method == "sucess")
					{
						printf("receive msg = sucess\n");
					}
				}
			}

		}
	}
}

void CChatSocketClient::onSendMsg(const string& msg)
{
	int ret = 0;
	ret = send(m_hSocketCli, msg.data(), sizeof(msg.data()), 0);
	if (ret > 0)
	{
		printf("client send msg = sucess\n");
	}
}

bool CChatSocketClient::calc()
{
	time_t t;
	struct tm* local;
	char T[256];
	memset(T, 0, 256);
	t = time(NULL);
	local = localtime(&t);
	sprintf(T, "%d/%d/%d %d:%d:%d", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
	strcpy(m_pSendData, T);
	return true;
}

bool CChatSocketClient::startRunning()
{
	m_hRecvThread = CreateThread(NULL, 0, recvThread, (void*)this, 0, NULL);//由于static成员函数，无法访问类成员。因此传入this指针。
	if (m_hRecvThread == NULL)
	{
		return false;
	}
	m_hSendThread = CreateThread(NULL, 0, sendThread, (void*)this, 0, NULL);
	if (m_hSendThread == NULL)
	{
		return false;
	}
	return true;
}

void CChatSocketClient::startChat()
{
	while (true)
	{
		cin >> m_pSendData;

		m_bSendPermission = true;

	}
}

SOCKET CChatSocketClient::getSocketClient()
{
	return m_hSocketCli;
}

DWORD __stdcall CChatSocketClient::sendThread(void* param)
{
	std::cout << "发送数据线程开始运行！！" << std::endl;
	CChatSocketClient* pClient = static_cast<CChatSocketClient*>(param);//获得CClient对象指针。以便操纵成员变量。
	WaitForSingleObject(pClient->m_hEvent, INFINITE);//等待接收数据线程通知。
	while (pClient->isConnected())
	{
		while (pClient->getSendPermission())//可以发送数据。
		{
			std::cout << "等待接收数据线程通知！！" << std::endl;
			//
			//ResetEvent(pClient->m_hEvent);
			int ret = send(pClient->getSocketClient(), pClient->m_pSendData, 1024, 0);
			if (ret == SOCKET_ERROR)
			{
				int r = WSAGetLastError();
				if (r == WSAEWOULDBLOCK)
				{
					continue;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				std::cout << "结果发送成功！！" << std::endl;
				pClient->setSendPermission(false);
				break;
			}

		}
		Sleep(1000);//未收到发送通知，睡眠1秒。

	}
}

DWORD __stdcall CChatSocketClient::recvThread(void* param)
{
	std::cout << "接收数据线程开始运行！！" << std::endl;
	CChatSocketClient* pClient = static_cast<CChatSocketClient*>(param);
	while (pClient->isConnected())
	{
		memset(pClient->m_pRecvData, 0, 1024);
		int ret = recv(pClient->getSocketClient(), pClient->m_pRecvData, 1024, 0);
		if (ret == SOCKET_ERROR)
		{
			int r = WSAGetLastError();
			if (r == WSAEWOULDBLOCK)
			{
				//std::cout<<"没有收到来自客户端的数据！！"<<std::endl;
				Sleep(20);
				continue;
			}
			else if (r == WSAENETDOWN)
			{
				std::cout << "接收数据线程出现错误,连接中断！" << std::endl;
				break;
			}
			else
			{
				std::cout << "接收数据线程出现错误！" << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "恭喜，收到来自客户端的数据:" << pClient->m_pRecvData << std::endl;
			pClient->calc();
			std::cout << "通知发送线程发送结果！！" << std::endl;
			SetEvent(pClient->m_hEvent);
			pClient->setSendPermission(true);
		}
	}
	return 0;
}

void CChatSocketClient::setSendPermission(bool isSend)
{
	m_bSendPermission = isSend;
}

bool CChatSocketClient::getSendPermission()
{
	return m_bSendPermission;
}

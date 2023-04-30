#include "pch.h"
#include "base_socket.h"
#include "chat_socket_client.h"
#include "jsoncpp/include/json/json.h"

IChatSocketClient* DT_CreateChatSocketClient()
{
	IChatSocketClient* socketClient = new CChatSocketClient();
	return socketClient;
}


CChatSocketClient::CChatSocketClient()
	: m_iLocalPort(0)
	, m_hSocketCli(INVALID_SOCKET)
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

}

void CChatSocketClient::close()
{
	closesocket(m_hSocketCli);
	m_hSocketCli = INVALID_SOCKET;
}

void CChatSocketClient::start()
{
	printf("==================welcome. start================\n");
	while (true)
	{
		char recvBuf[SOCKET_BUF_SIZE];
		memset(recvBuf, 0, sizeof(recvBuf));
		int ret = connect(m_hSocketCli, (sockaddr*)&m_addrSer, sizeof(m_addrSer));
		if (ret != SOCKET_ERROR)
		{
			recv(m_hSocketCli, recvBuf, sizeof(recvBuf), 0);
			string recvMsg = recvBuf;
			Json::Reader reader;
			Json::Value root;
			// reader将Json字符串解析到root，root将包含Json里所有子元素
			if (reader.parse(recvMsg, root))
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
								ret = send(m_hSocketCli, recvBuf, sizeof(recvBuf),0);
								if (ret > 0)
								{
									printf("client send msg = sucess\n");
								}
							}
						}
					}

				}

			}
			printf("接收信息：msg = %s\n", recvBuf);
		}
	}
}

void CChatSocketClient::onReceiveMsg()
{

}

void CChatSocketClient::onSendMsg()
{

}

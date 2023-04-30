#include "socket_chat_room.h"
#include "multi_module_dll/include/base_socket.h"


CSocketChatRoom::CSocketChatRoom()
	: m_pChatServer(nullptr)
	, m_iServerPort(12248)
{

	m_pChatServer = DT_CreateChatSocketServer();

}

CSocketChatRoom::~CSocketChatRoom()
{
}

void CSocketChatRoom::setServerPort(int port)
{
	m_iServerPort = port;
}

void CSocketChatRoom::startServer()
{
	if (m_pChatServer)
	{
		m_pChatServer->setLocalProt(m_iServerPort);
		m_pChatServer->init();
		m_pChatServer->start();
	}
}

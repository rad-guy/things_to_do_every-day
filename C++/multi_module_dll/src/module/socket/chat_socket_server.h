#pragma once




#include <vector>

//class CChatSocketClient;
class CChatSocketServer : public IChatSocketServer
{
	//typedef vector< CChatSocketClient> VecClientGroup;
public:
	CChatSocketServer();
	virtual ~CChatSocketServer();

	virtual void setLocalProt(int port);

	virtual void init();

	virtual void close();
	virtual void start();

	//void registerClient();
	//void unregisterClient();
private:
	SOCKET m_hSocketSer;				// socket ·þÎñ
	//VecClientGroup m_vecClient;

	sockaddr_in	m_addrSer;

	int m_iLocalPort;
};
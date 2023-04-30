#pragma once


//class CChatSocketServer;
class CChatSocketClient : public IChatSocketClient
{

public:
	CChatSocketClient();
	virtual ~CChatSocketClient();

	virtual void setLocalProt(int port);

	virtual void init();

	virtual void close();
	virtual void start();


	virtual void onReceiveMsg();
	virtual void onSendMsg();
private:
	SOCKET m_hSocketCli;				// socket ¿Í»§¶Ë

	sockaddr_in	m_addrSer, m_addrCli;

	int m_iLocalPort;
};
#pragma once


typedef struct tagSChatClientInfo
{
	int	   id;
	SOCKET socket;
	string ip;
	int    port;

} SChatClientInfo;

class IChatServerSink
{
public:
	~IChatServerSink() {};
	virtual void onReceiveMsg() = 0;
};

#include <vector>

//class CChatSocketClient;
class CChatSocketServer : public IChatSocketServer
{
	typedef vector< SChatClientInfo*> VecClientGroup;
public:
	CChatSocketServer();
	virtual ~CChatSocketServer();

	virtual void setLocalProt(int port);
	virtual void setSink(IChatServerSink* sink);
	virtual void init();

	virtual void close();
	virtual void start();

	void massMsg(const string& msg);
	int  onConnectSuccess(const SOCKET& socket, const sockaddr_in& addr);

	void sendMsgToClient(int id, const string& msg);
	void sendMsgToClient(SChatClientInfo* client,const string& msg);

	void startMsgPolling();
	void registerClient(SChatClientInfo* client);
	void unregisterClient(SChatClientInfo* client);
	SChatClientInfo* getClientInfo(int id);
private:
	SOCKET m_hSocketSer;				// socket ·þÎñ
	VecClientGroup m_vecClient;

	IChatServerSink* m_pChatSink;

	sockaddr_in	m_addrSer;

	int m_iLocalPort;
};
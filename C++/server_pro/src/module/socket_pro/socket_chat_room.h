
class IChatSocketServer;
class CSocketChatRoom
{
public:
	CSocketChatRoom();
	~CSocketChatRoom();
	
	void						setServerPort(int port);
	void						startServer();
private:
	IChatSocketServer*			m_pChatServer;
	int							m_iServerPort;

};
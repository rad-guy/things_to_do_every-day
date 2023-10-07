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

	bool isConnected();
	bool disconnect();

	virtual void onReceiveMsg(const string& msg);
	virtual void onSendMsg(const string& msg);

	bool calc();//计算当前时间，并复制到发送缓冲区内。
	bool startRunning();//开始运行发送和接收线程。
	virtual void startChat();
	SOCKET getSocketClient();
	static DWORD WINAPI sendThread(void* param);//发送线程入口函数。
	static DWORD WINAPI recvThread(void* param);//接收线程入口函数。
	void setSendPermission(bool isSend);
	bool getSendPermission();
private:
	SOCKET m_hSocketCli;				// socket 客户端


	HANDLE m_hSendThread;//发送线程句柄。
	HANDLE m_hRecvThread;//接受线程句柄。

	char* m_pRecvData;//接收缓冲区。
	char* m_pSendData;//发送缓冲区。
	HANDLE m_hEvent;//发送线程和接收线程同步事件对象。接收客户端请求后通知发送线程发送当前时间。

	sockaddr_in	m_addrSer, m_addrCli;

	int m_iLocalPort;
	bool m_bIsConnected;
	bool m_bSendPermission;//由于只有接收到客户端请求后才需要发送，该变量控制是否发送数据。
};
#pragma once

#include <WinSock2.h>

class CMultiCastServer
{
public:
	CMultiCastServer();
	~CMultiCastServer();

	void setLocalPort(int port);
	void setRemoteAddr(const char* ip,int port);

	void init();		// 初始化
	void close();		// 关闭
	void setBroadCast();
	void setMultiCast();
	void start();
	int  sendUdp(const char* buf, size_t n, int opt, const struct sockaddr_in& addr);
private:
	SOCKET m_hSocket;				// socket 实例

	int    m_iLocalPort;			// 本地端口，服务只需要一个端口就可以了
	u_long m_ulRemoteIp;			// 远端ip
	int	   m_iRemotePort;			// 远端端口

	bool   m_bIsSetBroad;
	bool   m_bIsSetMulti;
};
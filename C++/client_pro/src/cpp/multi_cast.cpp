#include "multi_cast.h"
#include <iostream>
#include <WS2tcpip.h>


// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

const unsigned int RECVBUFSIZE = 1024 * 50;

CMultiCastServer::CMultiCastServer()
	: m_hSocket(INVALID_SOCKET)
	, m_iLocalPort(0)
	, m_ulRemoteIp(0)
	, m_iRemotePort(0)
	, m_bIsSetBroad(false)
	, m_bIsSetMulti(false)
{
}

CMultiCastServer::~CMultiCastServer()
{
}

void CMultiCastServer::setLocalPort(int port)
{
	m_iLocalPort = port;
}

void CMultiCastServer::setRemoteAddr(const char* ip, int port)
{
	// inet_addr 函数将包含 IPv4 点分十进制地址的字符串转换为 IN_ADDR结构的正确地址
	m_ulRemoteIp = inet_addr(ip);
	m_iRemotePort = port;
}

void CMultiCastServer::init()
{
	WSADATA wsaData;
	int iResult = 0;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"Error at WSAStartup()\n");
		return;
	}

	if (m_hSocket) close();
	// 参数1:地址族规范,AF_INET  (IPv4) 地址系列
	// 参数2:SOCK_DGRAM 使用 Internet 地址系列（AF_INET 或 AF_INET6）的用户数据报协议 (UDP)
	//		 SOCK_STREAM 使用 Internet 地址系列（AF_INET 或 AF_INET6）的传输控制协议 (TCP)
	// 参数3:如果指定值为 0，则调用者不希望指定协议，服务提供者将选择要使用的协议
	m_hSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (m_hSocket == INVALID_SOCKET)
	{
		wprintf(L"socket function failed with error: %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	//// 设置地址重用选项
	//int reuseEnable = 1;
	//if (setsockopt(m_hSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuseEnable, sizeof(reuseEnable)) < 0) {
	//	printf("setsockopt error");
	//	return;
	//}


	// sockaddr 内容均以网络字节顺序表示
	sockaddr_in localAddr;
	memset(&localAddr, 0, sizeof(localAddr));
	localAddr.sin_family = AF_INET;
	// htons 函数将 从 主机 转换为 TCP/IP网络字节顺序（大端字节序）返回 u_short
	localAddr.sin_port = htons(m_iLocalPort);
	// sin_addr.s_addr 格式为u_long的 IPv4 地址
	// htonl 函数将 从 主机 转换为 TCP/IP网络字节顺序（大端字节序）返回 u_long
	localAddr.sin_addr.s_addr = INADDR_ANY;
	// bind 函数将本地地址与套接字相关联
	int ret = bind(m_hSocket, (sockaddr*)&localAddr, sizeof(localAddr));
	if (ret == SOCKET_ERROR)
	{
		wprintf(L"bind failed with error %u\n", WSAGetLastError());
		close();
		WSACleanup();
		return;
	}
	else
		wprintf(L"bind returned success\n");

	u_long on = 1;
	// ioctlsocket 函数控制套接字的 I/O 模式
	iResult = ioctlsocket(m_hSocket, FIONBIO, &on);
	if (iResult != NO_ERROR)
	{
		printf("ioctlsocket failed with error: %ld\n", iResult);
	}

}

void CMultiCastServer::close()
{
	closesocket(m_hSocket);
}

void CMultiCastServer::setBroadCast()
{
	in_addr inaddr;
	inaddr.s_addr = m_ulRemoteIp;
	unsigned char* ip = (unsigned char*)&m_ulRemoteIp;
	if ((ip[0] == 192 || ip[0] == 172 || ip[0] == 10 || ip[0] == 255) && ip[3] == 255)
	{
		int val = 1;
		// setsockopt函数设置套接字选项
		int ret = setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST,(const char*)&val,sizeof(val));
		if (ret == SOCKET_ERROR)
		{
			printf("set broad cast error : %d", WSAGetLastError());
		}
		// inet_ntoa 函数将 (Ipv4) Internet 网络地址转换为 Internet 标准点分十进制格式的ASCII 字符串
		printf("setBroadCast ip: %s\n", inet_ntoa(inaddr));
	}
	m_bIsSetBroad = true;
}

void CMultiCastServer::setMultiCast()
{
}

void CMultiCastServer::start()
{
	char buf[RECVBUFSIZE];
	sockaddr_in from;
	socklen_t addr_len = sizeof(from);
	int len;
	while (true)
	{
		if (!m_hSocket) return;

		memset(buf, 0, sizeof(buf));
		len = recvfrom(m_hSocket, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&from, &addr_len);
		if (len > 0)
		{
			buf[len] = '\0';
			printf("RecvMessage From %s/%d:%s", inet_ntoa(from.sin_addr), ntohs(from.sin_port), buf);
		}
		Sleep(500);
	}
}

int CMultiCastServer::sendUdp(const char* buf, size_t n, int opt, const sockaddr_in& addr)
{
	int ret = sendto(m_hSocket, buf, n, opt, (struct sockaddr*)&addr, sizeof(addr));
	return 0;
}

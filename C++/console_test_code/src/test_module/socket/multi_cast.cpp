#include "test_module/socket/multi_cast.h"
//
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdio.h>
//
//#pragma comment(lib, "ws2_32.lib") // ����Windows Socket��




void CMultiCast::testBroadCast()
{
	//WSADATA wsaData;
	//int iResult;
	//SOCKET sock;


	//// ��ʼ��Winsock
	//iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	//if (iResult != 0) {
	//	printf("WSAStartup failed: %d\n", iResult);
	//	return;
	//}

	//// ����Socket
	//sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//if (sock == INVALID_SOCKET) {
	//	printf("socket failed: %ld\n", WSAGetLastError());
	//	WSACleanup();
	//	return;
	//}



	//// ���ù㲥ѡ��
	//int optval = 1;
	//iResult = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char*)&optval, sizeof(optval));
	//if (iResult == SOCKET_ERROR) {
	//	printf("setsockopt failed with error: %d\n", WSAGetLastError());
	//	closesocket(sock);
	//	WSACleanup();
	//	return;
	//}

	//// ���͹㲥��Ϣ
	//char* broadcastMsg = (char*)"Hello from broadcast!";
	//struct sockaddr_in broadcastAddr;
	//memset(&broadcastAddr, 0, sizeof(broadcastAddr));
	//broadcastAddr.sin_family = AF_INET;
	//broadcastAddr.sin_addr.s_addr = htonl(INADDR_BROADCAST); // �㲥��ַ
	//broadcastAddr.sin_port = htons(1234); // �㲥�˿�

	//iResult = sendto(sock, broadcastMsg, strlen(broadcastMsg), 0, (SOCKADDR*)&broadcastAddr, sizeof(broadcastAddr));
	//if (iResult == SOCKET_ERROR) {
	//	printf("sendto failed with error: %d\n", WSAGetLastError());
	//	closesocket(sock);
	//	WSACleanup();
	//	return;
	//}


	//// �ر�Socket��Winsock
	//closesocket(sock);
	//WSACleanup();
}

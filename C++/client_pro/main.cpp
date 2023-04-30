#include "multi_cast.h"
#include "../multi_module_dll/src/include/base_socket.h"

int main()
{
	//CMultiCastServer server;
	//server.setLocalPort(9999);
	////server.setRemoteAddr("192.168.1.255", 8888);
	//server.init();
	////server.setMultiCast();
	//server.start();

	if (!DT_Start_WinSocket_Dll())
	{
		printf("³õÊ¼»¯Ê§°Ü.");
		return 0;
	}

	IChatSocketClient* chatClient = DT_CreateChatSocketClient();
	if (chatClient)
	{
		chatClient->setLocalProt(12241);
		chatClient->init();
		chatClient->start();
	}


	DT_Clean_WinSocket_Dll();

	return 0;
}
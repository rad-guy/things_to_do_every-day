#include "app_operator.h"
#include "multi_module_dll/include/base_socket.h"
#include "module/socket_pro/socket_chat_room.h"

CAppInstance::CAppInstance()
{
}

CAppInstance::~CAppInstance()
{
}

void CAppInstance::startApp()
{
	if (!DT_Start_WinSocket_Dll())
	{
		printf("≥ı ºªØ ß∞‹.");
		return;
	}

}

void CAppInstance::stopApp()
{
	DT_Clean_WinSocket_Dll();
}

void CAppInstance::executeChatDemo()
{	
	CSocketChatRoom room;
	room.startServer();
}

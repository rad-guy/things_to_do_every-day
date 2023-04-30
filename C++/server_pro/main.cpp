#include "manager/app_operator.h"
#include <string>
#include <iostream>
#include "jsoncpp/include/json/json.h"

using namespace std;

int main()
{
	// 广播组播demo
	//CMultiCastServer server;
	//server.setLocalPort(8888);
	//server.setRemoteAddr("192.168.1.255", 9999);
	//server.init();
	//server.setBroadCast();
	////server.setMultiCast();
	//server.start();

	CAppInstance::startApp();

	
	//string jsontxt = "{\"key\":\"a\",\"value\":[{\"name\":\"jane\",\"age\":16},{\"name\":\"molia\",\"age\":18}],\"ret\":0}";
	////jsontxt = "{\"key\":\"a\"}";
	//std::string strValue = "{ \"key\":\"value1\",\"array\": [{\"arraykey\":1},{\"arraykey\":2}]}"; 
	//Json::Reader reader;
	//Json::Value root;
	//// reader将Json字符串解析到root，root将包含Json里所有子元素
	//if (reader.parse(strValue, root))
	//{
	//	if (!root["key"].isNull())
	//	{
	//		std::string strValue = root["key"].asString();
	//		std::cout << strValue << std::endl;
	//	}
	//	Json::Value arrayObj = root["array"];
	//	for (int i = 0; i < arrayObj.size(); i++)
	//	{
	//		int iarrayValue = arrayObj[i]["arraykey"].asInt();
	//		std::cout << iarrayValue << std::endl;
	//	}
	//}
	CAppInstance::executeChatDemo();

	CAppInstance::stopApp();
	return 0;
}
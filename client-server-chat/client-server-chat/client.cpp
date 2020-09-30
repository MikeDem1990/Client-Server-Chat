#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include <winsock2.h>

#pragma warning(disable:4996)

using namespace std;


int main(int argc, char* argv[])
{

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	WSAStartup(DLLVersion, &wsaData);

	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "Error" << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(111);
	addr.sin_family = AF_INET;


	SOCKET Connection = socket(AF_INET,SOCK_STREAM,NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout <<
	}
	

	system("pause");

}
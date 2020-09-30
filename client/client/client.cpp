#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include <winsock2.h>
#include <string>
#pragma warning(disable:4996)

using namespace std;

SOCKET Connection;

void ClientHandler()
{
	int msg_size;
	while (true)
	{
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);
		cout << msg << endl;
		delete[] msg;
		 
	}
} 
 
int main(int argc, char* argv[])
{

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);

	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "Error" << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;


	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Error: failed connect to server.";
		return 1;
	}
	/*
	cout << "Connected!\n";
	char msg[256];
	recv(Connection, msg, sizeof(msg), NULL);
	cout << msg << "\n";
	*/
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	string msgl;
	
	while (true)
	{
		getline(cin,msgl);
		int msg_size = msgl.size();
		send(Connection, (char*)&msg_size, sizeof(int), NULL);
		send(Connection, msgl.c_str(), msg_size, NULL);
		Sleep(10);
	}

	system("pause");

	return 0;
}
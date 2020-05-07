#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
int main()

{

    long SUCCESSFUL;

    WSAData WinSockData;

    WORD DLLVERSION;



    DLLVERSION = MAKEWORD(2, 1);

    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);



    SOCKADDR_IN ADDRESS;

    int AddressSize = sizeof(ADDRESS);



    SOCKET sock_LISTEN;

    SOCKET sock_CONNECTION;



    sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);

    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");

    ADDRESS.sin_family = AF_INET;

    ADDRESS.sin_port = htons(8085);



    sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);   

    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

    listen(sock_LISTEN, SOMAXCONN);



    char msg[200];

    string MSG;



    for (;;)

    {

        cout << "\n\tSERVER: Waiting for incoming connections...";



        if (sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize))

        {

            cout << "\n\tA connection was found!" << endl;

            SUCCESSFUL = recv(sock_CONNECTION, msg, sizeof(msg), NULL);

            MSG = msg;

            cout << MSG << endl;

            closesocket(sock_CONNECTION);

        }

    }

}

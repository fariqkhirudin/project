#include <stdlib.h>

#include <stdio.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>



int main()

{

	char ServerMsg [256] = "Waalaikumussalam w.b.t";

	char ServerAcpt [100];

	

	int ServerSocket;

	ServerSocket = socket(AF_INET,SOCK_STREAM,0);

	

	/*cannot be changed*/

	struct sockaddr_in ipv4server; /*set socket attribute*/

	

	ipv4server.sin_family = AF_INET; // ACCEPT IPV4 & IPV6

	

	ipv4server.sin_port = htons(10500); //set port

	

	ipv4server.sin_addr.s_addr = INADDR_ANY;

	

	

	bind(ServerSocket,(struct sockaddr *) &ipv4server,sizeof(ipv4server)); //bind process

	

	

	listen(ServerSocket,10); //listen

	

	

	/*accept data from client*/

	

	int ClientSocket = accept(ServerSocket, NULL,NULL);

	

	recv(ClientSocket , ServerAcpt , sizeof(ServerAcpt), 0);  //receice from client

	

	send(ClientSocket , ServerMsg , sizeof(ServerMsg), 0); //send message to client

	

	printf("Message from client :");

	

	printf(ServerAcpt);

	

	close(ServerSocket);

	

	return 0;

	

	

	}

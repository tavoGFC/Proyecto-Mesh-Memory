/*
 * SocketCtoJ.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: ricardo
 */

#include "SocketCtoJ.h"


SocketCtoJ::SocketCtoJ() {
	MAXDATASIZE=1024;
}

int SocketCtoJ::conectar(string hostIP, int port) {
	MAXDATASIZE=1024;

	const char * host = hostIP.c_str(); /*Convert the string to a char* */

	//int result = 1;

//	//nuevas pruebas
//	char buffer[MAXDATASIZE];
	//host del servidor
	//char *host = "192.168.1.5";
	/*fichero descriptor*/
	//int descriptor;
	/*recibe informacion sobre el nodo remoto*/
	struct hostent *hostC;
	/*informacion sobre la direccion del servidor*/
	struct sockaddr_in server;



	if ((hostC = gethostbyname(host)) == NULL){
		printf("gethostbyname() error\n");
		//result = -1;
		return -1;
	}

	if ((descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("socket() error\n");
		return -1;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	//pasa la informacion de *hostC a h_addr
	server.sin_addr = *((struct in_addr *)hostC->h_addr);
	bzero(&(server.sin_zero), 8);

	if (connect(descriptor, (struct sockaddr *)&server, sizeof(struct sockaddr))  == -1){
		printf("connect() error\n");
		//result = -1;
		return -1;
	}
	return 1;
}

void SocketCtoJ::sendMessage(string mensaje){
	mensaje+=" \n";
	const char * mensajeChar = mensaje.c_str(); /*Convert the string to a char* */

	//permite recibir n cantidad de mensajes, escritos desde consola
	//printf("Please enter the message: ");
	bzero(buffer, MAXDATASIZE);
	//fgets(buffer, MAXDATASIZE-1, stdin);
	//char str1[]= mensajeChar ;
	strncpy(buffer, mensajeChar, sizeof(buffer));
	int n;
	n = write(descriptor, buffer, strlen(buffer));
	if (n < 0){
		printf("Error write()\n");
		//break;
		//result = -1;
		//return -1;
	}
	bzero(buffer, MAXDATASIZE);
	n = read(descriptor, buffer, MAXDATASIZE-1);
	if (n < 0){
		printf("error read()\n");
		//return -1;
	}
}

SocketCtoJ::~SocketCtoJ() {
	// TODO Auto-generated destructor stub
}


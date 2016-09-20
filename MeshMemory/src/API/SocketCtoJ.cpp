/*
 * SocketCtoJ.cpp
 *
 *  Created on: Sep 16, 2016
 *  Author: ricardo, randy, gustavo
 */

#include "SocketCtoJ.h"

/**
 * Constructor
 */
SocketCtoJ::SocketCtoJ() {
	MAXDATASIZE=1024;
	this->descriptor = descriptor;
}


/**
 * Destroyer
 */
SocketCtoJ::~SocketCtoJ() {
}

/**
 *
 * Connects the Client-C++(Mesh Mem Client)to the
 * Server-Java (MeshMem Manager).
 *
 * Returns 1 when successful, -1 when unsuccessful.
 *
 * @params string hostIP, int port
 */
int SocketCtoJ::startConnection(string hostIP, int port) {
	MAXDATASIZE=1024;
	const char * host = hostIP.c_str();
	struct hostent *hostC;
	struct sockaddr_in server;
	if ((hostC = gethostbyname(host)) == NULL){
		printf("gethostbyname() error\n");
		return -1;
	}

	if ((descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("socket() error\n");
		return -1;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr = *((struct in_addr *)hostC->h_addr);
	bzero(&(server.sin_zero), 8);
	if (connect(descriptor, (struct sockaddr *)&server, sizeof(struct sockaddr))  == -1){
		printf("connect() error\n");
		return -1;
	}
	return 1;
}

/**
 * Receives a message from the Server-Java (MeshMem Manager)
 *for print it into the  Client-C (MeshMem Client)'s screen.
 *
 *Returns a int on whether the was receive or not.
 *
 *@params, char* buffer, int longitudMensaje
 */
int SocketCtoJ::receiveMsj(char* buffer, int longitudMensaje){
	int Leido = 0;
	int Aux = 0;
	if ((descriptor == -1) || (buffer == NULL) || (longitudMensaje < 1))
		return -1;
	while (Leido < longitudMensaje){
		Aux = read (descriptor, buffer , longitudMensaje - Leido);
		if (Aux > 0){
			Leido = Leido + Aux;
		}
		else{
			if (Aux == 0)
				return Leido;
			if (Aux == -1){
				switch (errno){
					case EINTR:
					case EAGAIN:
						usleep (100);
						break;
					default:
						return -1;
				}
			}
		}
	}
	return Leido;
}



/**
 * Sends a message from the  Client-C++ (MeshMem Client)
 * to the Server-Java (MeshMem Manager).
 *
 * @params string mensaje
 */
void SocketCtoJ::sendMsj(string mensaje){
	mensaje+=" \n";
	const char * mensajeChar = mensaje.c_str();
	bzero(buffer, MAXDATASIZE);
	strncpy(buffer, mensajeChar, sizeof(buffer));
	int n;
	n = write(descriptor, buffer, strlen(buffer));
	if (n < 0){
		printf("Error write()\n");
	}
	bzero(buffer, MAXDATASIZE);
	n = read(descriptor, buffer, MAXDATASIZE-1);
	if (n < 0){
		printf("error read()\n");
	}
}




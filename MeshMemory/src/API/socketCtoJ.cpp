/*
 * main.cpp
 *
 *  Created on: 13 de set. de 2016
 *      Author: gustavo
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

/* Puerto abierto del nodo remoto*/
#define PORT 8080

/*numero maximo de dats en bytes*/
#define MAXDATASIZE 1024



using namespace std;

int main(){

	//host del servidor
	char *host = "192.168.1.3";

	string mensaje = "Mensaje desde C++\n";

	/*fichero descriptor*/
	int descriptor, numbt;
	/*texto recibido*/
	char buf[MAXDATASIZE];
	/*recibe informacion sobre el nodo remoto*/
	struct hostent *hostC;
	/*informacion sobre la direccion del servidor*/
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
	server.sin_port = htons(PORT);
	//pasa la informacion de *hostC a h_addr
	server.sin_addr = *((struct in_addr *)hostC->h_addr);
	bzero(&(server.sin_zero), 8);

	if (connect(descriptor, (struct sockaddr *)&server, sizeof(struct sockaddr))  == -1){
		printf("connect() error\n");
		return -1;
	}

	//recibe informacion indefinida
	if ((numbt = recv(descriptor, buf, MAXDATASIZE, 0)) == -1){
		printf("error en recv() \n");
		return -1;
	}

	//no esta enviando mensaje
	if ((send(descriptor, mensaje.c_str(), strlen(mensaje.c_str() ), 0)) < 0){
		printf("error en send() \n");
		return -1;
	}

	buf[numbt];

	printf("Mensaje del Servidor: %s\n", buf);

	close(descriptor);

}

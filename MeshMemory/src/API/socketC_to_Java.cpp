/*
 * socketC_to_Java.cpp
 *
 *  Created on: 13 de set. de 2016
 *  Modified on: 15 de set. de 2016
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

	//nuevas pruebas
	char buffer[MAXDATASIZE];
	//host del servidor
	char *host = "192.168.1.5";
	/*fichero descriptor*/
	int descriptor;
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

	int n;
	while(true){
	//permite recibir n cantidad de mensajes, escritos desde consola
		printf("Please enter the message: ");
		bzero(buffer, MAXDATASIZE);
		fgets(buffer, MAXDATASIZE-1, stdin);
		//char str1[]= "Hola Manager, estoy en C+\n";
		//strncpy(buffer, str1, sizeof(buffer));
		n = write(descriptor, buffer, strlen(buffer));
		if (n < 0){
			printf("Error write()\n");
			break;
			return -1;
		}
	}

	bzero(buffer, MAXDATASIZE);
	n = read(descriptor, buffer, MAXDATASIZE-1);
	if (n < 0){
		printf("error read()\n");
		return -1;
	}


}

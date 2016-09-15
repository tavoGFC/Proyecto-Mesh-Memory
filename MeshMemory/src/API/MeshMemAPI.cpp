/*
 * MeshMemAPI.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: randy
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

int Lee_Socket (int fd, char *Datos, int Longitud){
	int Leido = 0;
	int Aux = 0;


	if ((fd == -1) || (Datos == NULL) || (Longitud < 1))
		return -1;

	while (Leido < Longitud){
		Aux = read (fd, Datos , Longitud - Leido);
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

int Escribe_Socket (int fd, char *Datos, int Longitud){
	int Escrito = 0;
	int Aux = 0;

	if ((fd == -1) || (Datos == NULL) || (Longitud < 1))
		return -1;

	while (Escrito < Longitud){

		Aux = write (fd, Datos + Escrito, Longitud - Escrito);
		if (Aux > 0){

			Escrito = Escrito + Aux;
		}
		else{

			if (Aux == 0)
				return Escrito;
			else
				return -1;
		}
	}
	return Escrito;
}


int ini tialize(char* host, int port){


	//host del servidor
	//char *host = "192.168.43.26";
	int Aux;
	/*fichero descriptor*/
	int descriptor;
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


	read(descriptor, buf, MAXDATASIZE);
	if ((read(descriptor, buf, MAXDATASIZE)) < 0){
			printf("error en read() \n");
			return -1;
	}

	Aux = htonl(MAXDATASIZE);

	Escribe_Socket(descriptor, (char *)&Aux, sizeof(MAXDATASIZE));


	char mensaje1[MAXDATASIZE];
	strcpy(mensaje1, "Mensaje enviado desde Client C++\n");

	Escribe_Socket(descriptor, mensaje1, MAXDATASIZE);
	cout << "Mensaje enviado a Manager: " << mensaje1 << endl;

	int longitud;
	char mensaje[MAXDATASIZE];
	//recibe informacion indefinida
	Lee_Socket(descriptor, (char *)&Aux, sizeof(int));
	longitud = ntohl(MAXDATASIZE);

	Lee_Socket(descriptor, mensaje, longitud);
	cout << "Mensaje recibido de Manager: " << mensaje << endl;




	close(descriptor);


}


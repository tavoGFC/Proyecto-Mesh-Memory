/*
// * main.cpp
// *
// *  Created on: 13 de set. de 2016
// *      Author: gustavo
// */


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

	/*
	* Comprobacion de que los parametros de entrada son correctos
	*/
	if ((fd == -1) || (Datos == NULL) || (Longitud < 1))
		return -1;

	/*
	* Mientras no hayamos leido todos los datos solicitados
	*/
	while (Leido < Longitud){
		Aux = read (fd, Datos , Longitud - Leido);
		if (Aux > 0){
			/*
			* Si hemos conseguido leer datos, incrementamos la variable
			* que contiene los datos leidos hasta el momento
			*/
			Leido = Leido + Aux;
		}
		else{
			/*
			* Si read devuelve 0, es que se ha cerrado el socket. Devolvemos
			* los caracteres leidos hasta ese momento
			*/
			if (Aux == 0)
				return Leido;
			if (Aux == -1){
				/*
				* En caso de error, la variable errno nos indica el tipo
				* de error.
				* El error EINTR se produce si ha habido alguna
				* interrupcion del sistema antes de leer ningun dato. No
				* es un error realmente.
				* El error EGAIN significa que el socket no esta disponible
				* de momento, que lo intentemos dentro de un rato.
				* Ambos errores se tratan con una espera de 100 microsegundos
				* y se vuelve a intentar.
				* El resto de los posibles errores provocan que salgamos de
				* la funcion con error.
				*/
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

	/*
	* Se devuelve el total de los caracteres leidos
	*/
	return Leido;
}


int Escribe_Socket (int fd, char *Datos, int Longitud){
	int Escrito = 0;
	int Aux = 0;

	/*
	* Comprobacion de los parametros de entrada
	*/
	if ((fd == -1) || (Datos == NULL) || (Longitud < 1))
		return -1;

	/*
	* Bucle hasta que hayamos escrito todos los caracteres que nos han
	* indicado.
	*/

	while (Escrito < Longitud){

		Aux = write (fd, Datos + Escrito, Longitud - Escrito);
		if (Aux > 0){
			/*
			* Si hemos conseguido escribir caracteres, se actualiza la
			* variable Escrito
			*/
			Escrito = Escrito + Aux;
		}
		else{
			/*
			* Si se ha cerrado el socket, devolvemos el numero de caracteres
			* leidos.
			* Si ha habido error, devolvemos -1
			*/
			if (Aux == 0)
				return Escrito;
			else
				return -1;
		}
	}

	/*
	* Devolvemos el total de caracteres leidos
	*/
	return Escrito;
}


int main(){

	//host del servidor
	char *host = "192.168.43.26";
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

/*
 * SocketCtoJ.h
 *
 *  Created on: Sep 16, 2016
 *      Author: ricardo, randy, gustavo
 */

#ifndef API_SOCKETCTOJ_H_
#define API_SOCKETCTOJ_H_
using namespace std;

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

/**
 * Class for the creation for a C/C++ socket.
 */

class SocketCtoJ {
private:
	int MAXDATASIZE;
	int descriptor;
public:
	SocketCtoJ();
	virtual ~SocketCtoJ();
	int startConnection(string host, int port);
	int receiveMsj(char* buffer, int longitud);
	void sendMsj(string mensaje);
	char buffer[1024];
	char getBuffer();
};


#endif /* API_SOCKETCTOJ_H_ */

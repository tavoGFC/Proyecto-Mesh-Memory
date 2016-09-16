/*
 * SocketCtoJ.h
 *
 *  Created on: Sep 16, 2016
 *      Author: ricardo
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

class SocketCtoJ {
private:
	int MAXDATASIZE;
	int descriptor;
	char buffer[1024];
public:
	SocketCtoJ();
	virtual ~SocketCtoJ();
	int conectar(string host, int port);
	void sendMessage(string mensaje);
};


#endif /* API_SOCKETCTOJ_H_ */

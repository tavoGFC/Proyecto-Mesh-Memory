/*
 * MeshMemAPI.h
 *
 *  Created on: Sep 14, 2016
 *      Author: randy
 */

#ifndef MESHMEMAPI_H_
#define MESHMEMAPI_H_

#include "xReference.h"
#include "SocketCtoJ.h"

using namespace std;

class MeshMemAPI{
private:
	SocketCtoJ mySocket;
public:
	MeshMemAPI();
	virtual ~MeshMemAPI();
	SocketCtoJ getSocket();
	xReference xMalloc(int size, string type);
	xReference xMalloc(int size, string type, string value);
	void xAssign(xReference reference, string value);
	void xFree(xReference toFree);

	bool verifyType(string type);

};

#endif /* MESHMEMAPI_H_ */

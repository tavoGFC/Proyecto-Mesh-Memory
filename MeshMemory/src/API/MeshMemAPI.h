/*
 * MeshMemAPI.h
 *
 *  Created on: Sep 14, 2016
 *      Author: randy
 */

#ifndef MESHMEMAPI_H_
#define MESHMEMAPI_H_

#include "xReference.h"
#include "Token.h"

int ini tialize(char* host, int port);
xReference xMalloc(int size, void type);
xReference xMalloc(int size, void type, void* value);
void xAssign(xReference reference, void* value);
void xFree(xReference toFree);
int Escribe_Socket (int fd, char *Datos, int Longitud);
int Lee_Socket (int fd, char *Datos, int Longitud);

#endif /* MESHMEMAPI_H_ */

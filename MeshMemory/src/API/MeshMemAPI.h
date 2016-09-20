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

/**
 * MeshMem API is an .h source file that contains the firm
 * and prototype of the functions that made up the API.
 *
 * All functions are available to use when the connection
 * between the Server-Java (MeshMem Manager) and the Client-
 * C++ (MeshMem Client) is set up.
 */

xReference xMalloc(int size, void* type);
xReference xMalloc(int size, void* type, void* value);
void xAssign(xReference reference, void* value);
void xFree(xReference toFree);


#endif /* MESHMEMAPI_H_ */

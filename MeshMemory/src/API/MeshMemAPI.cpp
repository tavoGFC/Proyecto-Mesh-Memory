/*
 * MeshMemAPI.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: randy
 */

#include "MeshMemAPI.h"
#include <iostream>
#include <string>
#include "xReference.h"

MeshMemAPI::MeshMemAPI(){

}
MeshMemAPI::~MeshMemAPI(){

}
bool MeshMemAPI::verifyType(string type){
	if (type=="string"){
		return true;
	}
	else if (type=="int"){
			return true;
		}
	else if (type=="float"){
			return true;
		}
	else if (type=="double"){
			return true;
		}
	else if (type=="char"){
			return true;
		}
	else{
		return false;
	}

}

SocketCtoJ MeshMemAPI::getSocket(){
	return mySocket;
}

xReference MeshMemAPI::xMalloc(int size, string type){
	xReference ref=xReference(size, type);
	return ref;

}
xReference MeshMemAPI::xMalloc(int size, string type, string value){
	xReference ref=xReference(size, type);
	return ref;


}
void MeshMemAPI::xAssign(xReference reference, string value){

}
void MeshMemAPI::xFree(xReference toFree){

}

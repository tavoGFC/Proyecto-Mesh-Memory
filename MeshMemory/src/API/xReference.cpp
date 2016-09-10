/*
 * xReference.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: randy
 */

#include "xReference.h"

xReference::xReference() {
}


xReference::xReference(int id, int size) {
	this->id = id;
	this->size = size;
}

xReference::~xReference() {
}


bool xReference::operator ==(xReference xRef2){
	bool boolResult;
	if(this->id == xRef2.id){
		boolResult = true;
	}else{
		boolResult = false;
	}
	return boolResult;
}

bool xReference::operator !=(xReference xRef2){
	bool boolResult;
	if(this->id != xRef2.id){
		boolResult = true;
	}else{
		boolResult = false;
	}
	return boolResult;
}

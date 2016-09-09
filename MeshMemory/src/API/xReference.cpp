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


/*bool xReference::operator ==(const xReference& xRef1, const xReference& xRef2){
	bool boolResult;
	if(xRef1.id == xRef2.id && xRef1.size == xRef2.size ){
		boolResult = true;
	}else{
		boolResult = false;
	}
	return boolResult;
}

Pareja& operator +(const Pareja &p1,const Pareja &p2)
{
  return *(new Pareja(p1.a + p2.a, p1.b + p2.b) );
}
*/

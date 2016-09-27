/*
 * xReference.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: randy
 */

#include "xReference.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

/**
 * Constructor for an xReference object.
 *
 */
xReference::xReference() {
}

/**
 * Constructor for an xReference object. Initializes some attributes.
 *
 */
xReference::xReference(int size, string type) {
	this->size = size;
	this->type=type;
	this->id= this->generateID();
}


/**
 * Destroyer for an xReference object.
 */
xReference::~xReference() {
}

/**
 * Returns the id for an xReference object.
 *
 * @return id
 */
string xReference::getID(){
	return id;
}

/**
 * Returns the type for an xReference object.
 *
 * @return type
 */
string xReference::getType(){
	return type;
}

/**
 * Returns the size for an xReference object.
 *
 * @param size
 */
void xReference::setSize(int size){
	this->size = size;
}

/**
 * Returns the size for an xReference object.
 *
 * @return size
 */
int xReference::getSize(){
	return size;
}

/**
 * Set the data to save as a string. Merely representation.
 */
void xReference::setData(string data){
	this->data = data;
}

/**
 * Returns the data form the xReference obj as a string. Merely representation.
 *
 * @return data
 */
string xReference::getData(){
	return data;
}

/**
 * Free the data from a xRefenrence obj. Set the data to NULL.
 */
void xReference::freeData(){
	string null = "";
	this->data =(null);
}


/**
 * Compares two xReference, if equal returns true, else false.
 *
 * @param xReference xRef2
 * @return bool
 */
bool xReference::operator ==(xReference xRef2){
	bool boolResult;
	if(this->id == xRef2.id){
		boolResult = true;
	}else{
		boolResult = false;
	}
	return boolResult;
}


/**
 * Compares two xReference, if not equal returns true, else false.
 *
 * @param xReference xRef2
 * @return bool
 */
bool xReference::operator !=(xReference xRef2){
	bool boolResult;
	if(this->id != xRef2.id){
		boolResult = true;
	}else{
		boolResult = false;
	}
	return boolResult;
}



void xReference::operator =(xReference xRef2){
	xReference *ptrThis = &this;
	xReference *ptrxRef2 = &xRef2;
	*ptrThis = *xRef2;
	xRef2.~xReference();
}


/**
 * Overset the value of this data to a NULL.
 */
void xReference::operator =(string null){
	this->data=null;
}


/**
 * Converts an number (int) into a string.
 *
 * @param <T> number
 * @return bool
 */
template <typename T>
string xReference::NumberToString ( T Number ){
     ostringstream ss;
     ss << Number;
     return ss.str();
 }

/**
 * Creates an ID for an xReference object.
 *
 * @return id
 */
string xReference::generateID(){
	string id, ID;
		for(int j = 0; j < 5; j++){
			clock_t start = clock();
			int timeInt = start;
			string s = NumberToString(timeInt);
			id = generateID_Aux(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
			ID +=id;
		}
		return ID;
}

/**
 * Auxiliar function to generateID().
 *
 * @return id
 */
string xReference::generateID_Aux(unsigned char const* bytes_to_encode, unsigned int in_len) {
	  string ret;
	  int i = 0;
	  int j = 0;
	  unsigned char char_array_3[3];
	  unsigned char char_array_4[4];

	  while (in_len--){
	    char_array_3[i++] = *(bytes_to_encode++);
	    if (i == 3){
	      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	      char_array_4[3] = char_array_3[2] & 0x3f;

	      for(i = 0; (i <4) ; i++)
	        ret += base64_chars[char_array_4[i]];
	      i = 0;
	    }
	  }

	  if (i){
	    for(j = i; j < 3; j++)
	      char_array_3[j] = '\0';

	    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	    char_array_4[3] = char_array_3[2] & 0x3f;

	    for (j = 0; (j < i + 1); j++)
	      ret += base64_chars[char_array_4[j]];

	    while((i++ < 3))
	      ret += '-';
	  }
	  return ret;
	}

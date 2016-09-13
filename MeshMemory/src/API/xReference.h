/*
 * xReference.h
 *
 *  Created on: Sep 7, 2016
 *      Author: randy
 */

#ifndef XREFERENCE_H_
#define XREFERENCE_H_

#include <iostream>
using namespace std;


/**
 * Creates an object xReference.
 *
 */
class xReference {

private:
	string id; //ID that identifies each xRefe created.
	int size; // Integer that show only the byte size of the data.

public:

	xReference();
	virtual ~xReference();
	string getID();
	void setSize(int size);
	int getSize();
	xReference& operator *();
	bool operator ==(xReference xRef2);
	bool operator !=(xReference xRef2);
	//void operator =();
	string generateID();
	string generateID_Aux(unsigned char const* bytes_to_encode, unsigned int in_len);

	template <typename T>
	string NumberToString ( T Number );

	 string base64_chars =
				             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				             "abcdefghijklmnopqrstuvwxyz"
				             "0123456789+/";


};

#endif /* XREFERENCE_H_ */

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
 * Creates an object xReference. That stands as a references
 * for a memory piece that is in the mesh network. It has an
 * id for it's identification and the size that is wanted to
 * be saved.
 */
class xReference {

private:
	string id;
	int size;
	string type;

public:
	xReference();
	xReference(int size, string type);
	virtual ~xReference();

	string getID();;
	void setSize(int size);
	int getSize();
	string getType();

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

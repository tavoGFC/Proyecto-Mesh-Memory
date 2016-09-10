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

class xReference {
private:
	int id; // UUID
	int size; // int that show only the byte size of the data
public:

	xReference();
	xReference(int id, int size);
	virtual ~xReference();
	//xReference& operator *();
	bool operator ==(xReference xRef2);
	bool operator !=(xReference xRef2);
	//void operator =();

};

#endif /* XREFERENCE_H_ */

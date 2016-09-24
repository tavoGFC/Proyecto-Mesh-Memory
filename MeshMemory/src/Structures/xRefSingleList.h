/*
 * xRefSingleList.h
 *
 *  Created on: Sep 20, 2016
 *      Author: ricardo
 */

#ifndef STRUCTURES_XREFSINGLELIST_H_
#define STRUCTURES_XREFSINGLELIST_H_

#include <iostream>
#include <stdio.h>
#include <sstream>
#include "../API/xReference.h"

using namespace std;

class xRefSingleList {
public:
	xRefSingleList();
	virtual ~xRefSingleList();
	void insertData(xReference addData);
	void deleteData(xReference delData);
	void printList();
	xReference getDataX(int x);
private:
	struct Node{
		xReference value;
		Node *next;
		int posc;
	};

	int len;
	struct Node *head;
};



#endif /* STRUCTURES_XREFSINGLELIST_H_ */

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

	xReference& operator *();
	//xReference& operator +();
	/*bool inline operator ==(const xReference& xRef1, const xReference& xRef2){
		bool boolResult;
			if(xRef1.id == xRef2.id && xRef1.size == xRef2.size ){
				boolResult = true;
			}else{
				boolResult = false;
			}
			return boolResult;
		}
*/
	//bool operator !=(const xReference& xRef1, const xReference& xRef2);
	//void operator =();

	//Pareja& operator +(const Pareja &p1,const Pareja &p2)
	//tipo  nombre_clase::operator + (lista de parámetros);
};

#endif /* XREFERENCE_H_ */

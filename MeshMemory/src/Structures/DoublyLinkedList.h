/*
 * DoublyLinkendList.h
 *
 *  Created on: Sep 6, 2016
 *      Author: randy
 */

#ifndef DOUBLYLINKENDLIST_H_
#define DOUBLYLINKENDLIST_H_
#include <iostream>
using namespace std;

class DoublyLinkedList {

	struct Node{
		        string value;
		        Node *next;
		        Node *previous;
		        int posc;
		    };
	private:
		int len;
		Node *head;
		Node *tail;

	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		void insertData(string addData);
		void deleteData(string delData);
		void printListLeftRight(); //PrintListIzDer();
		void printListRightLeft(); //PrintListDerIz();
		string getDataX(int x);
};

#endif /* DOUBLYLINKENDLIST_H_ */

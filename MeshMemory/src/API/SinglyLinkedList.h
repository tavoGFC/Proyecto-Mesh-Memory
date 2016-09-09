/*
 * SinglyLinkedList.h
 *
 *  Created on: Sep 5, 2016
 *      Author: randy
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <iostream>

using namespace std;

class SinglyLinkedList {

	public:
		SinglyLinkedList();
		~SinglyLinkedList();
		void insertData(string addData);
		void deleteData(string delData);
		void printList();
		string getDataX(int x);

		struct Node{
			        string value;
			        Node *next;
			        int posc;
			};

		int len;
		struct Node *head;

};

#endif /* SINGLYLINKEDLIST_H_ */

/*
 * DoublyLinkedList.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: randy
 */

#include "DoublyLinkedList.h"
#include <iostream>


/**
 * Constructor
 */
DoublyLinkedList::DoublyLinkedList() {
	len=0;
	head=NULL;
	tail=NULL;
}

DoublyLinkedList::~DoublyLinkedList(){
}

/**
 * Adds a node with the given value to the end of the list
 */
void DoublyLinkedList::insertData(string newValue){
	Node* newNode= new Node();
	newNode->value=newValue;
	if (head!=NULL){	//if list is not empty
		tail->next = newNode;
		newNode->previous=tail;
		newNode->posc = len;
		tail=newNode;
		len++;
	}else{	//if list is empty
		head=newNode;
		tail=newNode;
		newNode->posc=0;
		len=1;
	}
}

/**
 * Deletes the first node that is found with the given value
 */
void DoublyLinkedList::deleteData(string nodeValue){
	if (head==NULL){	//first case: Empty list
		cout << "ERROR"<<endl;
		return;
	}
	Node *temp=head;
	Node *temp2=temp->next;
	bool flagDeleated=false;

	if ((head->value)==nodeValue){	//second case: found at the beginning
		head=head->next;
		head->previous=NULL;
		temp=temp->next;
		flagDeleated=true;
	}else{	//third case: anywhere else
		while((flagDeleated == false)&&(temp2!=NULL)){	//temp2 sea dif de NULL es por si el valor no esta
			if ((temp2->value)==nodeValue){	//si encuentra el valor
				if (temp2->next==NULL){	//si el valor esta al final
					tail=temp;
					temp->next = NULL;
					temp=temp2;
					flagDeleated=true;
				}else{		//si el valor esta en algun otro lugar
					temp2=temp2->next;
					temp->next = temp2;
					temp2->previous=temp;
					temp=temp2;
					flagDeleated=true;
				}
			}else{
				temp=temp2;
				temp2=temp2->next;
			}
		}
	}
	if(flagDeleated==false){	//mensaje de error si no se encuentra el valor
		cout<<"ERROR";
		cout<< nodeValue;
		cout<< "-1" <<endl;
		return;
	}
	while(temp!=NULL){	//para cambiar los sub-indices que se alteraron
		temp->posc--;
		temp=temp->next;
	}
	len--;	//se disminuye el largo de la lista
}

/**
 * Prints the list from left to right
 */
void DoublyLinkedList::printListLeftRight(){
	Node *temp=head;
	    while(temp!=NULL){
	    	cout<<"<= ";
	        cout<<temp->value;		//print the value
	        cout << " [";
	        cout << (temp->posc) ;	//print the position
	        cout << "] => " ;
	        temp=temp->next;
	    }
	    cout<<endl;

}

/**
 * Prints the list from right to left
 */
void DoublyLinkedList::printListRightLeft(){
	Node *temp=tail;
	    while(temp!=NULL){
	    	cout<<"<= ";
	        cout<<temp->value;		//print the value
	        cout << " [";
	        cout << (temp->posc) ;	//print the position
	        cout << "] => " ;
	        temp=temp->previous;
	    }
	    cout<<endl;

}


/**
 * Gets the node value by giving the position
 */
string DoublyLinkedList::getDataX(int x){
	if (head==NULL){
		cout << "ERROR: Lista vacia"<<endl;
		return false;
	}else if (x >= len or x<0){
		cout << "Error: Valor ingresado invalido" << endl;
		return false;
	}else{
		Node *temp=head;
		string nodeValue;
		while(temp!=NULL){
			if (temp->posc == x){
				nodeValue = temp->value;
				break;
			}else{
				temp=temp->next;
			}
		}
		cout << nodeValue <<endl;  //print the value
		return nodeValue;
	}
}

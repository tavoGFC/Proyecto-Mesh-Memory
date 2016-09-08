/*
 * SinglyLinkedList.cpp
 *
 *  Created on: Sep 5, 2016
 *      Author: randy
 */

#include "SinglyLinkedList.h"


SinglyLinkedList::SinglyLinkedList() {
	len=0;
	head=NULL;
}

SinglyLinkedList::~SinglyLinkedList(){

}

void SinglyLinkedList::insertData(string newValue) {	//adds a new node with the given value
	Node* newNode= new Node();
	newNode->value=newValue;

	if (head!=NULL){	//if list is not empty
		Node *temp=head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newNode;
		newNode->posc = len;
		len++;

	}else{	//if list is empty
		head=newNode;
		newNode->posc=0;
		len=1;
	}
}

void SinglyLinkedList::deleteData(string nodeValue){	//deletes the first node that is found with the given value
	if (head==NULL){	//first case: Empty list
		cout << "ERROR"<<endl;
		return;
	}
	Node *temp=head;
	Node *temp2=temp->next;
	bool flagDeleated=false;
	if ((head->value)==nodeValue){	//second case: found at the beginning
		head=head->next;
		temp=temp->next;
		flagDeleated=true;
	}
	else{	//third case: anywhere else
		while((flagDeleated == false)&&(temp2!=NULL)){
			if ((temp2->value)==nodeValue){
				temp->next = temp2->next;
				temp=temp2;
				flagDeleated=true;
			}
			else{
				temp=temp2;
				temp2=temp2->next;
			}
		}
	}

	if(flagDeleated==false){
			cout<<"ERROR";
			cout<< nodeValue;
			cout<< "-1" <<endl;
			return;
		}

	while(temp!=NULL){
		temp->posc--;
		temp=temp->next;
	}
	len--;

}

void SinglyLinkedList::printList() {
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->value;		//print the value
        cout << " [";
        cout << (temp->posc) ;	//print the position
        cout << "] -> " ;
        temp=temp->next;
    }
    cout<<endl;
}

string SinglyLinkedList::getDataX(int x){
	if (head==NULL){
			cout << "ERROR" <<endl;
			//return false;
	}
	if (x >= len or x<0){
		cout << "Error"<< endl;
		return false;
	}else{
		Node *temp=head;
		string nodeValue;
		while(temp!=NULL){
			if (temp->posc == x){
				nodeValue = temp->value;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		cout << nodeValue <<endl;  //print the value
		return nodeValue;
	}
}


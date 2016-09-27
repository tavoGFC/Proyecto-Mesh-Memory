/*
 * xRefSingleList.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: ricardo
 */

#include "xRefSingleList.h"


/**
 * Constructor
 */
xRefSingleList::xRefSingleList() {
	len=0;
	head=NULL;

}

/**
 * Destroyer
 */
xRefSingleList::~xRefSingleList() {
}


/**
 * Insert a new node in list with as a
 * newValue object (xReference).
 *
 * @params newValue xReference
 */
void xRefSingleList::insertData(xReference newValue) {	//adds a new node with the given value
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

/**
 * Deletes the first node as a nodeValue object
 * (xReference) in the list.
 *
 * @params nodeValue xReference
 */
void xRefSingleList::deleteData(xReference nodeValue){	//deletes the first node that is found with the given value
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
			cout<< nodeValue.getID();
			cout<< "-1" <<endl;
			return;
		}

	while(temp!=NULL){
		temp->posc--;
		temp=temp->next;
	}
	len--;

}

/**
 * Print the list.
 */
void xRefSingleList::printList() {
    Node *temp = head;
    while(temp!=NULL){
    	ostringstream ss;
    	ss << temp->value.getSize();
    	string size= ss.str();

    	string info=(" id: " + temp->value.getID() + "  size: " + size +"  type: " + temp->value.getType());
        //cout<<temp->value;		//print the value
        cout << " [";
        cout << ("poscicion: ") ;	//print the position
        cout << (temp->posc) ;	//print the position
        cout <<info;
        cout << "] -> " <<endl ;

        temp=temp->next;
    }
    cout<<endl;
}

/**
 * Return an xReference object from the list,
 * from the position insert in the parameter.
 *
 * @params x int
 */
xReference xRefSingleList::getDataX(int x){
	Node *temp=head;
	xReference nodeValue;
	while(temp!=NULL){
		if (temp->posc == x){
			nodeValue = temp->value;
			break;
		}
		else{
			temp=temp->next;
		}
	}
	return nodeValue;
}

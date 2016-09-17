
//============================================================================
// Name        : consola.cpp
// Author      : randy, ricardo y gustavo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include "API/MeshMemAPI.h"
#include "API/SocketCtoJ.h"
#include "API/xReference.h"

using namespace std;

int main() {
	cout << "Welcome to the Mesh Memory, brave warrior!" << endl; // prints !!!Hello World!!!
	cout << "To access the API please connect to a MeshMemory Manager.";
	cout << "Enter a valid IP address and the Port Number of the device."<<endl;

	int portN;
	string hostIP;

	SocketCtoJ socket;
	while(true){
		cout << "Entry Host: "<<endl;
		cin >> hostIP;
		cout << "Entry Port: "<<endl;
		cin >> portN;
		//int port = portN;


		if (socket.conectar(hostIP, portN) != -1){
			cout <<"Successfully connected"<<endl;
			break;
		}
		cout<<"ERROR: please try connecting again!!"<<endl;
	}


	cout << "==============================================================================="<<endl;

	cout << "These are the functions to use in this menu." << endl;

	cout << "________________________________________________________________________________"<<endl;

	cout << "To use these functions type the number of the function you want to use." << endl;
	cout << "(1). xMalloc(int size, xType type)" << endl;
	cout << "(2). xMalloc(int size, xType type, void* value)" << endl;
	cout << "(3). xAssign(xReference reference, void* value)" << endl;
	cout << "(4). xFree(xReference toFree)" << endl;
	cout << "(0). To EXIT" << endl;

	cout << "==============================================================================="<<endl;


	string entry;
	xReference ref1;

	while(true){
		cout << "Type your choice: " << endl;
		cin >> entry;

		if(entry == "0" ){
			cout << "Exit." << endl;
			break;
		}
		else if(entry == "1"){
			cout << "You have enter option (1): xMalloc(int size, xType type, void* value)." << endl;
			cout << "Please enter the parameters size (int) and type (xType)." << endl;
			cin>>entry;
			ref1= xReference(entry);
			socket.sendMessage(ref1.getData());


		}
		else if(entry == "2"){

		}
		else if(entry == "3" ){
			cout << "You have enter option (3): xAssign(xReference reference, void* value) " << endl;
			cout << "Please enter the parameters reference (int) and value (void*)." << endl;

			void* value;

			cout << "Entry value: "<<endl;
			cin >> value;

			cout << value <<endl;

			//llamado de la funcion xAssign()
		}
		else if(entry == "4" ){

		}
		else{
			cout << "Your entry does not match our functions.";
		}
	}
	return 0;

}

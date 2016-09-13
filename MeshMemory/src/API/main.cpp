//============================================================================
// Name        : MeshMemClient.cpp
// Author      : Randy
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "xReference.h"
#include "MeshMemAPI.h"
using namespace std;


int main() {
	cout << "Welcome to the Mesh Memory Client." << endl;
	cout << "To connect to the Mesh Memory Manager, please enter the IP address and the Port Number of the Device." << endl;
	char ip;
	int portNum;
	cout << "Entry: ";
	cin >> ip;
	cout << "Entry: ";
	cin >> portNum;
	cout << "The IP is: " << ip;
	cout << "\nThe Port Number is: " << portNum;
	cout << "Right we are trying to connect..." << endl;

	// initialize(ip, portNum);
/*
	if(connection successful){
		cout << "Connection successful.";
		cout<< "These is the option you enter. Choose one."
		.
		.
		.

	}else{
		cout << "Connection failure.";
		cout<< "Please try again";
	}



*/
	return 0;

}

//============================================================================
// Name        : consola.cpp
// Author      : r
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void imprimir(int port, string host);

void imprimir(int port, string host){
	cout << port << host << endl;
}

int numeros(string a, int b){
	if ((a=="a") & (b==2)){
		return 1;
	}else{
		return -1;
	}
}

int main() {
	cout << "Welcome to the Mesh Memory, brave warrior!" << endl; // prints !!!Hello World!!!
	cout << "To access the API please connect to a MeshMemory Manager.";
	cout << "Enter a valid IP address and the Port Number of the device."<<endl;

	int port;
	string host;

	/*
	cout << "Entry Host: "<<endl;
	cin >> host;
	cout << "Entry Port: "<<endl;
	cin >> port;
	//init */

	while(true){
		cout << "Entry Host: "<<endl;
		cin >> host;
		cout << "Entry Port: "<<endl;
		cin >> port;
		if (numeros(host, port) != -1){
			break;
		}
		cout<<"ERROR: please try again!!"<<endl;
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

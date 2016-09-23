//============================================================================
// Name        : MeshMemClient.cpp
// Author      : randy, ricardo y gustavo
// Version     : 1.0
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include "API/MeshMemAPI.h"
//#include "API/SocketCtoJ.h"
#include "API/xReference.h"
#include "Structures/xRefSingleList.h"
#include "API/Encripter.h"


using namespace std;

int main() {
	MeshMemAPI myAPI;
	SocketCtoJ mySocket=myAPI.getSocket();
	Encripter crypto;

	int portN;
	string hostIP;
	xRefSingleList refList;

	cout << "Welcome to the Mesh Memory!" << endl;
	cout << "To access the API please connect to a MeshMemory Manager.";
	cout << "Enter a valid IP address and the Port Number of the device to make a connection."<<endl;

	while(true){
		cout << "Entry Host: "<<endl;
		cin >> hostIP;
		cout << "Entry Port: "<<endl;
		cin >> portN;
		if (mySocket.startConnection(hostIP, portN) != -1){
			cout <<"Successfully connected!"<<endl;
			break;
		}
		cout<<"ERROR: please try connecting again!!"<<endl;
	}


	string menu =  "===============================================================================\n"
				   "These are the functions to use in this menu.\n"
				   "________________________________________________________________________________\n"

				   "To use these functions type the number of the function you want to use.\n"
			       "(0). To EXIT.\n"
				   "(1). xMalloc(int size, xType type)\n"
				   "(2). xMalloc(int size, xType type, void* value)\n"
				   "(3). xAssign(xReference reference, void* value)\n"
	               "(4). xFree(xReference toFree)\n"
	               "===============================================================================\n";
	cout << menu << endl;

	string entryOption;

	int entrySize;
	string entryType;

	while(true){
		cout << "Type your choice: " << endl;
		cin >> entryOption;

		if(entryOption == "0" ){
			cout << "Exit." << endl;
			break;
		}
		//----------------------------------------xMALLOC------------------------------------
		else if(entryOption == "1"){
			cout << "You have enter option (1): xMalloc(int size, string type)." << endl;
			cout << "Please enter the parameters size (int) and type (xType)." << endl;

			cout << "Entry Size: "<<endl;
			cin>>entrySize;
			cout << "Entry type: "<<endl;
			cin>>entryType;

			if (myAPI.verifyType(entryType)){

			xReference ref1 = myAPI.xMalloc(entrySize, entryType);

			string msj= entryType + "/" + ref1.NumberToString(entrySize);

			mySocket.sendMsj("API" + crypto.encode(msj));

			//mySocket.sendMsj("API" + entryType );
			refList.insertData(ref1);
			refList.printList();
			}
			else{
				cout <<"ERROR, type is not in our parameters."<<endl;
			}

//			int aux;
//			int longitud;
//			socket.receiveMsj((char*) &aux, sizeof(int));
//			longitud = ntohl(aux);
//			socket.receiveMsj(socket.buffer,longitud);
//
//			printf("Message of the MeshMem Manager: %s\n", socket.buffer);

			cout << "Try another number if want to make another action." << endl;

		}
		//----------------------------------------xMALLOC------------------------------------
		else if(entryOption == "2"){
			cout << "You have enter option (2): xMalloc(int size, xType type, void* value)." << endl;
			cout << "Please enter the parameters size (int), type (xType) and value (void*)." << endl;
			cout << "Entry: "<<endl;

		}
		//----------------------------------------xASSIGN------------------------------------
		else if(entryOption == "3" ){
			cout << "You have enter option (3): xAssign(xReference reference, void* value) " << endl;
			cout << "Please enter the parameters reference (int) and value (void*)." << endl;

			void* value;

			cout << "Entry value: "<<endl;
			cin >> value;

			cout << value <<endl;
		}
		//----------------------------------------xFREE------------------------------------
		else if(entryOption == "4" ){

		}

		//----------------------------------------ERROR------------------------------------
		else{
			cout << "Your entry does not match our functions.";
		}
	}
	return 0;

}

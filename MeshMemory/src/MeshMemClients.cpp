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
	int entryInt;
	string entryString;

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
			cin>>entryInt;
			cout << "Entry type: "<<endl;
			cin>>entryString;

			if (myAPI.verifyType(entryString)){

				xReference ref1 = myAPI.xMalloc(entryInt, entryString);

				string idenRef1 = ref1.getID(); //--------------------

				string msj= entryString + "/" + ref1.NumberToString(entryInt) +"/" +  idenRef1;

				mySocket.sendMsj("API" + crypto.encode(msj)); //API+type+size+ID

				refList.insertData(ref1);
				refList.printList();
			}
			else{
				cout <<"ERROR, type is not in our parameters."<<endl;
			}

			cout << "Try another number if want to make another action." << endl;

		}
		//----------------------------------------xMALLOC  (2)------------------------------------
		else if(entryOption == "2"){
			cout << "You have enter option (2): xMalloc(int size, String type, String value)." << endl;
			cout << "Please enter the parameters size (int), type (string) and value (any primitive value)." << endl;
			cout << "Entry: "<<endl;

			cout << "Entry Size: "<<endl;
			cin>>entryInt;
			cout << "Entry type: "<<endl;
			cin>>entryString;

			string Value;
			cout << "Entry value: "<<endl;
			cin>>Value;

			if (myAPI.verifyType(entryString)){

				xReference ref1 = myAPI.xMalloc(entryInt, entryString);

				string idenRef1 = ref1.getID(); //--------------------

				string msj= entryString + "/" + ref1.NumberToString(entryInt);

				mySocket.sendMsj("API" + crypto.encode(msj)); //API+type+size+ID

				refList.insertData(ref1);
				refList.printList();
			}
			else{
				cout <<"ERROR, type is not in our parameters."<<endl;
			}

			cout << "Try another number if want to make another action." << endl;
		}
		//----------------------------------------xASSIGN------------------------------------
		else if(entryOption == "3" ){
			cout << "You have enter option (3): xAssign(xReference reference, void* value) " << endl;
			cout << "These are the xRef available:" << endl;
			refList.printList();
			cout << "Please type the number of the xReference object that makes references to the memory block." << endl;

			xReference ref1;
			cout << "Entry xReference Object: "<<endl;

			cin >>entryInt;
			ref1 = refList.getDataX(entryInt);

			string iden = ref1.getID();

			cout << "Entry value: "<<endl;
			cin>>entryString;

			string msj= entryString + "/" + iden;

			mySocket.sendMsj("API" + crypto.encode(iden)); //API+value+ID

			cout << "Try another number if want to make another action." << endl;

		}
		//----------------------------------------xFREE------------------------------------
		else if(entryOption == "4" ){
			cout << "You have enter option (4): xFree(xReference reference) " << endl;
			cout << "These are the xRef available:" << endl;
			refList.printList();
			cout << "Please type the number of the xReference object that refers to the memory block that you want to free." << endl;

			xReference ref1;
			cout << "Entry xReference Object: "<<endl;

			cin >> entryInt;

			string iden = ref1.getID();

			string msj= iden;

			mySocket.sendMsj("API" + crypto.encode(iden)); //API+ID

			cout << "Try another number if want to make another action." << endl;

		}

		//----------------------------------------ERROR------------------------------------
		else{
			cout << "Your entry does not match our functions.";
		}
	}
	return 0;

}

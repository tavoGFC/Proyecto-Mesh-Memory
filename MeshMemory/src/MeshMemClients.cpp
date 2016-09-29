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
	MeshMemAPI myAPI; /*Instantiating an API */
	SocketCtoJ mySocket=myAPI.getSocket(); /* Socket from API*/
	Encripter crypto;/*Instantiating an Encripter for encoding in Base_64*/
	int portN; /*Number (int) of the port of the Java-Server*/
	string hostIP; /*Number (string) of the Java-Server*/
	xRefSingleList refList; /*Instantiating an xRefSingleList (Double Linked List)*/

	/*Welcome (string)*/
	string welcome =   "Welcome to the Mesh Memory!"
					   "To access the API please connect to a MeshMemory Manager."
					   "Enter a valid IP address and the Port Number of the device to make a connection.";
	/*menu (string)*/
	string menu =  	   "===============================================================================\n"
					   "These are the functions to use in this menu.\n"
					   "________________________________________________________________________________\n"

					   "To use these functions type the number of the function you want to use.\n"
				       "(0). To EXIT.\n"
					   "(1). xMalloc(int size, xType type)\n"
					   "(2). xMalloc(int size, xType type, void* value)\n"
					   "(3). xAssign(xReference reference, void* value)\n"
		               "(4). xFree(xReference toFree)\n"
		               "===============================================================================\n";

	cout << welcome << endl; //printing welcome

	/*Loop for connecting this C-Client with the Java-Server*/
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

	cout << menu << endl; //printing the menu

	string entryOption; //entry (string) for choosing an action
	int entryInt; //entry (int) for int  parameters in the action
	string entryString; //entry (string) for  parameters in the action
	string entryValue; //entry (string) for the parameters in the action

	/*Loop for the User to interact with the MeshMemAPI*/
	while(true){
		cout << "Type your choice: " << endl;
		cin >> entryOption;

		if(entryOption == "0" ){
			cout << "Exit." << endl;
			break;
		}
		/*----------------------------------------xMALLOC------------------------------------*/
		else if(entryOption == "1"){
			cout << "You have enter option (1): xMalloc(int size, string type)." << endl;
			cout << "Please enter the parameters size (int) and type (as a string)." << endl;

			cout << "Entry Size: "<<endl;
			cin>>entryInt;
			cout << "Entry type: "<<endl;
			cin>>entryString;

			if (myAPI.verifyType(entryString)){

				/*xMalloc returns an ref1 (xReference)*/
				xReference ref1 = myAPI.xMalloc(entryInt, entryString);

				/*Setting a unique ID for this ref1*/
				string idenRef1 = ref1.getID();

				/*Concatenate all data in msj (string): "API/xMalloc1/ identifies which action is being sent*/
				string msj= "xMalloc1/"+ entryString + "/" + ref1.NumberToString(entryInt) +"/" +  idenRef1;

				/*Send the msj (string) to the Java-Server Encripted in Base_64*/
				mySocket.sendMsj("API/" + crypto.encode(msj)  + "\n");

				/*Insert the ref1 (xReference) to a reList (xRefSingleList)*/
				refList.insertData(ref1);

				/*Prints the refList (xRefSingleList) on screen to show all xReferences object created*/
				refList.printList();
			}
			else{
				cout <<"ERROR, type is not in our parameters."<<endl;
			}

			cout << "Try another number if want to make another action." << endl;

		}
		/*----------------------------------------xMALLOC  (2)--------------------------------*/
		else if(entryOption == "2"){
			cout << "You have enter option (2): xMalloc(int size, String type, String value)." << endl;
			cout << "Please enter the parameters size (int), type (string) and value (any primitive value)." << endl;

			cout << "Entry Size: "<<endl;
			cin>>entryInt;
			cout << "Entry type: "<<endl;
			cin>>entryString;

			cout << "Entry value: "<<endl;
			cin>> entryValue;

			if (myAPI.verifyType(entryString)){

				/*xMalloc returns an ref1 (xReference)*/
				xReference ref1 = myAPI.xMalloc(entryInt, entryString, entryValue);

				/*Setting a unique ID for this ref1*/
				string idenRef1 = ref1.getID();

				/*Concatenate all data in msj (string): "API/xMalloc2/ identifies which action is being sent*/
				string msj= "xMalloc2/" + entryString + "/" + ref1.NumberToString(entryInt) + "/" + entryValue +"/" +  idenRef1;

				/*Send the msj (string) to the Java-Server Encripted in Base_64*/
				mySocket.sendMsj("API/" + crypto.encode(msj) + "\n"); //API+type+size+ID

				/*Insert the ref1 (xReference) to a reList (xRefSingleList)*/
				refList.insertData(ref1);

				/*Prints the refList (xRefSingleList) on screen to show all xReferences object created*/
				refList.printList();
			}
			else{
				cout <<"ERROR, type is not in our parameters."<<endl;
			}

			cout << "Try another number if want to make another action." << endl;
		}
		/*----------------------------------------xASSIGN------------------------------------*/
		else if(entryOption == "3" ){
			cout << "You have enter option (3): xAssign(xReference reference, string value) " << endl;
			cout << "Please type the number of the xReference object that makes references to the memory block." << endl;

			cout << "These are the xRef available:" << endl;
			refList.printList();

			/*Instantiate an xReference: xref3 */
			xReference ref3;

			cout << "Entry xReference Object: "<<endl;
			cin >>entryInt;

			/*Make xref3 equal as the one on the refList position */
			ref3 = refList.getDataX(entryInt);

			/*Setting a unique ID for this ref3 (xReference) */
			string idenRef3 = ref3.getID();

			/*Entry the value of the data to save*/
			cout << "Entry value: "<<endl;
			cin>>entryString;


			if (myAPI.verifyType(entryString)){

				/*Invoke the xAssing Method*/
				myAPI.xAssign(ref3,entryString);

				/*Concatenate all data in msj (string): "API/xAssign/ identifies which action is being sent*/
				string msj= "xAssign/" + entryString + "/" + idenRef3;

				/*Send the msj (string) to the Java-Server Encripted in Base_64*/
				mySocket.sendMsj("API/" + crypto.encode(msj) + "\n");

			}


			cout << "Try another number if want to make another action." << endl;

		}
		/*----------------------------------------xFREE------------------------------------*/
		else if(entryOption == "4" ){
			cout << "You have enter option (4): xFree(xReference reference) " << endl;
			cout << "Please type the number of the xReference object that refers to the memory block that you want to free." << endl;

			cout << "These are the xRef available:" << endl;
			refList.printList();

			/*Instantiate an xReference: xref4 */
			xReference ref4;

			cout << "Entry xReference Object: "<<endl;
			cin >> entryInt;

			/*Make xref4 equal as the one on the refList position */
			ref4 = refList.getDataX(entryInt);

			/*Setting a unique ID for this ref4 (xReference) */
			string iden = ref4.getID();

			/*Concatenate all data in msj (string): "API/xFree/ identifies which action is being sent*/
			string msj= "xFree/" + iden;

			/*Send the msj (string) to the Java-Server Encripted in Base_64*/
			mySocket.sendMsj("API/" + crypto.encode(iden) + "\n");

			cout << "Try another number if want to make another action." << endl;

		}

		/*----------------------------------------ERROR------------------------------------*/
		else{
			cout << "Your entry does not match our functions.";
		}
	}
	return 0;

}

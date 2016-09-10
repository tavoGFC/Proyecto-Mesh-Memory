//============================================================================
// Name        : Labs.cpp
// Author      : Randy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Structures/SinglyLinkedList.h"
#include "Structures/DoublyLinkedList.h"
#include "API/Token.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
//SOBRECARGA DE OPERDORES//
class Pareja{
public:
    double a, b;

    // constructor parametrizado
    Pareja(const double a,const double b){
        this->a = a;
        this->b = b;
    }
};

// Sobrecarga del operador +
Pareja& operator +(const Pareja &p1,const Pareja &p2){
  return *(new Pareja(p1.a + p2.a, p1.b + p2.b) );
}

int main() {

    //Pareja A(50, 75 );
    //Pareja B(150, 175 );
    //Pareja C = A + B;

    //cout << "A = " << A.a << ',' << A.b << "\n";
    //cout << "B = " << B.a << ',' << B.b << "\n";
    //cout << "C = " << C.a << ',' << C.b << "\n";

	cout << "Hola Mercurio!" << endl;

//-----------------------------------------------------------------------------------------------------------------------
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	 //const string s = "Hello World!" ;
	 //string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
	 //string decoded = base64_decode(encoded);
	 //cout << "encoded: " << encoded << endl;
	 //cout << "decoded: " << decoded << endl;
//-----------------------------------------------------------------------------------------------------------------------
	 //cout << sizeof(s) << endl;
//-----------------------------------------------------------------------------------------------------------------------
	 //SinglyLinkedList listOne;
	 //listOne.insertData("Pilot");
	 //listOne.insertData("Tolip");
	 //listOne.insertData("Lotpi");
	 //listOne.insertData("Polit");
	 //listOne.insertData("Lipot");
	 //listOne.insertData("Tipol");
	 //listOne.printList();
	 //listOne.deleteData("Tolip");
	 //listOne.printList();
	 //DoublyLinkedList listTwo;
	 //listTwo.insertData("Pilot");
	 //listTwo.insertData("Tolip");
	 //listTwo.insertData("Lotpi");
	 //listTwo.insertData("Polit");
	 //listTwo.insertData("Lipot");
	 //listTwo.insertData("Tipol");
	 //listTwo.printListLeftRight();
	 //listTwo.printListRightLeft();
	 //listTwo.deleteData("Tolip");
	 //listTwo.printListLeftRight();
	 //listTwo.printListRightLeft();
	return 0;
}

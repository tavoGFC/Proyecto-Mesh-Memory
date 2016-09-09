//============================================================================
// Name        : HelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "FolderMML/Token.h"

using namespace std;


template <typename T>
  string NumberToString ( T Number ){
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

char generateID(){
	//char ID[];

}


int main() {
	cout << "Hola Saturno!" << endl;

	clock_t start = clock();
	cout << "time: "<< start  << endl;
	int timeInt = start;
	cout << "timeInt: "<< timeInt  << endl;

	//long a = 9098;
	string s = NumberToString(timeInt);
	cout<< "s: " << s << endl;


	Token token1;
	token1.setString(s);
	string stringEncoded;
	stringEncoded = token1.base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
	string stringDecoded;
	stringDecoded = token1.base64_decode(stringEncoded);



	//string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
	//string decoded = base64_decode(encoded);
	cout << "encoded: " << stringEncoded << endl;
	cout << "decoded: " << stringDecoded << endl;
	return 0;
}

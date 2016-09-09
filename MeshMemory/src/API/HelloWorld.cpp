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

string generateID_Aux(unsigned char const* bytes_to_encode, unsigned int in_len) {
  string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--){
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3){
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i){
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '-';
  }
  return ret;
}

string generateID() {
	string id, ID;
	for(int j = 0; j < 5; j++){
		clock_t start = clock();
		int timeInt = start;
		string s = NumberToString(timeInt);
		id = generateID_Aux(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
		ID +=id;
	}
	return ID;
}


int main() {

	cout << "Hola Saturno!" << endl;
	string idid = generateID();
	cout << "Hola Jupiter!" << endl;
	cout << "idid: " << idid << endl;

/*
	clock_t start = clock();
	cout << "time: "<< start  << endl;
	int timeInt = start;
	cout << "timeInt: "<< timeInt  << endl;
	string s = NumberToString(timeInt);
	cout<< "s: " << s << endl;
	Token token1;
	token1.setString(s);
	string stringEncoded;
	stringEncoded = token1.base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
	string stringDecoded;
	stringDecoded = token1.base64_decode(stringEncoded);
	cout << "encoded: " << stringEncoded << endl;
	cout << "decoded: " << stringDecoded << endl;
	return 0;
*/
}

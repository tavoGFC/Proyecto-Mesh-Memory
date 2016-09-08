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

using namespace std;
//BASE64 Funciones//
string base64_encode(unsigned char const* , unsigned int len);
string base64_decode(string const& s);


static const string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}



string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}


string base64_decode(string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}
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

	cout << "Hello World!" << endl;
	enum paises {entero=4, peru, india, islandia, oman};
	string pais;
	pais = oman;
	int sizePais = sizeof(pais);
	cout << sizePais << endl;
	if (sizePais == entero){
		cout << "wlololcao" << endl;
		return true;
	}else{
		return false;
	}

	cout << pais << endl;


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

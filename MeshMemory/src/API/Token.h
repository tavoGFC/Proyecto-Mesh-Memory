/*
 * Token.h
 *
 *  Created on: Sep 8, 2016
 *      Author: randy
 */

#ifndef API_TOKEN_H_
#define API_TOKEN_H_
#include <iostream>
#include <stdio.h>

using namespace std;

class Token {
	public:
		Token();
		virtual ~Token();
		string base64_encode(unsigned char const* , unsigned int len);
		string base64_decode(string const& s);
		static inline bool is_base64(unsigned char c) {
		  return (isalnum(c) || (c == '+') || (c == '/'));
		}

		string toEncode;

		static const string base64_chars =
		             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		             "abcdefghijklmnopqrstuvwxyz"
		             "0123456789+/";

};

#endif /* API_TOKEN_H_ */

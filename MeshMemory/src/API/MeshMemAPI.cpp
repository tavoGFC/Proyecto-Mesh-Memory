/*
 * MeshMemAPI.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: randy, ricardo
 */

#include "MeshMemAPI.h"
#include <iostream>
#include <string>
#include "xReference.h"

/**
 * Constructor for a MeshMem API object.
 */
MeshMemAPI::MeshMemAPI(){

}

/**
 * Destroyer for a MeshMem API object.
 */
MeshMemAPI::~MeshMemAPI(){

}

/**
 * Returns the socket used in the connection.
 * @return socket
 */
SocketCtoJ MeshMemAPI::getSocket(){
	return mySocket;
}

/**
 *Creates an xReference obj and set its attributes of size and type to the
 *ones enter in the parameters.
 *to
 *
 *@returns ref
 */
xReference MeshMemAPI::xMalloc(int size, string type){
	xReference ref=xReference(size, type);
	return ref;

}

/**
 *Creates an xReference obj and set its attributes of size and type and data
 *to the ones enter in the parameters.
 *
 *@returns ref
 */
xReference MeshMemAPI::xMalloc(int size, string type, string value){
	xReference ref=xReference(size, type);
	//ref.setData(value);
	return ref;


}
/**
 *Set the data of the reference to
 */
void MeshMemAPI::xAssign(xReference reference, string value){
	//reference.setData(value);
}

/**
 *Set the value of data to an NULL into the toFree obj.
 */
void MeshMemAPI::xFree(xReference toFree){
	//toFree.freeData();
	cout<< "Free data.";
}

/*---------------------*/
/*Verifications Methods*/
/*---------------------*/

/**
 * Verifies if the type is type: char, string, int, double, float.
 *
 * @params string type
 * @return bool
 */
bool MeshMemAPI::verifyType(string type){
	if (type=="string"){
		return true;
	}
	else if (type=="int"){
			return true;
		}
	else if (type=="float"){
			return true;
		}
	else if (type=="double"){
			return true;
		}
	else if (type=="char"){
			return true;
		}
	else{
		return false;
	}

}

/**
 * Verifies if the entry is a str (string).
 *
 * @params string str
 * @return bool
 */
bool MeshMemAPI::verifyInt(string str){
	if (str==""){ //verificar string vacio
		return false;
	}
	if (str[0]=='-'){ //verificar negativo
		if (str.length()<2){ //verifica que no solo sea el caracter de "-"
			return false;
		}
		str=str.substr(1);  //corta el negativo y se trabaja como positivo
	}

	bool resp=true;
	unsigned int i;
	for(i=0; i < str.length();i++){
		if ( !isNumber( str[i] ) ){
			resp=false;
			break;
		}
	}
	return resp;
}


/**
 * Verifies if the entry is a str (string).
 *
 * @params string str
 * @return bool
 */
bool MeshMemAPI::verifyFloat(string str){
	if (str==""){  //verificar string vacio
			return false;
		}
	if(str[0]=='.'){ //verificar punto al principio
		return false;
	}
	if (str[0]=='-'){ //verificar negativo
		if (str.length()<2){  //verifica que no solo sea el caracter de "-"
			return false;
		}
		str=str.substr(1);  //corta el negativo y se trabaja como positivo
	}

	bool resp=true;
	int point=0;
	unsigned int i;
	for(i=0; i < str.length();i++){
		if(str[i]=='.'){	//verifica si es punto
			point++;
			if (point>=2){	//solo puede haber 1 punto
				resp=false;
				break;
			}
			else if(i==str.length()-1){	//si hay punto, no puede ser al final
				resp=false;
				break;
			}
		}
		else if ( !isNumber(str[i]) ){	//verificar si son numeros
			resp=false;
			break;
		}
	}
	return resp;
}

/**
 * Verifies if the entry is a str (string).
 *
 * @params string str
 * @return bool
 */
bool MeshMemAPI::verifyDouble(string str){
	if (str==""){  //verificar string vacio
		return false;
	}
	if(str[0]=='.'){ //verificar punto al principio
		return false;
	}
	if (str[0]=='-'){ //verificar negativo
		if (str.length()<2){  //verifica que no solo sea el caracter de "-"
			return false;
		}
		str=str.substr(1);  //corta el negativo y se trabaja como positivo
	}

	bool resp=true;
	int point=0;
	unsigned int i;
	for(i=0; i < str.length();i++){
		if(str[i]=='.'){	//verifica si es punto
			point++;
			if (point>=2){	//solo puede haber 1 punto
				resp=false;
				break;
			}
			else if(i==str.length()-1){	//si hay punto, no puede ser al final
				resp=false;
				break;
			}
		}
		else if ( !isNumber(str[i]) ){	//verificar si son numeros
			resp=false;
			break;
		}
	}
	return resp;
}


/**
 * Verifies if the entry is a str (string).
 *
 * @params string str
 * @return bool
 */

bool MeshMemAPI::verifyChar(string str){
	if (str.compare(" ")==0){	//que no sea un espacio
		return false;
	}
	else if(str.length()!=1){	//que solo tenga un caracter
		return false;
	}
	else{
		return true;
	}
}

/**
 * Verifies if the entry c (char) have any digit number from 1 to 9.
 *
 * @params char c
 * @return bool
 */
bool MeshMemAPI::isNumber(char c){
	if (c=='0'){
		return true;
	}
	else if (c=='1'){
			return true;
		}
	else if (c=='2'){
				return true;
			}
	else if (c=='3'){
				return true;
			}
	else if (c=='4'){
				return true;
			}
	else if (c=='5'){
				return true;
			}
	else if (c=='6'){
				return true;
			}
	else if (c=='7'){
				return true;
			}
	else if (c=='8'){
				return true;
			}
	else if (c=='9'){
				return true;
			}
	else{
		return false;
	}
}


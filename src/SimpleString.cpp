/*
 * SimpleString.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: erolh
 */

#include "SimpleString.h"

SimpleString::SimpleString(int maxSize) {
	if (maxSize > 0) {
		this->maxSize = maxSize;
		this->currentSize = 0;
	}
	str = new char[maxSize];
	this->str[0] = 0;
}

SimpleString::SimpleString(const char* otherStr, int maxSize) :
		SimpleString(maxSize) {
	if (strlen(otherStr) <= (unsigned) maxSize) {
		strcpy(this->str, otherStr);
	}
}

SimpleString::~SimpleString() {
	delete[] str;
}

SimpleString& SimpleString::operator =(const SimpleString& other) {
	if (other.currentSize <= this->maxSize)
		strcpy(this->str, other.str);
	this->currentSize = other.currentSize;
	return *this;
}

SimpleString::SimpleString(const SimpleString& other)
	: SimpleString(other.str,other.maxSize){
}

SimpleString::SimpleString(const SimpleString& other, int maxSize)
 : SimpleString(other.str,maxSize){
}

bool SimpleString::operator<(const SimpleString& other) const {
	int isSmaller = strcmp(this->str, other.str);
	if (isSmaller < 0)
		return true;
	return false;
}

SimpleString::SimpleString() : SimpleString(30){
}

ostream& operator<<(ostream& os,const SimpleString& toPrint){
	os<<toPrint.str;
	return os;
}

/*
 * SimpleString.h
 *
 *  Created on: Jan 13, 2016
 *      Author: erolh
 */

#ifndef SimpleSTRING_H_
#define SimpleSTRING_H_

#include <iostream>
#include <cstring>
using namespace std;

class SimpleString {
	char* str;
	int maxSize;
	int currentSize;

public:
	SimpleString();
	SimpleString(int maxSize);
	SimpleString(const SimpleString& other);
	SimpleString(const SimpleString& other, int maxSize);
	SimpleString(const char* otherStr, int maxSize = 30);
	~SimpleString();

	SimpleString& operator=(const SimpleString& other);

	bool operator<(const SimpleString& other) const;

	int getCurrentSize() const {
		return currentSize;
	}

	friend ostream& operator<<(ostream&, const SimpleString&);
};

#endif /* SimpleSTRING_H_ */

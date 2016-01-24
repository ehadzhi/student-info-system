/*
 * Student.h
 *
 *  Created on: Jan 6, 2016
 *      Author: erolh
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

#include "SimpleString.h"

using namespace std;

class Student {
	static const int NAME_MAX_LENGTH = 30;

	SimpleString* name;
	double avgScore;
	int cellPhoneNumber;

public:
	Student() {
	}
	Student(SimpleString name, double avgScore, int phoneNumber);

	friend ostream& operator<<(ostream& os, const Student& toPrint);

	double getAvgScore() const {
		return avgScore;
	}

	bool setAvgScore(double avgScore) {
		if (avgScore >= 0 && avgScore <= 6) {
			this->avgScore = avgScore;
			return true;
		}
		return false;
	}

	int getCellPhoneNumber() const {
		return cellPhoneNumber;
	}

	bool setCellPhoneNumber(int cellPhoneNumber) {
		if (cellPhoneNumber >= 0) {
			this->cellPhoneNumber = cellPhoneNumber;
			return true;
		}
		return false;
	}

	const SimpleString getName() const {
		return *name;
	}
};
#endif /* STUDENT_H_ */

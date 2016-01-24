/*
 * Student.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: erolh
 */

#include "Student.h"

#include <iomanip>

Student::Student(SimpleString name, double avgScore, int phoneNumber) :
		avgScore(avgScore), cellPhoneNumber(phoneNumber) {
	if (name.getCurrentSize() <= NAME_MAX_LENGTH) {
		this->name = new SimpleString(name, NAME_MAX_LENGTH);
	}
	if (avgScore >= 0) {
		this->avgScore = avgScore;
	}
	if (phoneNumber >= 0) {
		this->cellPhoneNumber = phoneNumber;
	}
}

ostream& operator<<(ostream& os, const Student& toPrint) {
	os << left << setw(30) << toPrint.getName() << " " << setw(3)
			<< toPrint.getAvgScore() << " " << toPrint.getCellPhoneNumber()
			<< endl;
	return os;
}

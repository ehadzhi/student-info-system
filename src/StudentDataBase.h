/*
 * StudentDataBase.h
 *
 *  Created on: Jan 17, 2016
 *      Author: erolh
 */

#ifndef STUDENTDATABASE_H_
#define STUDENTDATABASE_H_

#include <string>

#include "DataBase.h"
#include "SimpleString.h"
#include "Student.h"

using namespace std;

class StudentDataBase: public DataBase<SimpleString, Student> {
	Student parceLine(string line);
public:

	bool addStudent(const Student& toAdd) {
		return addRecord(toAdd.getName(), toAdd);
	}

	double getAverageScore(const SimpleString& studentName);
	bool setAverageScore(double newScore, const SimpleString& studentName);

	int getPhoneNumber(const SimpleString& studentName);
	bool setPhoneNumber(int newNumber, const SimpleString& studentName);

	void loadFromFile(const char* fileName);
};

#endif /* STUDENTDATABASE_H_ */

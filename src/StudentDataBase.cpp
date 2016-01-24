/*
 * StudentDataBase.cpp
 *
 *  Created on: Jan 17, 2016
 *      Author: erolh
 */

#include "StudentDataBase.h"

#include <cstdlib>
#include <fstream>

using namespace std;

void trimName(string& candidateName);
bool checkName(string& candidateName);

bool checkAndTrimName(string& candidateName) {
	if (checkName(candidateName)) {
		trimName(candidateName);
		return true;
	}
	return false;
}

int StudentDataBase::getPhoneNumber(const SimpleString& studentName) {
	Student* toGetFrom = searchRecord(studentName);
	if (toGetFrom != nullptr)
		return toGetFrom->getCellPhoneNumber();
	return -1;
}

bool StudentDataBase::setPhoneNumber(int newNumber,
		const SimpleString& studentName) {
	Student* toGetFrom = searchRecord(studentName);
	if (toGetFrom != nullptr)
		return toGetFrom->setCellPhoneNumber(newNumber);
	return false;
}

void StudentDataBase::loadFromFile(const char* fileName) {
	fstream toReadFrom(fileName);
	string line;
	Student currentStudent;
	if (toReadFrom.is_open())
		while (toReadFrom.good() && !toReadFrom.eof()) {
			getline(toReadFrom, line);
			if (line.size() > 5) {
				currentStudent = parceLine(line);
				this->addRecord(currentStudent.getName(), currentStudent);
			}
		}
	toReadFrom.close();
}

Student StudentDataBase::parceLine(string line) {
	string name = line.substr(0, 30);
	string grade = line.substr(31, 3);
	string number = line.substr(35, 15);
	double gr = atof(grade.c_str());
	int num = atoi(number.c_str());

//  for debug
//	cout << line << endl;
//	cout << name << endl;
//	cout << grade << endl;
//	cout << number << endl;

	return Student(name.c_str(), gr, num);
}

double StudentDataBase::getAverageScore(const SimpleString& studentName) {
	Student* toGetFrom = searchRecord(studentName);
	if (toGetFrom != nullptr)
		return toGetFrom->getAvgScore();
	return -1;
}

bool StudentDataBase::setAverageScore(double newScore,
		const SimpleString& studentName) {
	Student* toGetFrom = searchRecord(studentName);
	if (toGetFrom != nullptr)
		return toGetFrom->setAvgScore(newScore);
	return false;
}

void trimName(string& candidateName) {
	char currCh;
	bool lastWasSpace = false;
	for (unsigned int i = candidateName.size() - 1; i >= 0; i--) {
		currCh = candidateName.at(i);
		if (lastWasSpace) {
			if (currCh == ' ') {
				candidateName.erase(i);
				continue;
			}
			lastWasSpace = false;
		} else {
			if (currCh == ' ')
				lastWasSpace = true;
		}
	}
}

bool checkName(string& candidateName) {
	if (candidateName.size() > 30 || candidateName.size() < 6)
		return false;

	char currCh;
	for (unsigned int i = 0; i < candidateName.size(); i++) {
		currCh = candidateName.at(i);
		if (currCh != ' '
				&& (currCh >= 'Z' || currCh <= 'A' || currCh >= 'z'
						|| currCh >= 'a'))
			return false;
	}
	return true;
}

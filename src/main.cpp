/*
 * main.cpp
 *
 *  Created on: Jan 16, 2016
 *      Author: erolh
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "StudentDataBase.h"

using namespace std;

static const char alpha[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz      ";

int stringLength = sizeof(alpha) - 1;

char genRandom()  // Random string generator function.
{
	return alpha[rand() % stringLength];
}

void StudentDataBaseDemo();

string getRandomString(int minLength, int maxLenght) {
	string test;
	for (int z = 0; z < (rand() % (maxLenght - minLength) + minLength); z++) {
		test += genRandom();
	}
	return test;
}

void generate(unsigned long int numStudents);

int main() {

	//generate(1000000);
	StudentDataBaseDemo();

	return 0;
}

void generate(unsigned long int numStudents) {
	StudentDataBase generator;

	double currentScore = 0;
	int currentPhoneNumber = 0;
	string currentName;
	fstream fileToWrite;
	fileToWrite.open("dataBase.txt", ios::out | ios::trunc);
	for (unsigned long int i = 0; i < numStudents; i++) {
		currentScore = ((double) ((rand() % 40) + 20)) / 10;
		currentPhoneNumber = (rand() % 999999) + 359000000;

		fileToWrite << left << setw(30) << getRandomString(5, 29) << " "
				<< setw(3) << currentScore << " " << currentPhoneNumber << endl;

	}
	fileToWrite.close();
}

void StudentDataBaseDemo() {
	StudentDataBase demoDataBase;
	demoDataBase.loadFromFile("dataBase.txt");

	demoDataBase.insertToStream(cout);
}

/*
 * DataBase.h
 *
 *  Created on: Jan 16, 2016
 *      Author: erolh
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <fstream>
#include <iostream>

#include "btree_map.h"

using namespace std;
using namespace btree;

template<typename Key, typename Elem>
class DataBase {
	typedef btree_map<Key, Elem> bTree;
	bTree dataBase;
public:
	DataBase() {

	}

	// too specific to be implemented at this point
	//void loadFromFile(const char* fileName);
	Elem* searchRecord(const Key& toLookFor);
	bool addRecord(const Key& toAddK, const Elem& toAddE);
	bool deleteRecord(const Key& toDelete);
	void storeToFile(const char* fileName);

	void insertToStream(ostream& os);
	void insertToStreamWithKeys(ostream& os);
};

template<typename Key, typename Elem>
inline bool DataBase<Key, Elem>::addRecord(const Key& toAddK,
		const Elem& toAddE) {
	if (dataBase.find(toAddK) != dataBase.end())
		return false;
	dataBase[toAddK] = toAddE;
	return true;
}

template<typename Key, typename Elem>
inline Elem* DataBase<Key, Elem>::searchRecord(const Key& toLookFor) {
	auto record = dataBase.find(toLookFor);

	if (record == dataBase.end())
		return nullptr;
	return &(record->second);
}

template<typename Key, typename Elem>
inline bool DataBase<Key, Elem>::deleteRecord(const Key& toDelete) {
	if (dataBase.erase(toDelete) > 0)
		return true;
	return false;
}

template<typename Key, typename Elem>
inline void DataBase<Key, Elem>::storeToFile(const char* fileName) {
	fstream fileToWrite;
	fileToWrite.open(fileName, ios::out | ios::trunc);

	insertToStream(fileToWrite);

	fileToWrite.close();
}

template<typename Key, typename Elem>
inline void DataBase<Key, Elem>::insertToStream(ostream& os) {
	auto start = dataBase.begin();
	auto end = dataBase.end();
	while (start != end) {
		os << start->second;
		start++;
	}
}

template<typename Key, typename Elem>
inline void DataBase<Key, Elem>::insertToStreamWithKeys(ostream& os) {
	auto start = dataBase.begin();
	auto end = dataBase.end();
	int counter = 1;
	while (start != end) {
		os << counter << ". " << start->first << " : " << start->second;
		start++;
		counter++;
	}
}

#endif /* DATABASE_H_ */

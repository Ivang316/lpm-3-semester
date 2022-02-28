#pragma once
#include "List.h" 

const int maxSize = 200;

class ListTable : public List {
public:
	int getCount();
	bool searchElem(string& s);
	void insertElem(string& s);
	void deleteElem(string& s);
};

class HashTable {
	int size = maxSize;
	ListTable table[maxSize];
public:
	int hash(string word);
	bool search(string data);
	void insert(string data);
	int colls();
};

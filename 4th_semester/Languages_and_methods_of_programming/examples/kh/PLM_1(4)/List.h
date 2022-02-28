#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class List {
public:
	struct Node {
		string data;
		Node* next;
	};
	Node* head;
	int count;
public:
	List() : head(0), count(0) {};
	bool isEmpty();
	void addToHead(string data);
	void deleteFromHead();
	void deleteAfterNode(Node* node);
	void clear();
};

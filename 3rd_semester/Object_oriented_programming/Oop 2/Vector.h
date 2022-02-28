#pragma once
#include <iostream>
using namespace std;

class Vector {
	struct Node {
		double val = 0; //coefficient
		Node* next = nullptr;
	}; 
	int len = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
	void clear();
	void push(double value);
public:
	Vector() {};
	Vector(Vector&);
	~Vector();
	void fill_from_console();
	double dot_product(Vector&);
	Vector& operator=(Vector&);
	Vector* operator+(Vector&);
	Vector* operator-(Vector&);
	void operator*(double);
	bool operator==(Vector&);
	bool operator!=(Vector&);
	friend ostream& operator<<(ostream&, Vector&);
	friend istream& operator>>(istream&, Vector&);	
};


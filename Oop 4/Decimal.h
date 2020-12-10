#pragma once

#include <iostream>
#include "Array.h"
using namespace std;


class Decimal: public Array {
	unsigned char* arr = nullptr;
	void init_with_string(const string&);
	void remove_leading_zeros();
	void resize(int);
	void fill(unsigned char);
public:
	Decimal();
	Decimal(int number);
	Decimal(const string&);
	Decimal(Decimal&);
	
	Decimal* operator+(Decimal&);			 
	Decimal* operator-(Decimal&);	
	const bool operator==(Decimal&);				 
	const bool operator!=(Decimal&);				 
	const bool operator>(Decimal&);
	const bool operator<(Decimal&);
	const bool operator<=(Decimal&);
	const bool operator>=(Decimal&);
	const unsigned char& operator[](const unsigned long);
	friend istream& operator>>(istream&, Decimal&);
	friend ostream& operator<<(ostream&, Decimal&);
};


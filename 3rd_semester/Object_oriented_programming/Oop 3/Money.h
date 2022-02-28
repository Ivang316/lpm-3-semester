#pragma once
#include <iostream>
using namespace std;

class Money {
	long sum = 0;
	unsigned char kopek = 0;
public:
	Money() {}
	Money(double);
	void set_sum(long);
	void set_kopek(unsigned char);
	void set(double);
	long get_sum();
	unsigned char get_kopek();
	double to_double();
	Money operator+(Money&);
	Money operator-(Money&);
	Money operator*(double);
	bool operator==(Money&);
	friend ostream& operator<<(ostream&, Money); 
	friend istream& operator>>(istream&, Money);
};

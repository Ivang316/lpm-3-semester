#pragma once
#include <iostream>
#include <string>
using namespace std;


class Array {
	unsigned int* arr = nullptr;
	static const long maxLen = 1000000;
	long len;
public:
	Array(long length = 1);
	Array(unsigned int*, long);
	Array(string&);

	Array(const Array&);

	long gLen();
	void sLen(long);
	long gMaxLen();

	void resize(long);
	bool contains(unsigned int);
	unsigned int& operator[](long);

	virtual void foreach(double*&, long&) = 0;
	virtual void sum(Array&, Array&, Array&) = 0;

	friend istream& operator>>(istream&, Array&);
	friend ostream& operator<<(ostream&, Array&);
};


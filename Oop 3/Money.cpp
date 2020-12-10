#include "Money.h"
#include <iostream>
#include <string>
using namespace std;

Money::Money(double val) {
	set(val);
}
long Money::get_sum() { 
	return sum; 
}
unsigned char Money::get_kopek() { 
	return kopek; 
}
void Money::set_sum(long number) { 
	sum = number; 
}
void Money::set_kopek(unsigned char number) { 
	kopek = number; 
}
void Money::set(double val) {
	if (abs(val) <= (pow(2, 63) - 1)) {
		sum = val;
		double tmpFrac = val - sum;
		kopek = tmpFrac * 100;
	}
}
double Money::to_double() {
	return sum + static_cast<double>(kopek) / 100;
}
Money Money::operator+(Money& a) {
	Money res(to_double() + a.to_double());
	return res;
}
Money Money::operator-(Money& a) {
	Money res(to_double() - a.to_double());
	return res;
}
Money Money::operator*(double factor) {
	set(to_double() * factor);
	return *this;
}
bool Money::operator==(Money& a) {
	return (sum == a.sum) && (kopek == a.kopek);
}
ostream& operator<<(ostream& out, Money m) {
	if (abs(m.kopek) < 10)
		out << m.sum << ",0" << +m.kopek;
	else
		out << m.sum << ',' << +m.kopek;
	return out;
}
istream& operator>>(istream& in, Money m) {
	in >> m.sum >> m.kopek;
	return in;
}


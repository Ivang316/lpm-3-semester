#pragma once

#include <iostream>
#include <string>
using namespace std;


class Child {
	string firstName, middleName, lastName;
	int year, month, day;

public:
	Child() {
		firstName = middleName = lastName = "";
		year = month = day = 0;
	}

	Child(string firstN, string middleN, string lastN, int y, int m, int d) :
		firstName(firstN), middleName(middleN), lastName(lastN),
		year(y), month(m), day(d) { }

	friend ostream& operator<<(ostream& out, const Child& obj) {
		out << obj.firstName << ' ' << obj.middleName << ' ' << obj.lastName << '\n';
		out << obj.year << ' ' << obj.month << ' ' << obj.day << '\n';
		return out;
	}

	Child& operator=(const Child& obj) {
		firstName = obj.firstName;
		middleName = obj.middleName;
		lastName = obj.lastName;
		year = obj.year;
		month = obj.month;
		day = obj.day;
		return *this;
	}

	bool operator==(const Child& obj) {
		return(
			firstName == obj.firstName &&
			middleName == obj.middleName &&
			lastName == obj.lastName &&
			year == obj.year &&
			month == obj.month &&
			day == obj.day
			);
	}

	bool operator!=(const Child& obj) {
		return(
			firstName != obj.firstName ||
			middleName != obj.middleName ||
			lastName != obj.lastName ||
			year != obj.year ||
			month != obj.month ||
			day != obj.day
			);
	}
};
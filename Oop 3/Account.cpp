#include "Account.h"

Account::Account(string isurname, int inumber, double ipersentage, Money amount = 0) :
	surname(isurname), num(inumber), prst(ipersentage), sum(amount) {}
void Account::set_surname(string isurname) { 
	surname = isurname; 
}
void Account::withdraw(Money amount) { 
	sum = sum - amount; 
}
void Account::top_up(Money amount) { 
	sum = sum + amount; 
}
void Account::charge_interest() { 
	sum = sum * prst; 
}
double Account::to_dollars() { 
	return sum.to_double() / 78; 
}
double Account::to_euro() { 
	return sum.to_double() / 91; 
}
string Account::to_words(int number) {
	if (number && number < 1000) {
		const string specialCases[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
		const string onesPlaces[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		const string tensPlaces[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

		string res;
		int t = number;
		if (t % 100 >= 10 && t % 100 <= 19) {
			res = specialCases[t % 100 - 10];
			t /= 100;
		}
		else {
			if (t % 10) //единицы
				res = onesPlaces[t % 10 - 1] + ' ' + res;
			t /= 10;
			if (t % 10 > 1) //десятки
				res = tensPlaces[t % 10 - 2] + ' ' + res;
			t /= 10;
		}
		if (t) //сотни
			res = onesPlaces[t - 1] + " hundred " + res;
		return res;
	}
	else
		return "";
}
string Account::sum_to_string() {
	long ruble = sum.get_sum();
	unsigned char kopek = sum.get_kopek();
	string res;
	if (kopek)
		res = to_words(kopek) + "kopeks";
	for (int i = 0; ruble; i++) {
		if (i == 0) {
			res = to_words(ruble % 1000) + "rubles " + res;
			ruble /= 1000;
			continue;
		}
		if (i == 1) {
			res = to_words(ruble % 1000) + "thousand " + res;
			ruble /= 1000;
			continue;
		}
		if (i == 2) {
			res = to_words(ruble % 1000) + " million " + res;
			ruble /= 1000;
			continue;
		}
		if (i == 3) {
			res = to_words(ruble % 1000) + " billion " + res;
			ruble /= 1000;
			continue;
		}
		if (i == 4) {
			res = to_words(ruble % 1000) + " trillion " + res;
			ruble /= 1000;
			continue;
		}
	}
	return res;
}
string Account::get_surname() {
	return surname;
}
int Account::get_number() {
	return num;
}
double Account::get_persentage() {
	return prst;
}
double Account::get_sum() {
	return sum.to_double();
}


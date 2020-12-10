#pragma once
#include "Money.h"
#include <string>
using namespace std;

class Account {
	string surname;
	int num = 0;
	double prst = 1; //процентная ставка
	Money sum;
	string to_words(int);
public:
	Account(){}
	Account(string, int, double, Money);
	void set_surname(string);
	void withdraw(Money); //снять со счета
	void top_up(Money); //пополнить
	void charge_interest(); //начислить проценты
	double to_dollars();
	double to_euro();
	string sum_to_string();
	string get_surname();
	int get_number();
	double get_persentage();
	double get_sum();
};



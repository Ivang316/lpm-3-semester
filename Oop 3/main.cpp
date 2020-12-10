/* 
41 Создать класс Account (задание 32), используя для представления суммы класс Money (задание 24).

32 Класс Account — банковский счет. Четыре поля: фамилия, номер счета, процент начисления, сумма в рублях. Операции: смена владельца, снять со счета, пополнить счет, начислить проценты, перевести в доллары, в евро, преобразовать в числительное

24 Класс Money. Поле long для рублей и unsigned char для копеек. Реализовать сложение, вычитание и умножение*/

#include <iostream>
#include "Money.h"
#include "Account.h"
using namespace std;

//вспомогетельные функции
void show_list();
Account* create_acc();
void acc_info(Account&);
void change_surname(Account&);
void withdraw(Account&);
void top_up(Account&);
void charge_interest(Account&);
void print_sum_as_number(Account&);

int main() {
	int choice;
	Account* a = create_acc();
	do {
		system("cls");
		acc_info(*a);
		show_list();
		cin >> choice;
		switch (choice) {
		case 1: {a = create_acc(); break; }
		case 2: {change_surname(*a); break; }
		case 3: {withdraw(*a); break; }
		case 4: {top_up(*a); break; }
		case 5: {charge_interest(*a); break; }
		case 6: {print_sum_as_number(*a); break; }
		}
	} while (choice);
}

void show_list() {
	cout << "0 Exit \n1 Create a new account \n2 Change surname \n3 Withdraw \n4 Top up \n5 Charge interest \n6 Show sum as a number \n";
}
Account* create_acc() {
	cout << "To create an account enter surname, account number, persentage and sum of money\n";
	cout << "Surname: ";
	string surname;
	cin >> surname;
	cout << "Account number: ";
	int number;
	cin >> number;
	cout << "Persentage: ";
	double prst;
	cin >> prst;
	cout << "Money on account: ";
	double sum;
	cin >> sum;
	Account* result = new Account(surname, number, prst, sum);
	return result;
}
void acc_info(Account& a) {
	cout << "Surname: " << a.get_surname() << "   Number: " << a.get_number() << "   Persentage: " << a.get_persentage() << "   Sum: " << a.get_sum() << endl;
}
void change_surname(Account& a) {
	cout << "Enter new surname: ";
	string s;
	cin >> s;
	a.set_surname(s);
}
void withdraw(Account& a) {
	cout << "Enter amount: ";
	double amount;
	cin >> amount;
	a.withdraw(amount);
}
void top_up(Account& a) {
	cout << "Enter amount: ";
	double amount;
	cin >> amount;
	a.top_up(amount);
}
void charge_interest(Account& a) {
	a.charge_interest();
}
void print_sum_as_number(Account& a) {
	cout << a.sum_to_string() << '\n';
	system("pause");
}



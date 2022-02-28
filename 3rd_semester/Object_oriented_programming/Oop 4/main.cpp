/*
������� ������� ����� Array
 1 ����-������ ����������� ����
 2 ���� ��� �������� ���������� ��������� � �������� �������-������� � N
 3 ����������� ��������� ������ ������� � ����������� ���������

  ������� ����������� �������������, �������� ���������� ��������� � ��������� ��������(�� ��������� 0)
  ����������� �������� []. ��������� ������ �� �����������
�������������������������������������������������������
������� ����������� ����� Decimal ��� ������ � ������������ ������ �������
 ����� � unsigned char[N] ��� N ��� ���� �� Array
 [0] �������, [1] ������� � ��� �����
 ������� ����������� ������������� � ��� ����������
 ����������� � ������� ���������� ����������� �������� ��� ����� �� C++, ���������, ����, �����, ������������
*/
#include <iostream>
#include "Array.h"
#include "Decimal.h"
using namespace std;


void show_list();
void show_numbers(Decimal*, Decimal*);
void change_number(Decimal*&);
void add(Decimal*, Decimal*);
void subtract(Decimal*, Decimal*);
void compare(Decimal*, Decimal*);


int main() {
	int choice;
	Decimal* a = new Decimal, * b = new Decimal;
	cout << "Enter the first number\n";
	cin >> *a;
	cout << "Enter the second number\n";
	cin >> *b;
	do {
		system("cls");
		show_list();
		show_numbers(a, b);
		cin >> choice;
		switch (choice) {
		case 1: { change_number(a); break; }
		case 2: { change_number(b); break; }
		case 3: { add(a, b); break; }
		case 4: { subtract(a, b); break; }
		case 5: { compare(a, b); break; }
		}
	} while (choice);
	delete a; delete b;
}


void show_list() {
	cout << "Choose a number of action \n0 Exit \n1 Change first number \n2 Change second number \n3 Sum the numbers \n4 Subtract second from first \n5 Check equality\n";
}

void show_numbers(Decimal* a, Decimal* b) {
	cout << "First " << *a << "\nSecond " << *b << '\n';
}

void change_number(Decimal*& num) {
	cout << "Enter new number\n";
	cin >> *num;
}

void add(Decimal* a, Decimal* b) {
	Decimal* tmp = *a + *b;
	cout << "Result of addition\n" << *tmp << '\n';
	delete tmp;
	system("pause");
}

void subtract(Decimal* a, Decimal* b) {
	if (*a < *b)
		cout << "Cannot subtract bigger number from smaller\n";
	else {
		Decimal* tmp = *a - *b;
		cout << "Result of subtraction\n" << *tmp << '\n';
		delete tmp;
	}
	system("pause");
}

void compare(Decimal* a, Decimal* b) {
	if (*a == *b)
		cout << "Numbers are equal\n";
	else
		if (*a > * b)
			cout << "First is greater than second\n";
		else
			cout << "First is less than second\n";
	system("pause");
}


#include <iostream>
#include "Vector.h"
using namespace std;

void show_list();
void add();
void subtraction();
void multiply();
void product();
void compare();

/*—оздать класс n-мерных векторов с использованием списка. –еализовать + - == != << >> умножение на число, скал€рное произведение*/

int main() {
	show_list();
	int choice;
	do {
		cin >> choice;
		system("cls");
		switch (choice) {
		case 0: { break; }
		case 1: { show_list(); break; }
		case 2: { add(); break; }
		case 3: { subtraction(); break; }
		case 4: { multiply(); break; }
		case 5: { product(); break; }
		case 6: { compare(); break; }
		default: {}
		};
	} while (choice);
}


void show_list() {
	cout << "0 Exit \n1 Show this list \n2 Add vectors "
		<< "\n3 Subtract vectors \n4 Multiply by number \n5 Compute dot product "
		<< "\n6 Compare vectors\n\n";
}

void add() {
	Vector a, b;
	a.fill_from_console();
	b.fill_from_console();
	Vector* c = a + b;
	cout << *c << "\n";
}
void subtraction() {
	Vector a, b;
	a.fill_from_console();
	b.fill_from_console();
	Vector* c = a - b;
	cout << *c << "\n";
}
void multiply() {
	Vector a;
	a.fill_from_console();
	cout << "Enter a factor: ";
	int x;
	cin >> x;
	a * x;
	cout << a;
	cout << endl;
}
void product() {
	Vector a, b;
	a.fill_from_console();
	b.fill_from_console();
	double x = a.dot_product(b);
	cout << x << "\n";
}
void compare() {
	Vector a, b;
	a.fill_from_console();
	b.fill_from_console();
	if (a == b)
		cout << "Vectors are equal\n";
	else
		cout << "Vectors are not equal\n";
}



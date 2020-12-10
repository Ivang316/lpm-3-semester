#include <iostream>
#include "Stack.h"
using namespace std;
//9 ƒан стек вещественных чисел. ѕроверить, упор€дочены ли числа по возрастанию или по убыванию. »сходный стек не мен€ть.

int main() {
	Stack a, b, c;
	for (int i = 0; i < 32; i += 2) 
		a.push(i);
	for (int i = 99; i > 50; i -= 3)
		b.push(i);
	for (int i = 0; i < 10; i++)
		c.push(rand() % 100);
	
	cout << boolalpha << "List a: ";
	a.print_values();
	cout << "\nList b: ";
	b.print_values();
	cout << "\nList c: ";
	c.print_values();

	cout << "\na increasing: " << a.increasing();
	cout << "\na decreasing: " << a.decreasing();
	cout << "\n\nb increasing: " << b.increasing();
	cout << "\nb decreasing: " << b.decreasing();
	cout << "\n\nc increasing: " << c.increasing();
	cout << "\nc decreasing: " << c.decreasing();
}

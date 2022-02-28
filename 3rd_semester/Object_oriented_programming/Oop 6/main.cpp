//стр 125 н 17 Реализовать шаблон стека в виде односвязного списка

#include <iostream>
#include "Stack.h"
using namespace std;

void show_list();
template<class T>
void add_elem(Stack<T>&);
template<class T>
void pop_elem(Stack<T>&);


int main() {
	Stack<string> s;
	cout << "Filling the stack\n";
	cin >> s;
	int choice;
	do {
		system("cls");
		show_list();
		cout << "Stack: " << s << '\n'; 
		cin >> choice;
		switch (choice) {
		case 1: { cin >> s; break; }
		case 2: { add_elem(s); break; }
		case 3: { pop_elem(s); break; }
		}
	} while (choice);
}


void show_list() {
	cout << "Choose a number of action \n0 Exit \n1 Create new stack \n2 Push element \n3 Pop element\n";
}


template<class T>
void add_elem(Stack<T>& s) {
	cout << "Enter a new element: ";
	T tmp;
	cin >> tmp;
	s.push(tmp);
}

template<class T>
void pop_elem(Stack<T>& s) {
	try {
		s.pop();
	}
	catch (exception& error) {
		cout << error.what() << '\n';
		system("pause");
	}
}




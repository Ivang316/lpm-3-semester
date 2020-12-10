//Стр 68 н 81. Создать абстрактный базовый класс Array с виртуальными методами сложения и поэлементной обработки массива foreach(). Разработать производные классы AndArray и OrArray. В первом классе операция сложения реализуетя как пересечение можеств, а поэлементная обработка представляется собой извлечение квадратного корня. Во втором классе операция сложения реализуется как объединение, а поэлементная обработка — вычисление логарифма.

/*Абстр баз класс Array с вирт. методами сложения и foreach()
Произв класс AndArr сложение — пересечение множеств, foreach() — извлечение кв корня
Произв клссс  OrArr сложение — объединение множеств, foreach() — вычисление логарифма*/

#include <iostream>
#include "Array.h"
#include "AndArray.h"
#include "OrArray.h"
using namespace std;

string cin_Array_type(Array*&);
void show_list();
void show_arrays_info(Array*, string&, Array*, string&);
void show_sum_for_first(Array*, Array*);
void show_sum_for_second(Array*, Array*);
void show_foreach(Array*, string&);


int main() {
	Array* first = nullptr, * second = nullptr;
	cout << "Filling the first array. ";
	string firstType = cin_Array_type(first);
	cin >> *first;
	cout << "\nFilling the second array. ";
	string secondType = cin_Array_type(second);
	cin >> *second;

	int choice;
	do {
		system("cls");
		show_list();
		show_arrays_info(first, firstType, second, secondType);
		cin >> choice;
		switch (choice) {
		case 1: { 
			firstType = cin_Array_type(first);
			cin >> *first; 
			break; 
		}
		case 2: { 
			secondType = cin_Array_type(second);
			cin >> *second; 
			break; 
		}
		case 3: { 
			show_sum_for_first(first, second); 
			break; 
		}
		case 4: { 
			show_sum_for_second(first, second); 
			break;
		}
		case 5: { 
			show_foreach(first, firstType); 
			break; 
		}
		case 6: { 
			show_foreach(second, secondType); 
			break; 
		}
		}
	} while (choice);

	delete first; delete second;
}


string cin_Array_type(Array*& arr) {
	cout << "\nEnter type of the array: AndArray or OrArray\n";
	string Type;
	cin >> Type;
	if (Type == "AndArray")
		arr = new AndArray;
	else {
		arr = new OrArray;
		Type = "OrArray";
	}
	return Type;
}

void show_list() {
	cout << "Choose a number of action \n0 Exit \n1 Change first array \n2 Change second array \n3 Show sum for first \n4 Show sum for second \n5 Show foreach for first \n6 Show foreach for second";
}

void show_arrays_info(Array* a, string& aType, Array* b, string& bType) {
	cout << "\n" << "First " << aType << ": " << *a << "\n" << "Second " << bType << ": " << *b << "\n";
}

void show_sum_for_first(Array* a, Array* b) {
	AndArray* result = new AndArray;
	a->sum(*a, *b, *result);
	cout << "Result: " << *result << "\n";
	system("pause");
	delete result;
}

void show_sum_for_second(Array* a, Array* b) {
	AndArray* result = new AndArray;
	b->sum(*a, *b, *result);
	cout << "Result: " << *result << "\n";
	system("pause");
	delete result;
}

void show_foreach(Array* a, string& type) {
	double* resArr = nullptr;
	long len = 0;
	a->foreach(resArr, len);

	if (type == "AndArray")
		cout << "Square root: ";
	else
		cout << "Logarithm: ";

	for (int i = 0; i < len; i++)
		cout << resArr[i] << ' ';
	cout << "\n";
	delete[] resArr;
	system("pause");
}

//стр 125 н 17 Реализовать шаблон стека в виде односвязного списка

#include <iostream>
#include "Stack.h"

using namespace std;


int main() { 
	try {
		Stack<int> a;
		/*for (int i = 0; i < 5; i++)
			s.push(i);*/
		cin >> a;
		a.push(1); a.push(2); a.push(3); a.push(4); a.push(5); a.push(6);
		Stack<int> s = a;
		a.pop(); a.pop(); a.pop();
		while (!s.empty()) {
			cout << s.top() << "\n";
			s.pop();
		}
	}
	catch (exception& error) {
		cout << "An exception was caught: " << error.what() << "\n";
	}
}





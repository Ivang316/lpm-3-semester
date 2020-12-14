#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Choose a number of action: \n0 Exit \n";
	for (int i = 10, peremennaya = 1; i < 162; i++, peremennaya++) {
		string action;
		if (i < 100)
			action = to_string(i) + "  Print \'" + (char)(rand() % 200 + 50) + "\'  ";
		else
			action = to_string(i) + " Print \'" + (char)(rand() % 200 + 50) + "\'  ";
		if (peremennaya % 6 == 0)
			action += "\n";
		cout << action;
	}
}





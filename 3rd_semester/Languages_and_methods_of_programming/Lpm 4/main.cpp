#include <iostream>
#include "Tree.h"
using namespace std;

/*��������� ������� ������������ � ����������� �������� ��������� ������, ��� �������� �������� ��������*/

int main() {
	Btree a;
	a.insert(19);
	for (int i = 2; i < 43; i += 2)
		a.insert(i);
	a.print();
	cout << '\n';
	a.swap_max_min();
	a.print();
}

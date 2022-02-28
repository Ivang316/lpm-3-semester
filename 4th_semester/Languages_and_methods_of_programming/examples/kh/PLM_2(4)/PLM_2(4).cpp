// PLM_2(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "TrieTree.h"
using namespace std;

void filePrint(string fileName, string str, Trie tree) {
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "Enable to open the file!\n";
	}
	else {
		while (!file.eof()) {
			file >> str;
			tree.insert(str);
			str.clear();
		}
	}
	file.close();
}

int main() {
	ifstream file;
	string substr;
	Trie tree;

	filePrint("file.txt", substr, tree);

	cout << "The entire contents of the file:\n";
	tree.print();
	
	cout << "Enter substring:\n";
	cin >> substr;
	tree.substring(substr);

	cout << "\nFile contents without substring:\n";
	tree.print();

	system("pause");
	return 0;
}

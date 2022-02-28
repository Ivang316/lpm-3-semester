// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "List.h"
using namespace std;
void filePrint(string file) {
	ifstream myFile(file);
	if (!myFile.is_open())
		cout << "Error! Unable to open the file!\n";
	else {
		while (!myFile.eof()) {
			string word;
			myFile >> word;
			cout << word << "\n";
		}
	}
}

int repeatedWordsCount(string file, HashTable table) {
	int count = 0;
	ifstream myFile(file);
	if (!myFile.is_open())
		cout << "Error! Unable to open the file!\n";
	else {
		while (!myFile.eof()) {
			string word;
			myFile >> word;
			table.insert(word);
		}
		count = table.colls();
	}
	return count;
}

int main() {
	cout << "File: \n=============\n";
	filePrint("words.txt");
	cout << "=============\n";

	HashTable hashtable;
	int result = repeatedWordsCount("words.txt", hashtable);
	cout << "\nCount of words repeated more than five times: " << result << "\n";

	cin.get();
	return 0;
}

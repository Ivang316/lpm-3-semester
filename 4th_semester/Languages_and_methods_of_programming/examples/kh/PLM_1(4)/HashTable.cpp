#include "HashTable.h"

int ListTable::getCount() {
	return count;
}

bool ListTable::searchElem(string& data) {
	bool flag = false;
	Node* p = head;
	while (p) {
		if (p->data == data)
			flag = true;
		p = p->next;
	}
	return flag;
}
void ListTable::insertElem(string& data) {
	addToHead(data);
}
void ListTable::deleteElem(string& data) {
	Node* p = head;
	while (!isEmpty()) {
		if (p->data != data)
			p = p->next;
		else {
			if (p == head)
				deleteFromHead();
			else
				deleteAfterNode(p);
		}
	}
}

int HashTable::hash(string word) {
	const int p = 31, k = 200;
	long long hash = 0, p_pow = 1;
	for (int i = 0; i < word.length(); i++) {
		hash += (word[i] - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	return hash % k;
}
bool HashTable::search(string data) {
	int h = hash(data);
	return table[h].searchElem(data);
}
void HashTable::insert(string data) {
	int h = hash(data);
	table[h].insertElem(data);
}

int HashTable::colls() {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (table[i].getCount() > 5)
			count++;
	return count;
}

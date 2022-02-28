#include <iostream>
#include "List.h"
#include <fstream>
using namespace std;

bool List::isEmpty() {
	return head == 0;
}

void List::addToHead(string data) {
	Node* p = new Node;
	p->data = data;
	p->next = head;
	head = p;
	count++;
}

void List::deleteFromHead() {
	if (head) {
		Node* p = head;
		head = head->next;
		p->next = 0;
		delete p;
		count--;
	}
}
void List::deleteAfterNode(Node* node) {
	if (node && node->next) {
		Node* p = node->next;
		node->next = p->next;
		p->next = 0;
		delete p;
		count--;
	}
}

void List::clear() {
	while (!isEmpty())
		deleteFromHead();
	delete head;
}

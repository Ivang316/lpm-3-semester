#include <iostream>
#include "Sllist.h"

Sllist::Sllist() {
	tail = head = 0;
}
Sllist::~Sllist() {
	while (head) {
		Node* iter = head;
		head = head->next;
		delete iter;
	}
}
void Sllist::swap(Node* a, Node* b) {
	int tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}
void Sllist::push_back(int inval) {
	if (head) {
		Node* newNode = new Node;
		tail->next = newNode;
		tail = newNode;
		newNode->next = 0;
		newNode->value = inval;
	}
	else {
		head = new Node;
		head->value = inval;
		head->next = 0;
		tail = head;
	}
}
Sllist* Sllist::merge(Sllist& li) {
	Sllist* newLi = new Sllist;
	Node* iter = this->head;
	while (iter) {
		newLi->push_back(iter->value);
		iter = iter->next;
	}
	iter = li.head;
	while (iter) {
		newLi->push_back(iter->value);
		iter = iter->next;
	}
	newLi->sort();
	return newLi;
}
void Sllist::sort() {
	bool ordered;
	do {
		ordered = true;
		Node* iter = this->head;
		while (iter->next) {
			if (iter->value > iter->next->value) {
				swap(iter, iter->next);
				ordered = false;
			}
			iter = iter->next;
		}
	} while (!ordered);
}
void Sllist::print_elements() {
	Node* iter = this->head;
	while (iter) {
		std::cout << iter->value << ' ';
		iter = iter->next;
	}
}

#include "Stack.h"
#include <iostream>

Stack::~Stack() {
	while (top) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}

void Stack::push(double inVal) {
	Node* temp = new Node;
	temp->next = top;
	top = temp;
	temp->value = inVal;
}

void Stack::print_values() {
	Node* temp = top;
	while (temp) {
		std::cout << temp->value << ' ';
		temp = temp->next;
	}
}

bool Stack::increasing() {
	bool increasing = true;
	Node* temp = top;
	while (temp->next and increasing) {
		if (temp->value >= temp->next->value)
			increasing = false;
		temp = temp->next;
	}
	return increasing;
}

bool Stack::decreasing() {
	bool decreasing = true;
	Node* temp = top;
	while (temp->next and decreasing) {
		if (temp->value <= temp->next->value)
			decreasing = false;
		temp = temp->next;
	}
	return decreasing;
}


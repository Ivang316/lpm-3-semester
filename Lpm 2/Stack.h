#pragma once

class Stack {
	struct Node {
		double value = 0;
		Node* next = 0;
	};
	Node* top = 0;
public:
	~Stack();
	void push(double);
	void print_values();
	bool increasing();
	bool decreasing();
};

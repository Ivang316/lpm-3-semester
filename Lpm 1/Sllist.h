#pragma once
//single linked list
class Sllist {
	struct Node {
		int value = 0;
		Node* next = 0;
	};
	Node* head, * tail;

	void swap(Node* a, Node* b);
public:
	Sllist();
	~Sllist();
	void push_back(int inval);
	Sllist* merge(Sllist& li);
	void sort();
	void print_elements();
};

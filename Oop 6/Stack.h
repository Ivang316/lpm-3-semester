#pragma once
#include <iostream>
using namespace std;


template<class T>
class Stack {
	struct Node {
		T data;
		Node* next;
		Node(Node* next, const T& val = T()) : next(next), data(val) {};
	};
	Node* head = nullptr;
	size_t nodeCnt = 0;
public:
	Stack() {};
	Stack(const Stack&);
	~Stack();

	const T& top() const;

	bool empty() const;
	size_t size() const;

	void push(const T&);
	void pop();

	friend ostream& operator<< <>(ostream&, const Stack<T>&);
	friend istream& operator>> <>(istream&, Stack<T>&);
};







template<class T>
Stack<T>::Stack(const Stack& other) {
	while (!empty())
		pop();
	
	Node* otherIt = other.head, * thisIt = nullptr;
	while (otherIt) {
		Node* newNode = new Node(nullptr, otherIt->data);
		if (head) {
			thisIt->next = newNode;
			thisIt = thisIt->next;
		}
		else {
			head = newNode;
			thisIt = head;
		}
		otherIt = otherIt->next;
		nodeCnt++;
	}
}


template<class T>
Stack<T>::~Stack() {
	while (!empty())
		pop();
}


template<class T>
const T& Stack<T>::top() const {
	if (empty())
		throw std::range_error("Accessing to empty Stack");
	return head->data;
}


template<class T>
bool Stack<T>::empty() const {
	return !head;
}


template<class T>
size_t Stack<T>::size() const {
	return nodeCnt;
}


template<class T>
void Stack<T>::push(const T& value) {
	Node* newNode = new Node(head, value);
	head = newNode;
	nodeCnt++;
}


template<class T>
void Stack<T>::pop() {
	Node* tmp = head;
	head = head->next;
	delete tmp;
	nodeCnt--;
}


template<class T>
ostream& operator<< <>(ostream& out, const Stack<T>& s) {
	/*Node* otherIt = s.head;
	while (otherIt) {
		out << otherIt->data << ' ';
		otherIt = otherIt->next;
	}*/
	return out;
}


template<class T>
istream& operator>> <>(istream& in, Stack<T>& s) {
	cout << "How many numbers do you want to enter?\n";
	int count;
	in >> count;
	cout << "Enter " << count << " numbers: ";
	T tmp;
	for (int i = 0; i < count; i++) {
		in >> tmp;
		s.push(tmp);
	}
	return in;
}











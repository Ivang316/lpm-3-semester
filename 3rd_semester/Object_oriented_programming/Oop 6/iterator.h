#pragma once
#include "Stack.h"


template<class T>
class Stack<T>::iterator {
	friend class Stack;
	Node* elem;
	iterator(Node* el) : elem(el) {};
public:
	iterator() : elem(nullptr) {};
	iterator(const iterator& other) : elem(other.elem) {};

	iterator& operator=(const iterator& other) {
		elem = other.elem;
		return *this;
	}

	bool operator==(const iterator& other) const { return elem == other.elem; }
	bool operator!=(const iterator& other) const { return elem != other.elem; }

	iterator& operator++() {
		if (elem)
			elem = elem.next;
		return *this;
	}
	T& operator*() const {
		if (!elem)
			throw std::exception("Dereferencing null iterator");
		return elem.data;
	}
};
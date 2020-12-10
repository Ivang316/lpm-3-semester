#include "Vector.h"
#include <iostream>
using namespace std;

//private methods
void Vector::clear() {
	len = 0;
	while (head) {
		Node* iter = head;
		head = head->next;
		delete iter;
	}
}

void Vector::push(double value) {
	++len;
	Node* tmp = new Node;
	tmp->val = value;
	if (head) {
		tail->next = tmp;
		tail = tmp;
	}
	else {
		head = tmp;
		tail = tmp;
	}

}


//public methods
Vector::Vector(Vector& v) {
	Node* iter = v.head;
	while (iter) {
		this->push(iter->val);
		iter = iter->next;
	}
}

Vector::~Vector() { clear(); }

void Vector::fill_from_console() {
	this->clear();
	cout << "Enter the dimension of vector: ";
	int dim = 0;
	do {
		if (dim < 0) cout << "Try another number\n";
		cin >> dim;
	} while (dim < 0);

	cout << "Enter " << dim << " numbers: ";
	for (int tmp, i = 0; i < dim; i++) {
		cin >> tmp;
		push(tmp);
	}
}

double Vector::dot_product(Vector& v) {
	if (len == v.len) {
		double result = 0;
		Node* it1 = head, * it2 = v.head;
		while (it1) {
			result += it1->val * it2->val;
			it1 = it1->next;
			it2 = it2->next;
		}
		return result;
	}
}

Vector& Vector::operator=(Vector& v) {
	this->clear();
	Node* iter = v.head;
	while (iter) {
		this->push(iter->val);
		iter = iter->next;
	}
	return *this;
}


Vector* Vector::operator+(Vector& v) {
	if (len == v.len) {
		Vector* res = new Vector;
		Node* it1 = head, * it2 = v.head;
		for (int i = 0; i < len; i++) {
			res->push(it1->val + it2->val);
			it1 = it1->next;
			it2 = it2->next;
		}
		return res;
	}
}

Vector* Vector::operator-(Vector& v) {
	if (len == v.len) {
		Vector* res = new Vector;
		res->len = len;
		Vector::Node* it1 = head, * it2 = v.head;
		for (int i = 0; i < len; i++) {
			res->push(it1->val - it2->val);
			it1 = it1->next;
			it2 = it2->next;
		}
		return res;
	}
}

void Vector::operator*(double num) {
	Node* iter = head;
	while (iter) {
		iter->val *= num;
		iter = iter->next;
	}
}

bool Vector::operator==(Vector& v) {
	if (len == v.len) {
		bool equal = true;
		Node* it1 = head, * it2 = v.head;
		while (it1) {
			if (it1->val != it2->val)
				equal = false;
			it1 = it1->next;
			it2 = it2->next;
		}
		return equal;
	}
}

bool Vector::operator!=(Vector& v) {
	return !(*this == v);
}

ostream& operator<<(ostream& out, Vector& v) {
	Vector::Node* iter = v.head;
	while (iter) {
		out << iter->val << ' ';
		iter = iter->next;
	}
	return out;
}

std::istream& operator>>(istream& in, Vector& v) {
	if (v.len) {
		cout << "Enter " << v.len << " numbers: ";
		Vector::Node* iter = v.head;
		for (int i = 0; i < v.len; i++) {
			in >> iter->val;
			iter = iter->next;
		}
	}
	return in;
}


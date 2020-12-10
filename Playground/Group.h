#pragma once
#include "Child.h"

#include <iostream>
#include <string>
using namespace std;


class Group {
	struct Node {
		Child data;
		Node* next;
	};

	string teacher;
	static int groupNumber;
	int childrenCount;
	Node* head;

	void popChild(Node** head) {
		Node* temp = *head;
		*head = (*head)->next;
		temp->next = 0;
		delete temp;
	}

	bool isEmpty(Node* head) {
		return !head;
	}

public:

	Group() {
		groupNumber++;
		childrenCount = 0;
		teacher = "";
		head = nullptr;
	}

	void setTeacher(string t) {
		teacher = t;
	}

	void pushChild(const Child& obj) {
		Node* temp = new Node;
		temp->data = obj;
		temp->next = head;
		head = temp;
		childrenCount++;
	}

	void deleteChild(const Child& obj) {
		if (head->data == obj) {
			popChild(&head);
		}
		else {
			Node* temp = head;
			while (temp->next && temp->next->data != obj) {
				temp = temp->next;
			}
			if (temp->next != NULL) {
				Node* delElem = temp->next;
				temp->next = delElem->next;
				delElem->next = NULL;
				delete delElem;
			}
		}
		childrenCount--;
	}

	bool hasChild(const Child& obj) {
		Node* temp = head;
		while (temp) {
			if (temp->data == obj) return true;
			temp = temp->next;
		}
		return false;
	}

	void clearList(Node** head) {
		while (!isEmpty(*head)) {
			popChild(head);
		}
	}

	~Group() {
		clearList(&head);
		groupNumber--;
	}

	void print(int groupNumber) {
		cout << "Teacher: " << teacher
			<< ", Group number " << groupNumber
			<< ", Count of children: " << childrenCount << '\n';

		Node* temp = head;
		while (temp) {
			cout << temp->data << '\n';
			temp = temp->next;
		}
	}
};

int Group::groupNumber = 0;

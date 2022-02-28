#include "Tree.h"
#include <iostream>

//private methods
void Btree::clear(Node* leaf) {
	if (leaf) {
		clear(leaf->left);
		clear(leaf->right);
		delete leaf;
	}
}

void Btree::insert(int value, Node* leaf) {
	if (value < leaf->val) {
		if (leaf->left) 
			insert(value, leaf->left);
		else {
			leaf->left = new Node;
			leaf->left->val = value;
		}
	}
	else {
		if (leaf->right) 
			insert(value, leaf->right);
		else {
			leaf->right = new Node;
			leaf->right->val = value;
		}
	}
}

void Btree::find_max(Node*& maxNode, Node* leaf) {
	if (leaf->right) 
		find_max(maxNode, leaf->right);
	else
		maxNode = leaf;
}

void Btree::find_min(Node*& minNode, Node* leaf) {
	if (leaf) {
		find_min(minNode, leaf->left);
		if (!leaf->left)
			minNode = leaf;
	}
}

void Btree::print(Node* leaf) {
	if (leaf) {
		print(leaf->left);
		std::cout << leaf->val << ' ';
		print(leaf->right);
	}
}





//public methods
Btree::~Btree() {
	this->clear();
}

void Btree::clear() {
	clear(root);
}

void Btree::insert(int value) {
	if (root)
		insert(value, root);
	else {
		root = new Node;
		root->val = value;
	}
}

void Btree::swap_max_min() {
	Node* maxNode = root, * minNode = root;
	find_max(maxNode, root);
	find_min(minNode, root);
	int temp = maxNode->val;
	maxNode->val = minNode->val;
	minNode->val = temp;	
}

void Btree::print() {
	print(root);
}



#pragma once
class Btree {
	struct Node {
		int val = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	Node* root = nullptr;
	void clear(Node*);
	void insert(int, Node*);
	void find_max(Node*&, Node*);
	void find_min(Node*&, Node*);
	void print(Node*);
public:
	~Btree();
	void clear();
	void insert(int);
	void swap_max_min();
	void print();
};


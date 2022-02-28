#pragma once
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	TrieNode* next[ALPHABET_SIZE + 1];
};

class Trie {
	TrieNode* root;
	void _insert(TrieNode* p, int i);
	void _remove(string str, string substr);
	void _substring(TrieNode* p, string str, string substr);
	void _print(TrieNode* p, string s);
public:
	Trie();
	void insert(string s);
	void remove(string s, TrieNode* p);
	void substring(string str);
	void print();
};

#include "TrieTree.h"
#include <string>

Trie::Trie() {
	root = new TrieNode[ALPHABET_SIZE + 1];
	for (int i = 0; i < ALPHABET_SIZE + 1; i++)
		root->next[i] = nullptr;
}

void Trie::_insert(TrieNode* p, int i) {
	p->next[i] = new TrieNode;
	for (int j = 0; j < ALPHABET_SIZE + 1; j++) {
		p->next[i]->next[j] = nullptr;
	}
}
void Trie::insert(string str) {
	TrieNode* p = root;
	for (int i = 0; i < str.length(); i++) {
		int index = str[i] - 'a';
		if (p->next[index]) {
			p = p->next[index];
		}
		else {
			_insert(p, index);
			p = p->next[index];	
		}
	}
	_insert(p, ALPHABET_SIZE);
}

void Trie::_remove(string str, string substr) {
	int index = str.find(substr);
	if (index > -1 && index < str.length()) {
		remove(str, root);
	}
}
void Trie::remove(string str, TrieNode* p) {
	if (str == "") {
		if (p->next[ALPHABET_SIZE]) {
			TrieNode* q = p->next[ALPHABET_SIZE];
			p->next[ALPHABET_SIZE] = 0;
			delete q;
		}
	}
	else {
		remove(str.erase(0, 1), p->next[str[0] - 'a']);
	}
} 

void Trie::_substring(TrieNode* p, string str, string substr) {
	for (int i = 0; i < ALPHABET_SIZE + 1; i++) {
		if (p->next[i]) {
			str += (char)(i + 'a');
			_substring(p->next[i], str, substr);
			if (str[str.length() - 1] == ALPHABET_SIZE + 'a') {
				str.erase(str.length() - 1, 1);
				_remove(str, substr);
			}
			if (str != "") {
				str.erase(str.length() - 1, 1);
			}
		}
	}
}
void Trie::substring(string str) {
	_substring(root, "", str);
}

void Trie::_print(TrieNode* p, string str) {
	for (int i = 0; i < ALPHABET_SIZE + 1; i++) {
		if (p->next[i]) {
			str += (char)(i + 'a');
			_print(p->next[i], str);
			if (str[str.length() - 1] == ALPHABET_SIZE + 'a') {
				str.erase(str.length() - 1, 1);
				cout << str << endl;
			}
			if (str != "") {
				str.erase(str.length() - 1, 1);
			}
		}
	}
}
void Trie::print() {
	_print(root, "");
}

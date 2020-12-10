#include "BitString.h"
#include <string>

BitString::BitString() {}
BitString::BitString(unsigned long a, unsigned long b = 0) {
	head = a;
	tail = b;
}
unsigned long BitString::get_head() { return head; }
unsigned long BitString::get_tail() { return tail; }
void BitString::set_head(unsigned long val) { head = val; }
void BitString::set_tail(unsigned long val) { tail = val; }
void BitString::negation() {
	head = ~head;
	tail = ~tail;
}
BitString BitString::disjunction(BitString a) {
	BitString result;
	result.head = head | a.head;
	result.tail = tail | a.tail;
	return result;
}
BitString BitString::conjunction(BitString a) {
	BitString result;
	result.head = head & a.head;
	result.tail = tail & a.tail;
	return result;
}
BitString BitString::exclusive_or(BitString a) {
	BitString result;
	result.head = head ^ a.head;
	result.tail = tail ^ a.tail;
	return result;
}
void BitString::shift_left(int bits) {
	unsigned long temp;
	temp = tail >> (sizeof(long) * 8 - bits);
	tail <<= bits;
	head <<= bits;
	head |= temp;
}
void BitString::shift_right(int bits) {
	unsigned long temp;
	temp = head << (sizeof(long) * 8 - bits);
	head >>= bits;
	tail >>= bits;
	tail |= temp;
}
std::string BitString::to_string() {
	return "bit string: " + std::to_string(head) + ' ' + std::to_string(tail);
}

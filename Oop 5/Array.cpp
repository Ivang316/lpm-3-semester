#include "Array.h"


Array::Array(long length) {
	if (length >= 0 && length < maxLen) 
		resize(length);
}


Array::Array(unsigned int* array, long length) {
	resize(length);
	for (int i = 0; i < len; i++) 
		arr[i] = array[i];
}


Array::Array(string& str) {
	resize(str.length());
	for (int i = 0; i < len; i++)
		arr[i] = str[i] - '0';
}


Array::Array(const Array& newArr) {
	len = newArr.len;
	if (arr)
		delete[] arr;
	arr = new unsigned int[len];

	for (int i = 0; i < gLen(); i++) 
		arr[i] = newArr.arr[i];
}


long Array::gLen() {
	return len;
}


void Array::sLen(long length) {
	if (length >= 0 && length < maxLen)
		len = length;
}


long Array::gMaxLen() {
	return maxLen;
}


void Array::resize(long newLen) {
	if (newLen > gMaxLen())
		return;

	unsigned int* newArr = new unsigned int[newLen];
	for (long i = 0; i < newLen && i < len; i++) {
		if (i < len) {
			newArr[i] = arr[i];
			continue;
		}
		if (i < newLen) {
			newArr[i] = 0;
			continue;
		}
	}

	delete[] arr;
	arr = newArr;
	len = newLen;
}


bool Array::contains(unsigned int elem) {
	for (int i = 0; i < this->gLen(); i++)
		if ((*this)[i] == elem)
			return true;
	return false;
}


unsigned int& Array::operator[](long index) {
	if (index >= 0 && index < len)
		return arr[index];
}


istream& operator>>(istream& in, Array& arr) {
	cout << "How many numbers do you want to enter?\n";
	int count;
	in >> count;
	arr.resize(count);
	cout << "Enter " << count << " number: ";
	for (int i = 0; i < count; i++)
		in >> arr[i];
	return in;
}


ostream& operator<<(ostream& out, Array& arr) {
	for (int i = 0; i < arr.gLen(); i++)
		out << arr[i] << ' ';
	return out;
}



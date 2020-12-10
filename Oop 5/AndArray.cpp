#include "AndArray.h"


AndArray::AndArray(long length): Array(length) {}


AndArray::AndArray(unsigned int* array, long length): Array(array, length) {}


AndArray::AndArray(string& str): Array(str) {}


AndArray::AndArray(Array& newArr): Array(newArr) {}


void AndArray::foreach(double*& arr, long& len){
	delete[] arr;
	len = gLen();
	arr = new double[len];
	for (int i = 0; i < gLen(); i++)
		arr[i] = sqrt((*this)[i]);
}


void AndArray::sum(Array& first, Array& second, Array& res) {
	int resultLen = 0;
	for (int i = 0; i < first.gLen(); i++)
		if (second.contains(first[i]))
			resultLen++;
	res.resize(resultLen);

	for (int i = 0, i2 = 0; i < first.gLen(); i++)
		if (second.contains(first[i])) {
			res[i2] = first[i];
			i2++;
		}	
}


#include "OrArray.h"


OrArray::OrArray(long length) : Array(length) {}


OrArray::OrArray(unsigned int* array, long length) : Array(array, length) {}


OrArray::OrArray(string& str) : Array(str) {}


OrArray::OrArray(Array& newArr) : Array(newArr) {}


void OrArray::foreach(double*& arr, long& len) {
	delete[] arr;
	len = gLen();
	arr = new double[len];
	for (int i = 0; i < gLen(); i++)
		arr[i] = log((*this)[i]);
}


void OrArray::sum(Array& first, Array& second, Array& res) {
	int resLen = first.gLen();
	for (int i = 0; i < second.gLen(); i++)
		if (!first.contains(second[i]))
			resLen++;
	res.sLen(resLen);

	int i2 = 0;
	for (int i = 0; i < first.gLen(); i++, i2++)
		res[i2] = first[i];
	for (int i = 0; i < second.gLen(); i++)
		if (!first.contains(second[i])) {
			res[i2] = second[i];
			i2++;
		}

	/*res.sLen(first.gLen() + second.gLen());
	int i2 = 0;
	for (int i = 0; i < first.gLen(); i++, i2++)
		res[i2] = first[i];
	for (int i = 0; i < second.gLen(); i++)
		if (!first.contains(second[i])) {
			res[i2] = second[i];
			i2++;
		}*/	

	/*for (int i = 0; i < second.gLen(); i++) {
		if (!res.contains(second[i])) {
			res.resize(res.gLen() + 1);
			res[res.gLen() - 1] = second[i];
		}
	}*/
}



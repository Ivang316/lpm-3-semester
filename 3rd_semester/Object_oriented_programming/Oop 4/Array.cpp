#include "Array.h"



Array::Array(long length) {
	if (length >= 0 && length < maxLen)
		len = length;
}


const long Array::gLen() {
	return len;
}


const long Array::gMaxLen() {
	return maxLen;
}


void Array::sLen(long length) {
	if (length >= 0 && length < maxLen)
		len = length;
}


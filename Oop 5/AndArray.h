#pragma once
#include "Array.h"


class AndArray: public Array {
public:
	AndArray(long length = 1);
	AndArray(unsigned int*, long);
	AndArray(string&);

	AndArray(Array&);

	void foreach(double*&, long&); //извлечение корня из элементов
	void sum(Array&, Array&, Array&); //пересечение множеств
};

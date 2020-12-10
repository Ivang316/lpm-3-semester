#pragma once
#include "Array.h"


class OrArray: public Array {
public:
	OrArray(long length = 1);
	OrArray(unsigned int*, long);
	OrArray(string&);
	
	OrArray(Array&);

	void foreach(double*&, long&); //вычисление логарифма элементов
	void sum(Array&, Array&, Array&); //объединение множеств, элементы могут повторяться
};


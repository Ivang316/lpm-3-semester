#pragma once
#include "Array.h"


class AndArray: public Array {
public:
	AndArray(long length = 1);
	AndArray(unsigned int*, long);
	AndArray(string&);

	AndArray(Array&);

	void foreach(double*&, long&); //���������� ����� �� ���������
	void sum(Array&, Array&, Array&); //����������� ��������
};

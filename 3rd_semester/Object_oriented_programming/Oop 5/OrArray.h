#pragma once
#include "Array.h"


class OrArray: public Array {
public:
	OrArray(long length = 1);
	OrArray(unsigned int*, long);
	OrArray(string&);
	
	OrArray(Array&);

	void foreach(double*&, long&); //���������� ��������� ���������
	void sum(Array&, Array&, Array&); //����������� ��������, �������� ����� �����������
};


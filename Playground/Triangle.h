#pragma once
#include "Angle.h"
#include <string>

class Triangle {
	Angle abc, acb, bac;
	double ab, ac, bc;
	void calculateAngles();
public:
	Triangle(double ab, double bc, double ac);

	void setAB(double ab);
	void setBC(double bc);
	void setAC(double ac);

	double getAB();
	double getBC();
	double getAC();
	Angle getABC();
	Angle getACB();
	Angle getBAC();
	double getPerimeter();
	double getArea();
	double getHeightAB();
	double getHeightAC();
	double getHeightBC();
	std::string triangleType();
};

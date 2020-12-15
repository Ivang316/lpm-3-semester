#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <cmath>

void Triangle::calculateAngles() {
	bac = Angle(acos((ab * ab + ac * ac - bc * bc) / (2 * ab * ac)) * 180 / M_PI, 0);
	abc = Angle(acos((ab * ab + bc * bc - ac * ac) / (2 * ab * bc)) * 180 / M_PI, 0);
	acb = Angle(acos((bc * bc + ac * ac - ab * ab) / (2 * bc * ac)) * 180 / M_PI, 0);
}

Triangle::Triangle(double AB, double BC, double AC) {
	ab = AB; bc = BC; ac = AC;
	calculateAngles();
}

void Triangle::setAB(double AB) {
	ab = AB;
	calculateAngles();
}

void Triangle::setBC(double BC) {
	bc = BC;
	calculateAngles();
}

void Triangle::setAC(double AC) {
	ac = AC;
	calculateAngles();
}

double Triangle::getAB() {
	return ab;
}
double Triangle::getBC() {
	return bc;
}
double Triangle::getAC() {
	return ac;
}
Angle Triangle::getABC() {
	return abc;
}
Angle Triangle::getACB() {
	return acb;
}
Angle Triangle::getBAC() {
	return bac;
}

double Triangle::getPerimeter() {
	return (ab + ac + bc);
}
double Triangle::getArea() {
	double p = getPerimeter() / 2;
	return std::sqrt(p * (p - ab) * (p - ac) * (p - bc));
}
double Triangle::getHeightAB() {
	return (2 * getArea()) / ab;
}
double Triangle::getHeightAC() {
	return (2 * getArea()) / ac;
}
double Triangle::getHeightBC() {
	return (2 * getArea()) / bc;
}

std::string Triangle::triangleType() {
	if (abc.toDegrees() == 90 || bac.toDegrees() == 90 || acb.toDegrees() == 90)
		return "The Triangle is Rectangular.";

	else if (abc.toDegrees() == bac.toDegrees() &&
			 abc.toDegrees() == acb.toDegrees() &&
			 bac.toDegrees() == acb.toDegrees())
		return "The Triangle is Equilateral.";

	else if (abc.toDegrees() == bac.toDegrees() ||
			 abc.toDegrees() == acb.toDegrees() ||
			 bac.toDegrees() == acb.toDegrees())
		return "The Triangle is Isosceles.";

	else return "The Triangle is Arbitrary.";
}

/*std::string Triangle::toString() {
	std::ostringstream triangle;
	triangle << "The sides of the triangle are equal: AB = " << ab << " BC = " << bc << " AC = " << ac;
	triangle << "The angles of the triangle are equal: A = " << bac << " B = " << abc << " C = " << acb;
	std::string result = triangle.str();
	return result;
}*/

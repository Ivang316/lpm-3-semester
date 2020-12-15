#define _USE_MATH_DEFINES
#include "Angle.h"
#include <cmath>

void Angle::formatMinutes() {
	while (minutes > 60) {
		minutes -= 60;
		degrees++;
	}
	while (minutes < 0) {
		minutes += 60;
		degrees--;
	}
}
void Angle::formatDegrees() {
	while (degrees > 360)
		degrees -= 360;
	while (degrees < 0)
		degrees += 360;
}
void Angle::formatAngle() {
	formatMinutes();
	formatDegrees();
}

/*Angle::Angle() {
	degrees = 0; minutes = 0;
}
Angle::Angle(double deg, double min) : degrees(deg), minutes(min) {
	formatAngle();
}*/

void Angle::setDeg(double deg) {
	degrees = deg;
	formatDegrees();
}
void Angle::setMin(double min) {
	minutes = min;
	formatMinutes();
}

double Angle::getDegrees() {
	return degrees;
}
double Angle::getMinutes() {
	return minutes;
}
double Angle::toDegrees() {
	return degrees + minutes / 60.0;
}
double Angle::toRadians() {
	return toDegrees() * M_PI / 180;
}

void Angle::increaseDegrees(double val) {
	degrees += val;
	formatDegrees();
}
void Angle::increaseMinutes(double val) {
	minutes += val;
	formatMinutes();
}
void Angle::decreaseDegrees(double val) {
	degrees -= val;
	formatDegrees();
}
void Angle::decreaseMinutes(double val) {
	minutes -= val;
	formatMinutes();
}

double Angle::getSin() {
	return std::sin(toRadians());
}

/*bool angleComparisons(Angle& a, Angle& b) {
	int first = a.getMinutes() + a.getDegrees() * 60;
	int second = b.getMinutes() + b.getDegrees() * 60;
	if (first < second) return -1;
	else if (first > second) return 1;
	else return 0;
}*/

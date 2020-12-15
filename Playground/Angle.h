#pragma once

class Angle {
	double degrees, minutes;
	void formatMinutes();
	void formatDegrees();
	void formatAngle();
public:
	Angle() : degrees(0), minutes(0) {};
	Angle(double deg, double min) : degrees(deg), minutes(min) {};
	void setDeg(double deg);
	void setMin(double min);
	double getDegrees();
	double getMinutes();
	double toDegrees();
	double toRadians();
	void increaseDegrees(double val);
	void increaseMinutes(double val);
	void decreaseDegrees(double val);
	void decreaseMinutes(double val);
	double getSin();
};

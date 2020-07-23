#pragma once
#include <utility>

class Rotator
{
public:
	Rotator();
	void rotateClockWise(std::pair<double, double>&, double&);
	void rotateAntiClockWise(std::pair<double, double>&, double&);
	~Rotator();
private:
	std::pair<double, double> point;

	double myCos(double&);
	double mySin(double&);
};


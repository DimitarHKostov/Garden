#include "pch.h"
#include "Rotator.h"
#include <iostream>

#define PI 3.141592653

Rotator::Rotator()
{
}

void Rotator::rotateAntiClockWise(std::pair<double, double>& point, double& angle) {
	double x = point.first;
	double y = point.second;

	double newX = x * myCos(angle) + y * mySin(angle);
	double newY = -x * mySin(angle) + y * myCos(angle);
	point.first = newX;
	point.second = newY;
}

void Rotator::rotateClockWise(std::pair<double, double>& point, double& angle) {
	double x = point.first;
	double y = point.second;

	double newX = x * myCos(angle) - y * mySin(angle);
	double newY = x * mySin(angle) + y * myCos(angle);
	point.first = newX;
	point.second = newY;
}

double Rotator::mySin(double& angle) {
	return sin((angle * PI / 180));
}

double Rotator::myCos(double& angle) {
	return cos((angle * PI / 180));
}

Rotator::~Rotator()
{
}

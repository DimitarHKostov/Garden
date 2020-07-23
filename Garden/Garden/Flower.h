#pragma once
#include <utility>

class Flower
{
public:
	virtual const std::pair<double, double>& getCenterCoordinates()=0;
	virtual const double& getArea()=0;
	virtual const char& getType()=0;
};
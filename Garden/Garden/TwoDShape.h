#pragma once
#include "Flower.h"

class TwoDShape: public Flower
{
public:
	void setCenterCoordinates(const std::pair<double, double>&);
	virtual void setArea(const double&)=0;
	void setType(const char&);

	const std::pair<double, double>& getCenterCoordinates();
	const double& getArea();
	const char& getType();
protected:
	std::pair<double, double> centerCoordinates;
	double area;
	char type;
};


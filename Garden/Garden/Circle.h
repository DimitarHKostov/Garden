#pragma once
#include "TwoDShape.h"
#include <math.h>

class Circle: public TwoDShape
{
public:
	Circle(const double&);
	const double& getRadius();
	void setArea(const double&) override;
private:
	double radius;
};


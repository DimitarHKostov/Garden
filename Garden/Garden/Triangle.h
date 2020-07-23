#pragma once
#include "TwoDShape.h"

class Triangle: public TwoDShape
{
public:
	Triangle(const double&);
	const double& getSide();
	void setArea(const double&) override;
private:
	double side;
};


#pragma once
#include "TwoDShape.h"

class Ellipse: public TwoDShape
{
public:
	Ellipse(const double&);
	void setArea(const double&) override;
	const double& getRad() const;
	const double& getHalfRad() const;
private:
	double radius;
	double halfRadius;
};


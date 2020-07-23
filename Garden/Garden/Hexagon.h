#pragma once
#include "TwoDShape.h"

class Hexagon: public TwoDShape
{
public:
	Hexagon(const double&);
	void setArea(const double&) override;
	const double& getSide() const;
private:
	double side;
};


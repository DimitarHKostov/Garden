#include "pch.h"
#include "TwoDShape.h"

void TwoDShape::setCenterCoordinates(const std::pair<double, double>& coordinates) {
	this->centerCoordinates = coordinates;
}

void TwoDShape::setType(const char& type) {
	this->type = type;
}

const std::pair<double, double>& TwoDShape::getCenterCoordinates()
{
	return this->centerCoordinates;
}

const double& TwoDShape::getArea()
{
	return this->area;
}

const char& TwoDShape::getType()
{
	return this->type;
}
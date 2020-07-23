#include "pch.h"
#include "Ellipse.h"

#define PI 3.141592653

Ellipse::Ellipse(const double& rad)
{
	this->radius = rad;
	this->halfRadius = rad/2;
	this->setArea(rad);
}

void Ellipse::setArea(const double& side) {
	this->area = side * (side/2) * PI;
}

const double& Ellipse::getRad() const{
	return this->radius;
}

const double& Ellipse::getHalfRad() const{
	return this->halfRadius;
}
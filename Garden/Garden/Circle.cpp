#include "pch.h"
#include "Circle.h"

#define PI 3.141592653

Circle::Circle(const double& side){
	this->setType('c');
	this->radius = side;
	this->setArea(side);
}

void Circle::setArea(const double& side) {
	this->area = PI * side * side;
}

const double& Circle::getRadius() {
	return this->radius;
}
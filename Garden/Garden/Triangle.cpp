#include "pch.h"
#include "Triangle.h"

#define approximationOfSqrtThree 1.732050

Triangle::Triangle(const double& side){
	this->side = side;
	this->setArea(side);
}

const double& Triangle::getSide() {
	return this->side;
}

void Triangle::setArea(const double& side) {
	this->area = (side * side)*(approximationOfSqrtThree / 4);
}

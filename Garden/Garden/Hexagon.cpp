#include "pch.h"
#include "Hexagon.h"

#define approximationOfSqrtThree 1.732050

Hexagon::Hexagon(const double& side){
	this->side = side;
	this->setArea(side);
}

void Hexagon::setArea(const double& side) {
	this->area = ((3 * approximationOfSqrtThree) / 2) * (side*side);
}

const double& Hexagon::getSide() const {
	return this->side;
}
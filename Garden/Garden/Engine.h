#pragma once
#include "CoordinateSystem.h"
#include "Calculator.h"
#include "Flower.h"

class Engine
{
public:
	Engine();
	void start();
private:
	void fillGarden();
	void output();
	double rows;
	double cols;
	double angle;
	char type;
	double side;
	CoordinateSystem garden;
	Calculator calc;
	std::vector<Flower*> flowers;
	Rotator rotator;
};
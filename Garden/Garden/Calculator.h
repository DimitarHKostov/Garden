#pragma once
#include <vector>
#include <utility>
#include "Flower.h"
#include "Rotator.h"

//doing this to make it more readable
#define Vector std::vector<std::pair<double, double>>
#define Pair std::pair<double, double>

class Calculator
{
public:
	Calculator();
	Flower* createObject(double&, char&, Pair, double&, double&, double&, Vector&);
private:
	bool first;
	double height;
	double side;
	char type;
	Flower* coordinate(Pair&, double&, double&, double&, Vector&);
	Flower* circleCalc(Pair&, double&, double&, double&, Vector&);
	Flower* triangleCalc(Pair&, double&, double&, double&, Vector&);
	Flower* ellipseCalc(Pair&, double&, double&, double&, Vector&);
	Flower* hexagonCalc(Pair&, double&, double&, double&, Vector&);

	Flower* placeAnotherObject(Pair&, double&, double&, double&, Vector&, char);

	Rotator rotator;
};


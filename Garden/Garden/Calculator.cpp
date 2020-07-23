#include "pch.h"
#include "Calculator.h"
#include "Flower.h"
#include "Circle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Hexagon.h"
#include <iostream>
#include <math.h>
#include "vector"

#define approximationOfSqrtThree 1.732050

Calculator::Calculator(){
	first = true;
	this->height = 0;
}

Flower* Calculator::createObject(double& side, char& type, Pair center, double& rows, double& cols, double& angle, Vector& points) {
	this->side = side;
	this->type = type;
	return this->coordinate(center, rows, cols, angle, points);
}

Flower* Calculator::coordinate(Pair& center, double& rows, double& cols, double& angle, Vector& points) {
	//0. the logic for the following stays the same: 
	//1. while possible: put object right to the last one
	//2. then go up if possible
	//3. goto 1.
	//-- 'c'-circle, 'h'-hexagon, 't'-triangle, 'e'-ellipse
	switch (this->type) {
		case 'c': return this->circleCalc(center, rows, cols, angle, points);
		case 'h': return this->hexagonCalc(center, rows, cols, angle, points);
		case 't': return this->triangleCalc(center, rows, cols, angle, points);
		case 'e': return this->ellipseCalc(center, rows, cols, angle, points);
	}
	return nullptr;
}

Flower* Calculator::circleCalc(Pair& center, double& rows, double& cols, double& angle, Vector& points) {
	if (this->first) {
		Circle* circle = new Circle(this->side);
		double radius = circle->getRadius();
		if (radius > rows / 2 || radius > cols / 2) {
			return nullptr;
		}
		this->first = false;
		this->height = radius;
		Pair c(radius, radius);
		this->rotator.rotateAntiClockWise(c, angle);
		circle->setCenterCoordinates(c);
		return circle;
	}
	return this->placeAnotherObject(center, rows, cols, angle, points, 'c');
}

Flower* Calculator::triangleCalc(Pair& center, double& rows, double& cols, double& angle, Vector& points) {
	if (this->first) {
		this->first = false;
		Triangle* triangle = new Triangle(this->side);
		double side = triangle->getSide();
		double scale = this->side / approximationOfSqrtThree;
		//(2 * scale) represents radius
		if (this->side > rows && this->side > cols) {
			return nullptr;
		}
		this->height = 2 * scale;
		points.push_back(Pair(-side / 2, -scale));
		points.push_back(Pair(side / 2, -scale));
		points.push_back(Pair(0, 2 * scale));
		Pair c(2 * scale, 2 * scale);
		for (Pair& point : points) {
			this->rotator.rotateClockWise(point, angle);
			point.first += (2 * scale);
			point.second += (2 * scale);
			this->rotator.rotateAntiClockWise(point, angle);
		}
		this->rotator.rotateAntiClockWise(c, angle);
		triangle->setCenterCoordinates(c);
		return triangle;
	}
	return this->placeAnotherObject(center, rows, cols, angle, points, 't');
}

Flower* Calculator::hexagonCalc(Pair& center, double& rows, double& cols, double& angle, Vector& points) {
	if (this->first) {
		this->first = false;
		Hexagon* hexagon = new Hexagon(this->side);
		double side = hexagon->getSide();
		double scale = sqrt(pow(side, 2) - pow(side / 2, 2));
		//using side == R
		if (this->side > rows && this->side > cols) {
			return nullptr;
		}
		Pair c(side, side);
		points.push_back(Pair(side, 0));
		points.push_back(Pair(-side, 0));
		points.push_back(Pair(-scale, scale));
		points.push_back(Pair(-scale, -scale));
		points.push_back(Pair(scale, scale));
		points.push_back(Pair(scale, -scale));
		this->height = side;
		for (Pair& point : points) {
			this->rotator.rotateClockWise(point, angle);
			point.first += side;
			point.second += side;
			this->rotator.rotateAntiClockWise(point, angle);
		}
		this->rotator.rotateAntiClockWise(c, angle);
		hexagon->setCenterCoordinates(c);
		return hexagon;
	}
	return this->placeAnotherObject(center, rows, cols, angle, points, 'h');
}

Flower* Calculator::ellipseCalc(Pair& center, double& rows, double& cols, double& angle, Vector& points) {
	if (this->first) {
		this->first = false;
		Ellipse* ellipse = new Ellipse(side);
		double rad = ellipse->getRad();
		double halfRad = ellipse->getHalfRad();

		if (rad > rows / 2 || rad > cols / 2) {
			return nullptr;
		}
		Pair c(rad, rad);
		points.push_back(Pair(0, rad));
		points.push_back(Pair(0, -rad));
		points.push_back(Pair(0, halfRad));
		points.push_back(Pair(0, -halfRad));
		this->height = rad;
		for (Pair& point : points) {
			this->rotator.rotateClockWise(point, angle);
			point.first += rad;
			point.second += rad;
			this->rotator.rotateAntiClockWise(point, angle);
		}
		this->rotator.rotateAntiClockWise(c, angle);
		ellipse->setCenterCoordinates(c);
		return ellipse;
	}
	return this->placeAnotherObject(center, rows, cols, angle, points, 'e');
}

Flower* Calculator::placeAnotherObject(Pair& center, double& rows, double& cols, double& angle, Vector& points, char type) {
	if (type == 'c') {
		Circle* circle = new Circle(this->side);
		double radius = circle->getRadius();
		if (center.first + 2 * radius < cols) {
			Pair c(center.first + 2 * radius, height);
			this->rotator.rotateAntiClockWise(c, angle);
			circle->setCenterCoordinates(c);
			return circle;
		}

		if (center.second + 2 * radius < rows) {
			this->height = center.second + 2 * radius;
			Pair c(radius, height);
			this->rotator.rotateAntiClockWise(c, angle);
			circle->setCenterCoordinates(c);
			return circle;
		}
		return nullptr;
	}
	else if (type == 't') {
		Triangle* triangle = new Triangle(side);
		double scale = this->side / approximationOfSqrtThree;
		if (center.first + 4 * scale < cols) {
			Pair c(center.first + 4 * scale, height);
			this->rotator.rotateAntiClockWise(c, angle);
			triangle->setCenterCoordinates(c);
			for (Pair& point : points) {
				this->rotator.rotateAntiClockWise(point, angle);
			}
			return triangle;
		}

		if (center.second + 4 * scale < rows) {
			this->height = center.second + 4 * scale;
			Pair c(2 * scale, height);
			this->rotator.rotateAntiClockWise(c, angle);
			triangle->setCenterCoordinates(c);
			for (Pair& point : points) {
				this->rotator.rotateAntiClockWise(point, angle);
			}
			return triangle;
		}
		return nullptr;
	}
	else if (type == 'e') {
		Ellipse* ellipse = new Ellipse(side);
		double rad = ellipse->getRad();
		double halfRad = ellipse->getHalfRad();
		if (center.first + 2 * rad < cols) {
			Pair c(center.first + 2 * rad, height);
			this->rotator.rotateAntiClockWise(c, angle);
			ellipse->setCenterCoordinates(c);
			return ellipse;
		}

		if (center.second + 2 * rad < rows) {
			this->height = center.second + 2 * rad;
			Pair c(rad, height);
			this->rotator.rotateAntiClockWise(c, angle);
			ellipse->setCenterCoordinates(c);
			return ellipse;
		}
		return nullptr;
	}
	else if (type == 'h') {
		Hexagon* hexagon = new Hexagon(side);
		if (center.first + 2 * side < cols) {
			Pair c(center.first + 2 * side, height);
			this->rotator.rotateAntiClockWise(c, angle);
			hexagon->setCenterCoordinates(c);
			for (Pair& point : points) {
				this->rotator.rotateAntiClockWise(point, angle);
			}
			return hexagon;
		}

		if (center.second + 2 * side < rows) {
			this->height = center.second + 2 * side;
			Pair c(side, height);
			this->rotator.rotateAntiClockWise(c, angle);
			hexagon->setCenterCoordinates(c);
			for (Pair& point : points) {
				this->rotator.rotateAntiClockWise(point, angle);
			}
			return hexagon;
		}
		return nullptr;
	}
	return nullptr;
}
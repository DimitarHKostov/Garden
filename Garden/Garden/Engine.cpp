#include "pch.h"
#include "Engine.h"
#include <iostream>

//makes the code more readable
#define Vector std::vector<std::pair<double, double>>
#define Pair std::pair<double, double>

Engine::Engine() {
	this->rows = 0;
	this->cols = 0;
	this->type = 'n';
	this->side = 0;
}

void Engine::start() {
	std::cout << "Enter rows and cols:" << std::endl;
	std::cin >> rows >> cols;
	std::cout << "Enter angle of rotation in 2D: " << std::endl;
	std::cin >> angle;
	std::cout << "Enter type of flowers: " << std::endl;
	std::cin >> type;
	std::cout << "Enter the side: " << std::endl;
	std::cin >> side;
	this->garden.setCoordinates(rows, cols);
	this->fillGarden();
	this->output();
}

void Engine::fillGarden() {
	//same idea for all the figures
	//since they are all regular polygons, the can be surrounded by a circle
	//so if i always keep track of the radius to that circle, i can find one possible solution for the problem
	
	Vector sidePoints;
	Flower* currentFlower = this->calc.createObject(this->side, this->type, Pair(0, 0), this->rows, this->cols, this->angle, sidePoints);
	if (currentFlower != nullptr) {
		this->flowers.push_back(currentFlower);
		if (sidePoints.size() > 0) {
			this->garden.addDescribingPoints(sidePoints);
		}
		currentFlower = nullptr;
	}
	
	if (flowers.size() > 0) {
		Pair center = Pair(flowers[0]->getCenterCoordinates().first, flowers[0]->getCenterCoordinates().second);
		this->garden.addCenterPoint(center);
		this->rotator.rotateClockWise(center, this->angle);
		double x = center.first;
		double y = center.second;
		
		double dist = x;
		int i = 1;

		while (x + 2 * dist <= cols || y + 2 * dist <= rows) {
			currentFlower = this->calc.createObject(this->side, this->type, Pair(x, y), this->rows, this->cols, this->angle, sidePoints);
			if (currentFlower == nullptr) {
				break;
			}
			this->flowers.push_back(currentFlower);
			center = Pair(flowers[i]->getCenterCoordinates().first, flowers[i]->getCenterCoordinates().second);
			this->rotator.rotateClockWise(center, this->angle);
			if (sidePoints.size() > 0) {
				this->garden.addDescribingPoints(sidePoints);
				for (Pair& p : sidePoints) {
					this->rotator.rotateClockWise(p, this->angle);
				}
			}
			this->garden.addCenterPoint(center);
			x = center.first;
			y = center.second;
			i++;
			currentFlower = nullptr;
		}
	}
}

void Engine::output() {
	if (flowers.size() > 0) {
		std::cout << "Number of flowers: " << this->flowers.size() << std::endl;
		for (int i = 0; i < flowers.size(); i++) {
			double x = flowers[i]->getCenterCoordinates().first;
			double y = flowers[i]->getCenterCoordinates().second;
			std::cout << "Flower " << i + 1 << " has coordinates: ";
			std::cout << "(" << x << "," << y << ")" << std::endl;
		}
		double oneFlowerArea = this->flowers[0]->getArea();
		double gardenArea = this->rows*this->cols;
		int numberOfFlowers = this->flowers.size();
		std::cout << ((100 * oneFlowerArea) / gardenArea)*numberOfFlowers;
		std::cout << "% of the area is covered" << std::endl;
	}
	else {
		std::cout << "Number of flowers: 0"<< std::endl;
		std::cout << "0% of the area is covered" << std::endl;
	}
}
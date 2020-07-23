#include "pch.h"
#include "CoordinateSystem.h"

CoordinateSystem::CoordinateSystem()
{
	this->matrix = nullptr;
}

void CoordinateSystem::setCoordinates(const double _rows, const double _cols) {
	this->rows = _rows;
	this->cols = _cols;
	this->matrix = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new double[rows];
	}
}

void CoordinateSystem::addCenterPoint(const std::pair<double, double>& point) {
	this->centerPoints.push_back(point);
}

const std::vector<std::pair<double, double>>& CoordinateSystem::getCenterPoints() {
	return this->centerPoints;
}

void CoordinateSystem::addDescribingPoints(const std::vector<std::pair<double, double>>& set) {
	//i-th figure has vector of points
	this->describingPoints.push_back(set);
}

const std::vector<std::vector<std::pair<double, double>>>& CoordinateSystem::getDescribingPoints() {
	return this->describingPoints;
}

CoordinateSystem::~CoordinateSystem() {
	for (int i = 0; i < rows; ++i) {
		delete[] this->matrix[i];
	}
	delete[] matrix;
}
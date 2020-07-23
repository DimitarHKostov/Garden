#pragma once
#include <vector>

class CoordinateSystem
{
public:
	CoordinateSystem();
	void setCoordinates(const double, const double);
	void addCenterPoint(const std::pair<double, double>&);
	void addDescribingPoints(const std::vector<std::pair<double, double>>&);
	const std::vector<std::pair<double, double>>& getCenterPoints();
	const std::vector<std::vector<std::pair<double, double>>>& getDescribingPoints();
	~CoordinateSystem();
private:
	double rows;
	double cols;
	double** matrix;
	std::vector<std::pair<double, double>> centerPoints;
	std::vector<std::vector<std::pair<double, double>>> describingPoints;
};


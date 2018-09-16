#pragma once
#include "Shape.hpp"
//#include "TriangularPrism.h"

class TriangularPrism : public Shape
{
private:
	double depth;
	double a_length;
	double b_length;
	//theta is in degrees
	double theta;
public:

	TriangularPrism();
	TriangularPrism(double x, double y, double z, double depth, double a_length, double b_length, double theta);
	TriangularPrism(double x, double y, double z, double depth, double a_length, double b_length, double theta, double rotation);

	void draw();
};
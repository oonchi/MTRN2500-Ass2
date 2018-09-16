#pragma once
#include "Shape.hpp"

class TrapezoidalPrism : public Shape
{
private:
	double depth;
	double a_length;
	double b_length;
	double height;
	//theta is in degrees, it is the angle subtended by a_length and the side on the negative x-axis
	double theta;
public:

	TrapezoidalPrism();
	TrapezoidalPrism(double x, double y, double z, double depth, double a_length, double b_length, double height, double theta);
	TrapezoidalPrism(double x, double y, double z, double depth, double a_length, double b_length, double height, double theta, double rotation);

	void draw();
};
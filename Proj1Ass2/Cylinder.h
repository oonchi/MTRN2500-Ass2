#include "Shape.hpp"

class Cylinder : public Shape
{
private:
	double radius;
	double height;
public:

	Cylinder();
	Cylinder(double x, double y, double z, double radius, double height);
	Cylinder(double x, double y, double z, double radius, double height, double rotation);

	void draw();
};
